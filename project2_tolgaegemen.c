#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;

int *address;
int size;
int search;

//functions for testing the free() method
func2(char **str)
{
    free(*str);  //free
    *str = NULL; //Set to NULL
}

func1(char **str) //func1 receives as **
{
    func2(str); //Pass pointer to func2()
}

void *TEDU_alloc(int size)
{
    address = malloc(size);
    printf("Base address of array: %d\n", address);

    for (int i = 0; i <= (size / 4) - 1; i++)
    {
        address[i] = rand() % 20; //fill array with random numbers 0 to 20
        printf("%d. element of address is %d, starts at %u       ends at %u\n", i, address[i], address + i, address + i + 1);
    }

    int sizeOfChunk = (&address[size]) - address;

    printf("%d bytes of data is allocated\n", sizeOfChunk);
}

int TEDU_Free(void *ptr)
{

    //call functions to free the memory of the address, and test if its free

    printf("TESTING FREE()............................");
    func1(&ptr); //Pass Address of pointer to func1()

    if (ptr) //Check for NULL
    {
        printf("\nNot - Freed...\n");
    }
    else
    {
        for (int i = 0; i < size; i++) //nullify array elements
        {
            address[i] = NULL;
        }
        printf("\nFreed...\n");
    }
}

int Mem_IsValid(int ptr)
{
    bool isFound = false;

    for (int i = 0; i <= size; i++) //Perform checks for all of allocated chunk
    {

        int x = (int *)&address[i]; //Search if the input is in our allocated pointer storage array
        if (ptr == x)
        {

            printf("%u ADDRESS IS USED BY ELEMENT --> %d\n", ptr, address[i]);
            isFound = true;
            break;
        }

        else if (ptr - 1 == x)
        {

            printf("%u ADDRESS IS USED BY ELEMENT --> %d\n", ptr, address[i]);
            isFound = true;
            break;
        }
        else if (ptr - 2 == x)
        {

            printf("%u ADDRESS IS USED BY ELEMENT --> %d\n", ptr, address[i]);
            isFound = true;
            break;
        }
        else if (ptr - 3 == x)
        {

            printf("%u ADDRESS IS USED BY ELEMENT --> %d\n", ptr, address[i]);
            isFound = true;
            break;
        }
    }
    if (isFound == false)
    {
        printf("ADDRESS IS NOT USED\n");
    }
}

void TEDU_GetStats()
{
    printf("\nProcess Name, Memory Usage and CPU Time:\n");
    system("top -l 1 -stats \"command,mem,cpu\" | grep malloc2");
}

int main()
{
    int input1;
loop1:

    printf("\n1) Press 1 to allocate memory (call TEDU_alloc):\n");
    printf("2) Press 2 to free memory (call TEDU_Free)\n");
    printf("3) Press 3 to check if an address falls within the range of an allocated object (call Mem_IsValid)\n");
    printf("4) Press 4 to view memory usage (call TEDU_GetStats)\n");
    printf("0) Press 0 to exit\n");

    scanf("%d", &input1);

    if (input1 == 1)
    {
        printf("Enter the size:");
        scanf("%d", &size);
        TEDU_alloc(size);
        goto loop1;
    }
    else if (input1 == 2)
    {
        TEDU_Free(address);
        goto loop1;
    }
    else if (input1 == 3)
    {
        printf("Enter the address you want to search for:");
        scanf("%d", &search);
        Mem_IsValid(search);
        goto loop1;
    }
    else if (input1 == 4)
    {
        TEDU_GetStats();
        goto loop1;
    }
    else if (input1 == 0)
    {
        return (0);
    }
}