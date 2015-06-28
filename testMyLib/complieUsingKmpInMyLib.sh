gcc  -c usingKmpInMyLib.c -o usingKmpInMyLib.o
gcc usingKmpInMyLib.o ../myLib/string/kmp.o -o usingKmpInMyLib
