#include "../../includes/minishell.h"

int main()
{
    char *arr;

    arr = malloc(1);
    arr[0] = '\0';
    printf("\"%s\"\n", arr);
}