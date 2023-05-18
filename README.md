# 377_Final_Shell

## Header Files
  Here are the header files used:
  #include <tsh.h>
  #include <iostream>
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <map>
  #include <cstring>
  #include <ctime>

## Files
  I have edited the following files:
  main_tsh.cpp
  tsh.cpp
  tsh.h
  
##Starting the Trivial Shell
  To start the trivial shell, go into the terminal and type <./tsh_app>. It will start the tsh shell and give some information on what commands are supported. Go ahead and try those commands!
  
## Commands Supported
  ### 1. General UNIX Commands
    The General UNIX commands are supported, (i.e. ls, mkdir). 
  ### 2. help
    "help" displays a help message with all possible commands.
  ### 3. quit
    "quit" terminates the shell.
  ### 4. cd <directory_name>
  cd <directory_name>: Changes directory as per UNIX specifications
  
      cout << "Here are the available commands:" << endl;
    cout << "help: Display this help message" << endl;
    cout << "quit: Terminate the shell" << endl;
    cout << "cd <directory_name>: Changes directory as per UNIX specifications";
    cout << "<command>: Execute the specified command" << endl;
    cout << "<command1> | <command2>: Pipe the output of command1 as the input to command2" << endl;
    cout << "alias <command_nickname> = <command_name>: Nicknames a command";
  
