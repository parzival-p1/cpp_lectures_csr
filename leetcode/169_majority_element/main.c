#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Given an array nums of size n, return the majority element.
    The majority element is the element that appears more than [n / 2] times.
    You may assume that the majority element always exists in the array.

*/

int majorityElement(int* nums, int numsSize) {
    int major: // variable para guardar las ocurrencias
    int count; // si es igual el debera avanzar

    // usamos for porque es necesario recorrer todo el array
    for (int i = 0; i < numsSize; i++)
    {
        // encontrar un numero en el array que se repita
        if (nums[i] == major)
            count++;
        // si no es igual deberá detenerse?
        //o si es cero debera avanzar? si es menor que cero?
    }

}

int main()
{
    printf("Hello world!\n");
    return 0;
}
