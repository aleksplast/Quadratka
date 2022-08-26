#include <stdio.h>
#include <string.h>
#include "header.h"

void parser(char* arg, enum Colors color)
{
    if (strcmp(arg, "--color"))
        SetColor(color);
}
