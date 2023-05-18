#include <tsh.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <cstring>
#include <ctime>

using namespace std;

void simple_shell::parse_command(char* cmd, char** cmdTokens) {
    // TODO: tokenize the command string into arguments
    char* pch; //pointer to char
    pch = strtok(cmd, " \n"); //stores first token in pch
    int counter = 0;
    while (pch != NULL){ //tokenize cmd
        if (counter == 24){
            break;
        }
        cmdTokens[counter] = strdup(pch);
        pch = strtok(NULL, " \n");
        counter++;
    }
    cmdTokens[counter] = NULL;
    return;
}

void simple_shell::exec_command(char** argv) {
    // TODO: fork a child process to execute the command.
    string command = argv[0];
    if (aliases.find(command) != aliases.end()) {
        //replace the command with the corresponding alias value
        command = aliases[command];
    }

    int pid = fork(); 
    if (pid < 0) { //failure
        exit(EXIT_FAILURE);
    } else if (pid == 0) { //child
        //check if the command contains a pipe character "|"
        //fyi: left side command is anything before the pipe, right is anything after
        int i = 0;
        while (argv[i] != NULL) {
            if (strcmp(argv[i], "|") == 0) {
                //found a pipe, execute the commands on both sides of the pipe
                argv[i] = NULL;  //terminate the left side command
                char** argv2 = &argv[i + 1];  //arguments for the right side command
                int pipefd[2];
                if (pipe(pipefd) == -1) {
                    cerr << "Failed to create pipe" << endl;
                    exit(EXIT_FAILURE);
                }
                int pid2 = fork();
                if (pid2 < 0) {
                    cerr << "Failed to fork" << endl;
                    exit(EXIT_FAILURE);
                } else if (pid2 == 0) {
                    //child process for the right side command
                    close(pipefd[1]);  //close the write end of the pipe
                    dup2(pipefd[0], STDIN_FILENO);  //redirect stdin to the read end of the pipe
                    close(pipefd[0]);  //close the read end of the pipe
                    exit(execvp(argv2[0], argv2));
                } else {
                    //parent process for the left side command
                    close(pipefd[0]);  //close the read end of the pipe
                    dup2(pipefd[1], STDOUT_FILENO);  //redirect stdout to the write end of the pipe
                    close(pipefd[1]);  //close the write end of the pipe
                    exit(execvp(command.c_str(), argv));
                }
            }
            i++;
        }
        //no pipe found, execute the command normally
        exit(execvp(command.c_str(), argv));
    } else { // Parent pid > 0
        //parent process waits for the child process to complete 
        int status = 0;
        wait(&status);
    }
}

bool simple_shell::isQuit(char* cmd) {
    // TODO: check for the command "quit" that terminates the shell
    if (cmd[0] == 'q' && cmd[1] == 'u' && cmd[2] == 'i' && cmd[3] == 't'){
        return true;
    }
    return false;
}

void simple_shell::display_help() {
    cout << "Welcome to Miranda Zhang's Primitive Shell (tsh)!" << endl;
    cout << "------------------------------------" << endl;
    cout << "Here are the available commands:" << endl;
    cout << "help: Display this help message" << endl;
    cout << "quit: Terminate the shell" << endl;
    cout << "cd <directory_name>: Changes directory as per UNIX specifications";
    cout << "<command>: Execute the specified command" << endl;
    cout << "<command1> | <command2>: Pipe the output of command1 as the input to command2" << endl;
    cout << "alias <command_nickname> = <command_name>: Nicknames a command";
}

void simple_shell::change_directory(char** argv) {
    static char* prevDir = nullptr; //store previous directory
    
    if (argv[1] == nullptr) { //only cd given
        //no directory argument provided, go to the previous directory
        if (prevDir == nullptr) {
            cout << "No previous directory available" << endl;
        } else {
            if (chdir(prevDir) == -1) {
                cout << "Failed to change directory to the previous directory" << endl;
            }
        }
    } else if (argv[2] == nullptr) { //cd and a directory given
        //one directory argument provided, change to the specified directory
        char* cwd = getcwd(nullptr, 0); //gets current working directory, stores in cwd variable
        if (cwd == nullptr) {
            cout << "Failed to retrieve current working directory" << endl;
            return;
        }

        if (prevDir != nullptr) {
            free(prevDir); //free previously allocated memory
        }
        prevDir = cwd;
        
        if (chdir(argv[1]) == -1) {
            cout << "Failed to change directory" << endl;
        }
    } else {
        cout << "Usage: cd [directory]" << endl;
    }
}


void simple_shell::alias_command(char** argv) {
    if (argv[1] == nullptr || strcmp(argv[1], "-p") == 0) { 
        //no arguments provided or only -p option, print the list of aliases
        for (const auto& alias : aliases) {
            cout << alias.first << "='" << alias.second << "'" << endl;
        }
    } else {
        //arguments provided, define alias for each name value pair
        int i = 1;
        while (argv[i] != nullptr) {
            string arg = argv[i];
            size_t equalPos = arg.find('=');
            if (equalPos != string::npos) {
                string alias = arg.substr(0, equalPos);
                string value = arg.substr(equalPos + 1);
                aliases[alias] = value;
            } else {
                //no value provided, print the name and value of the alias
                if (aliases.find(arg) != aliases.end()) {
                    cout << arg << "='" << aliases[arg] << "'" << endl;
                } else {
                    cout << "Alias not found: " << arg << endl;
                }
            }
            i++;
        }
    }
}


void simple_shell::celebrate(){
    //array of statements
    string statements[] = {
        "╰(● ⋏ ●)╯╰(● ⋏ ●)╯ <\"we love tim!!!\"> ╰(● ⋏ ●)╯╰(● ⋏ ●)╯",
        "( ๑‾̀◡‾́)๑ *fist bump, we made it through spring semeste.r* ٩(｡•́‿•̀｡)",
        "(≧▽≦) <classmates, good luck in your future endeavors!>", 
        "(￣个￣) <thank you tim, thank you TAs, we are much wiser now.>",
        "｡ﾟ( ﾟஇ‸இﾟ)ﾟ｡ <we will miss you seniors! congrats!> ｡ﾟ(இ‸இﾟ )ﾟ｡"
    };

    //random seed
    srand(std::time(0));

    //randomize and print
    int index = std::rand() % 5;
    cout << endl;
    cout << statements[index] << std::endl;
    cout << endl;
}