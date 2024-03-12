#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (int argc, char* argv []){
setlocale (LC_ALL, "Portuguese");
printf ("Ola, mundo! \n %s", argv[1]);



    exit(0);
}