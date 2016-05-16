#!/bin/bash


make

./a.out testFile.c -d[lps] -a

latex astInfo.lex
xdvi astInfo.dvi