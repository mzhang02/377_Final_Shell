# 377_Final_Shell

## Where is the code?
  The code is in the master branch, not the main branch.

## Overview
  The project is an extension of the P2: Shell project from Spring 2023 semester. It is a trivial shell, made by Miranda Zhang, for the CS377 final project.

## Demo
  The link to the demo is here: https://youtu.be/PLr8uByotac

## Header Files
  Here are the header files used: <br>
  #include tsh.h <br>
  #include iostream <br>
  #include stdio.h <br>
  #include string.h <br>
  #include stdlib.h <br>
  #include map <br>
  #include cstring <br>
  #include ctime <br>

## Files
  I have edited the following files:<br>
  main_tsh.cpp <br>
  tsh.cpp <br>
  tsh.h <br>
  
## Starting the Trivial Shell
  To start the trivial shell, go into the terminal and type <./tsh_app>. It will start the tsh shell and give some information on what commands are supported. Go ahead and try those commands!
  
## Commands Supported
  1. General UNIX Commands:
    The General UNIX commands are supported, (i.e. ls, mkdir). They are forked and dependind on if it fails, succeeds (child), or is a parent (child). If it is a child, it determines if a pipe exists, and if the commands are on the left or right of the pipe. It writes and reads the process depending on if it is the left or right command. 
  2. help:
    "help" displays a help message with all possible commands. There is a brief explanation and example of all commands.
  3. quit:
    "quit" terminates the shell. It recognizes if the user has typed the four characters q, u, i, t and if so, terminates.
  4. cd directory_name:
  "cd directory_name" changes directory as per UNIX specifications. You can cd into a directory or cd out of a directory. The code checks if the second or third argument is a nullptr, and it will cd out if the second argument is a nullptr, and cd into the given directory if the third argument is a nullptr. Otherwise, it errors out. 
  5. command1 | command2:
  "command1 | command2" pipes the output of command1 as the input to command2.
  6. alias [-p] command_nickname = command_name: 
  alias command_nickname = command_name nicknames a command. It is a BASH builtin command that I implemented. It uses the '=' character to tokenize the two names. It uses a map to store the nickname and name pairs, and exec_command calls it and also executes the nicknamed commands.
  7. celebrate:
    "celebrate" prints out a random motivating message with emoticons! Congrats on finishing this semester. 

## Design Choices
I tried to keep all the methods for the commands in the tsh.cpp and the main function as clean as possible. For the method alias_command, it requires a privately declared map because it is a variable that is populated by the alias_command and utilized by the exec_command. The rest of the methods are all public. I also tried to print as many helpful error messages so it would be as user friendly as possible.

## Resources
The emoticons are from this website: https://www.emoticonstext.com/
