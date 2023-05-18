# 377_Final_Shell

## Where is the code?
  The code is in the master branch, not the main branch.

## Overview
  The project is an extension of the P2: Shell project from Spring 2023 semester. It is a trivial shell, made by Miranda Zhang, for the CS377 final project.

## Demo
  The link to the demo is here:

## Header Files
  Here are the header files used:
  #include <tsh.h> <br>
  #include <iostream> <br>
  #include <stdio.h> <br>
  #include <string.h> <br>
  #include <stdlib.h> <br>
  #include <map> <br>
  #include <cstring> <br>
  #include <ctime> <br>

## Files
  I have edited the following files:
  main_tsh.cpp <br>
  tsh.cpp <br>
  tsh.h <br>
  
## Starting the Trivial Shell
  To start the trivial shell, go into the terminal and type <./tsh_app>. It will start the tsh shell and give some information on what commands are supported. Go ahead and try those commands!
  
## Commands Supported
  ### 1. General UNIX Commands
    The General UNIX commands are supported, (i.e. ls, mkdir). 
  ### 2. help
    "help" displays a help message with all possible commands.
  ### 3. quit
    "quit" terminates the shell.
  ### 4. cd <directory_name>
  cd <directory_name> changes directory as per UNIX specifications.
  ### 5. <command1> | <command2>
  <command1> | <command2 pipes the output of command1 as the input to command2.
  ### 6. alias <command_nickname> = <command_name>
  alias <command_nickname> = <command_name> nicknames a command.
  ### 7. celebrate
    "celebrate" prints out a random motivating message with emoticons!
s
## Design Choices
    I tried to keep all the methods for the commands in the tsh.cpp and the main function as clean as possible. For the method alias_command, it requires a privately declared map because it is a variable that is populated by the alias_command and utilized by the exec_command. 

  
