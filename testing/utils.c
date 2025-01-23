// color codes
#define RED "\x1b[31m" // red
#define GREEN "\x1b[32m" // green
#define RESET "\x1b[0m" // reset to default color
#define BOLD "\x1b[1m" // bold
#define UL "\x1b[4m" // underline

#include <stdio.h>
#include <string.h>


void print_header(char *name)
{
    printf(UL BOLD "\n%s\n\t" RESET, name);
    printf(BOLD "libc\t\t" RESET);
    printf(BOLD "libasm\t" RESET);
    printf("\n");
}


void printf_color(char *color, char *str)
{
    if(strcmp(color, "green") == 0)
        printf("%s%s%s", GREEN, str, RESET);
    else if(strcmp(color, "red") == 0)
        printf("%s%s%s", RED, str, RESET);
    else
        printf("%s", str);
}