#include <stdio.h>
#include <stdlib.h>

int main() {
    for (int i = 0; i < 256; i++)printf("%d %x %c \n", i, i, i);
    return 0;
}