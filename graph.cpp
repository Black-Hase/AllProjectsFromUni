#include "graph.hpp"
#include<iostream>
#include<set>
#include<list>
#include<algorithm>
using namespace std;


Graph::Graph(int nodeCount) {
   n = nodeCount;
   adjList = new list<node>[n];
}

void Graph::showList(int src, list<node> lt) {
   list<node> :: iterator i;
   node tempNode;

   for(i = lt.begin(); i != lt.end(); i++) {
      tempNode = *i;
      cout << "(" << src << ")---("<<tempNode.dest << "|"<<tempNode.cost<<") ";
   }
   cout << endl;
}



void Graph::addEdge(int source, int dest, int cost)
{

}

void Graph::displayEdges()
{
   for(int i = 0; i<n; i++)
   {
      list<node> tempList = adjList[i];
      showList(i, tempList);
   }
}

int Graph:: min_element(int dist[], bool visited[])
{
   // Initialize min value
   int min = INT_MAX, min_index = -1;


   return min_index;
}

void Graph::dijkstra( int *dist, int *prev, int start)
{
   
}
