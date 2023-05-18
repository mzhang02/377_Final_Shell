#include <tsh.h>

using namespace std;

int main() {
  char cmd[81];
  char *cmdTokens[25];
  simple_shell *shell = new simple_shell();
  cout << "Welcome to Miranda Zhang's Shell (tsh)!" << endl;
  cout << "Here is a list of the commands supported:"<< endl;
  cout << "--General UNIX shell commands"<< endl;
  cout << "--Piping commands, using \"|\""<< endl;
  cout << "--Redirection commands, using \"cd\"" << endl;
  cout << "--Alias changing, using \"alias\"" << endl;
  cout << "--Celebrate! Type celebrate for fun ascii art" << endl;
  cout << "For more information, type \"help\" into the shell for the help table." << endl;
  cout << "tsh> ";
  while (fgets(cmd, sizeof(cmd), stdin)) {
    if (cmd[0] != '\n') {
      shell->parse_command(cmd, cmdTokens);
      if (shell->isQuit(*cmdTokens)) {
        exit(0);
      } else if (strcmp(cmdTokens[0], "help") == 0) {
        shell->display_help();
      } else if (strcmp(cmdTokens[0], "cd") == 0) {
        shell->change_directory(cmdTokens);
      } else if (strcmp(cmdTokens[0], "alias") == 0) {
          shell->alias_command(cmdTokens);
      } else if (strcmp(cmdTokens[0], "celebrate") == 0) {
          shell->celebrate();
      } else {
        shell->exec_command(cmdTokens);
      }
    }
    cout << "tsh> ";
  }
  cout << endl;
  exit(0);
}