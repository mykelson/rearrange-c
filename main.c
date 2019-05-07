#include <stdio.h>
#include <stdlib.h>

void rearrange(int list[], int n);
int decimal_to_binary(int n);

int main(void)
{
    int array[100], c, n;
    printf("Enter a number: ");
    scanf("%i", &n);

    //Populate the array
    printf("Enter %i numbers:\n", n);
    for (c=0; c < n; c++)
        scanf("%i", &array[c]);

    //Sort the array
    rearrange(array, n);

    printf("\n");
    for (c=0; c < n; c++)
        printf("%i\n", array[c]);

    return 0;
}


void rearrange(int list[], int n)
{
    int c, d, t;

    for (c = 0; c < n-1; c++)
    {
        for(d = 0; d < n - c - 1; d++)
        {
            if (decimal_to_binary(list[d]) > decimal_to_binary(list[d+1]))
            {
                // swapping
                t = list[d];
                list[d] = list[d+1];
                list[d+1] = t;
            }
            else if ((decimal_to_binary(list[d]) == decimal_to_binary(list[d+1])) && (list[d] > list[d+1]))
            {                
                
                // swapping
                t = list[d];
                list[d] = list[d+1];
                list[d+1] = t;
                
            }
        }
    }
}


int decimal_to_binary(int n)
{
    int c, d, count;
    char *pointer;
    int l = 0;

    count = 0;
    pointer = (char *)malloc(32+1);

    if (pointer == NULL)
        exit(EXIT_FAILURE);
    
    for (c = 31; c >= 0; c--)
    {
        d = n >> c;

        if (d & 1)
        {
            *(pointer+count) = 1 + '0';
            l++;
        }
        else
            *(pointer+count) = 0 + '0';

        count++;
    }
    *(pointer+count) = '\0';

    return l;
}