#include <iostream>
#include  <stdio.h>
#include <string.h>
#include <vector>
vector<int> v;
void markMultiples(bool arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
}
 
// A function to print all prime numbers smaller than n
void SieveOfEratosthenes(int n)
{
    // There are no prime numbers smaller than 2
    if (n >= 2)
    {
        // Create an array of size n and initialize all elements as 0
        bool arr[n];
        memset(arr, 0, sizeof(arr));
 
        /* Following property is maintained in the below for loop
           arr[i] == 0 means i + 1 is prime
           arr[i] == 1 means i + 1 is not prime */
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                v.push_back(i+1);
                markMultiples(arr, i+1, n);
            }
        }
    }
}
 
// Driver Program to test above function
int main()
{
    int n = 30;
    SieveOfEratosthenes(n);
    for (int i = 0; i < v.size(); ++i)
    {
        for (int i = 0; i < ; ++i)
        {
            /* code */
        }
    }
    return 0;
}