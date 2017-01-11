/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n < 1)
    {
        return false;
    }
    int start, end, index;
    start = 0;
    end = n - 1;
    index = (start + end) / 2;
    while (end >= start)
    {
        if (values[index] == value)
        {
            return true;
        }
        else if (value > values[index])
        {
            start = index + 1;
        }
        else 
        {
            end = index - 1;
        }
        index = (start + end) / 2;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int temp, min, index;
    temp = values[0];
    index = -1;
    
    for (int i = 0; i < n; i++)
    {
        min = values[i + 1];
        for (int j = i + 1; j < n; j++)
        {
            if (values[j] < min)
            {
                min = values[j];
                index = j;
            }
        }
        if (min < values[i])
        {
            temp = values[i];
            values[i] = values[index];
            values[index] = temp;
        }
    }
    
    return;
}
