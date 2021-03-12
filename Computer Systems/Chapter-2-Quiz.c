#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int x;
x = ((1u << 31) - 1);

int printf(("%i", x));

