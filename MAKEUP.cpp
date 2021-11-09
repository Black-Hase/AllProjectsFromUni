#include <iostream>
using namespace std;

int insertBeforeKey(int list[], int capacity, int* numItems, int key, int newVal)
{
    int index =-1;
    if(*numItems>=capacity)
    {
        return -1;
    }
    for(int i=0; i < * numItems; i++)
    {
        if(list[i]==key)
        {
            index =i;
            for(int j = *numItems; j>i; j--)
            {
                list[j]=list[j+1];
            }
            break;
        }
    }
    if(index==-1)
    {
        return -1;
    }
    (*numItems)++;
    list[index+1]=newVal;
    return 0;
}
int main()
{
    int array[5]={1,2,3,4};
    int key =2;
    int newVal =0;
    insertBeforeKey(int array[],5,4,key,newVal);
    
}

