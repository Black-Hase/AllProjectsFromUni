/********************
Michael V. Hasenkamp

Professor Boese
Worked with: Spencer
*********************/


#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "PriorityQueue.hpp"


using namespace std;

void PriorityQueue::repairUpward(int nodeIndex)
 {
     if(nodeIndex > currentQueueSize)
     {

         //cout << "index cannot be greater than heap size." << endl;
         return;
     }
     int p = nodeIndex/2;
     if(p!= 0 && priorityQueue[p].injurySeverity < priorityQueue[nodeIndex].injurySeverity)
     {

         PatientNode temp = priorityQueue[p];
         priorityQueue[p]= priorityQueue[nodeIndex];
         priorityQueue[nodeIndex]=temp;
         nodeIndex = p;
         repairUpward(nodeIndex);
     }
     else if(p != 0 && priorityQueue[p].injurySeverity == priorityQueue[nodeIndex].injurySeverity)
     {

        if( priorityQueue[p].treatmentTime > priorityQueue[nodeIndex].treatmentTime)
        {

         //check if the time limit is the same
         // want the person with the least amount of time to go first
         PatientNode temp2 = priorityQueue[p];
         priorityQueue[p]= priorityQueue[nodeIndex];
         priorityQueue[nodeIndex]=temp2;
         repairUpward(nodeIndex);
         }
     }
 }

void PriorityQueue::repairDownward(int nodeIndex)
{

    if(nodeIndex >currentQueueSize)
	{
	//	cout << "given index cannot be greater than heap size." << endl;
        return;
    }
    //left and right children
    int l = 2* nodeIndex;
    int r = 2* nodeIndex+1;
    //set give index as smallest 
    int smallest = nodeIndex;
    //compare it with its left and right children and set smallest
    if(l <= currentQueueSize)
    {
            if(priorityQueue[smallest].injurySeverity < priorityQueue[l].injurySeverity)
            {
                smallest =l;
            }
             else if(priorityQueue[smallest].injurySeverity == priorityQueue[l].injurySeverity)
             {
                if(priorityQueue[smallest].treatmentTime > priorityQueue[l].treatmentTime)
                {

                    smallest = l;
                }    
             }
    }
     if(r <= currentQueueSize)
    {
            if(priorityQueue[smallest].injurySeverity < priorityQueue[r].injurySeverity)
            {
                smallest =r;
            }
             else if(priorityQueue[smallest].injurySeverity == priorityQueue[r].injurySeverity)
             {
                if(priorityQueue[smallest].treatmentTime > priorityQueue[r].treatmentTime)
                {
                    smallest = r;
                }
                
             }
    }
    
   
    if(smallest!=nodeIndex)
    {
         PatientNode temp2 = priorityQueue[nodeIndex];
         priorityQueue[nodeIndex]= priorityQueue[smallest];
         priorityQueue[smallest]=temp2;
         repairDownward(nodeIndex);
    }
    

}

 PriorityQueue::PriorityQueue(int _queueSize)
 {
     priorityQueue = new PatientNode[_queueSize+1];
     currentQueueSize=0;
     maxQueueSize =_queueSize;
 }
 PriorityQueue::~PriorityQueue()
 {
     delete[] priorityQueue;
 }

void PriorityQueue::enqueue (std::string _name, int _injurySeverity, int _treatmentTime)
{
    /*
    PatientNode * temp3 =new PatientNode;
    temp3->injurySeverity = _injurySeverity;
    temp3->treatmentTime = _treatmentTime;
    // Corner case: If heap is full
	if(currentQueueSize == maxQueueSize)
	{
		cout << "Heap is full. Cannot Puth the key.";
		return
	}
	
    // increment the heap size
currentQueueSize++;
    // insert the new key at the end
	priorityQueue[currentQueueSize] = temp3;

    // Fix the min heap property if it is violated
    cout<<endl<<"Index of "<<priorityQueue[currentQueueSize]<<" : "<<currentQueueSize<<endl;
    cout<<"Parent of "<<priorityQueue[currentQueueSize]<<" : "<<priorityQueue[parent(currentQueueSize)]<<" at index : "<<parent(currentQueueSize)<<endl;
    // --- ENTER CODE HERE --- //
	repairUpward(currentQueueSize);

    //cout<<endl;
    */
    if(isFull())
    {
        cout << "NO ROOM: YOU GONNA DIE SAY HI TO SATAN FOR ME!" << endl;
        return;
    }
    if(currentQueueSize == 0)
    {
         
    priorityQueue[1].name = _name;
    priorityQueue[1].injurySeverity = _injurySeverity;
    priorityQueue[1].treatmentTime = _treatmentTime;
    currentQueueSize++;
    return;
    }
   
    priorityQueue[currentQueueSize+1].name = _name;
    priorityQueue[currentQueueSize+1].injurySeverity = _injurySeverity;
    priorityQueue[currentQueueSize+1].treatmentTime = _treatmentTime;                   
    currentQueueSize++;
    repairUpward(currentQueueSize);
    return;
    
}

string PriorityQueue::peekName()
{
    return priorityQueue[1].name;
}
int PriorityQueue::peekInjurySeverity()
{
    return priorityQueue[1].injurySeverity;
}
int PriorityQueue::peekTreatmentTime()
{
    return priorityQueue[1].treatmentTime;
}
void PriorityQueue::PriorityQueue::dequeue()
{
    if(isEmpty())
    {
        return;
    }
    if(currentQueueSize == 1)
    {
        currentQueueSize--;
        return;
    }
    priorityQueue[1]=priorityQueue[currentQueueSize];
    currentQueueSize--;
    repairDownward(1);
}
bool PriorityQueue::isFull()
{
    if(currentQueueSize == maxQueueSize )
    {
        return true;
    }
    return false;
}
bool PriorityQueue::isEmpty()
{
    if(currentQueueSize ==0)
    {
        return true;
    }
    return false;
}








