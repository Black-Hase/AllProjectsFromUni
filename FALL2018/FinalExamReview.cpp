#include <iostream>

using namespace std;


/*
Quiz 1 4


Write code to search a float array named values for the value in the variable named findMe. The array has num number of
elements in the list. Inside the loop, print out the element at each index separated with a semicolon, and stop searching the array once you
find the value in the variable findMe. Note: if the value in findMe is not in the list, then you will print out each element in the array.

For example, if the array has {1, 2, 3} and findMe is 2, you would print:

1;2




int main()
{
    int num =5;
    float findMe= 2;
 float value[num]={0,1,2,3,4};
     for(int i=0; i<num;i++)
     {
         if(value[i]!=findMe)
         {
             cout << value[i] << ";";
             
         }
         else if(value[i]==findMe)
         {
             cout << value[i];
             break;
         }
     }
    
    
    
    
    return 0;
}

*/

/*
Quiz 1 Problem 8

Write a function named insertInArray that takes the parameters list as an integer array, size 
for the capacity of the array, numItems has the number of items in the array, index which is the  index where the new item should go, and newVal
has the new value to be inserted into the array. If the array is at capacity then the function should return -1, otherwise return 0 for success.

int insertInArray(int list[ ], int size, int* numItems, int index, int newVal)
For example, if the array has {9, 2, 8, 3} and the array has the capacity to add a new value, and the new value is '5' at index '2', then the resulting array should be {9, 2, 5, 8, 3} and the function should return 0. You will also need to add one to the numItems variable.

*/


int insertInArray(int list[], int size, int* numItems, int index, int newVal)
{
    if(*numItems-1!=size)
    {
        
    
        for(int i=*numItems-1; i>index-1; i--)
        {
            list[i+1]=list[i];
        }
        list[index]=newVal;
        return 0;
    }
    else
    {
        return -1;
    }
    
    
}

int main()
{
    int size =6;
   int list[size]={1,2,3,4,5};
    int i=7;
    int T=5;
    int *t=T;
    insertInArray(list,size,t,2,i);
    return 0;
}