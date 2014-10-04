#include<time.h>
char cQuestion[][64] = {
    //simple move
    "move right" , 
    "move left" , 
    "move up" , 
    "move down" , 
    //some advanced tecnology to move between line or character
    "jump to first character where last change",
    "jump to the place of last change",
    "jump to the place when it's end in insert mode",
    "backward to start of a function",
    "forward to start of a function",
    "backward to end of a function",
    "forward to end of a function",
    "to begin of a block",
    "to end of a block",
    "to begin of a comment block",
    "to end of a comment block",
    //about regieter
    "open command history",
    "past register,like register +",
    "copy register context when we type cmd,like register a",
    //add , delete , move
    "add a new blank line below",
    "add a new blank line up",
    "delete all include brackets",
    //search command
    "search up the word below cursor",
    //some tip
    "move to defination of a variable",
    //abbreviation
    "abbreviation for all mode",
    "abbreviation for insert mode",
    "abbreviation for command line ",
    //map
    "which map command should you always use?",
    "which map is the saffest in nomal mode?",
    "which map is the saffest in visual mode?",
    "which map is the saffest in insert mode?",
};

char cAnswer[][64] = {
    "l",
    "h",
    "k",
    "j",
    "'[",
    "'.",
    "'^",
    "[[",
    "]]",
    "[]",
    "][",
    "[{",
    "]}",
    "[/",
    "]/",
    "q:",
    "\"+",
    "c-ra",
    "o",
    "O",
    "da(",
    "#",
    "gd",
    "abbrev",
    "iabbrev",
    "cabbrev",
    "noremap",
    "nnoremap",
    "vnoremap",
    "inoremap",
};

