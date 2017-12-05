#include "../src/crow.h"
#include <sys/wait.h>
#include <string>
#include <vector>

#define VERSION "v1.0"
#define DEFAULT_ROUTE "/api/"
#define CURRENT_ROUTE DEFAULT_ROUTE VERSION

using std::cout;
using std::endl;
using std::vector;
using std::string;


bool is_any_home(crow::json::rvalue urls) {
  char *cmd = "/usr/bin/ping";

  char *args[7] = {
                   cmd,
                   "-W", "1",
                   "-c", "1",
                   "",
                   (char*)0
  };

  vector<int> pids;

  for (auto s : urls) {
    args[5] = (char *)((std::string)s.s()).c_str();
    int pid = fork();

    if (pid == 0) {
      int fd = open("/dev/null", O_WRONLY);
      if (fd < 0) perror("open");
      dup2(fd, 1);
      dup2(fd, 2);
      execv(cmd, args);
    } else {
      pids.push_back(pid);
    }
  }

  // In thi parent
  for (int i = 0; i < urls.size(); i++) {
    int pid = pids[i];
    int status;
    waitpid(pid, &status, 0);
    if (status == 0)
      return true;
  }

  return false;
}
  
int main(int argc, char **argv)
{
    crow::SimpleApp app;

    CROW_ROUTE(app, CURRENT_ROUTE "/recent/")
      ([](const crow::request& req){
        auto request_json = crow::json::load(req.body);
        if (!request_json)
          return crow::response(400);

        crow::json::wvalue return_json;

        for (auto element : request_json) {
          return_json[element.key()] = is_any_home(element);
        }
        
        return crow::response(return_json);
    });

    app.port(1337).multithreaded().run();
}
