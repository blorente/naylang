//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

// Tis is the grammar of the commands accepted by the command-line frontend
grammar ConsoleFrontendCommands;

command : execute code      #ExecCommand
        | print code        #PrintCommand
        | run code          #RunCommand
        | load filename     #LoadCommand
        ;

execute: 'exec ' | 'e ';
print: 'print ' | 'p ';
run: 'run ' | 'r ';
load: 'load ' | 'l ';

code : STRING;
filename: STRING;

STRING: .+;

