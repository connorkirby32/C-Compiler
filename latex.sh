#!/bin/bash


make

./a.out testFile.c -d[lps] -a

latex astInfo.tex
xdvi astInfo.dvi

