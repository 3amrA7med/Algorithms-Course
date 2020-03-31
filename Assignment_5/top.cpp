#include <bits/stdc++.h>
using namespace std;
//int graph[10000][10000] = {0};
int **graph;
int read_input();
void topological_sort(int);
void rec_topological_sort(int,int,int*);
int index_sorted;
int main()
{
    int vertices = read_input();
    topological_sort(vertices);
    return 0;
}
int read_input(){
    int size,parent1,parent2;
    cin >> size ;
    graph = new int * [size];
    for(int i =0;i<size;i++)
        graph[i] = new int[size];
    for(int i =0; i<size ; i++)
    {
        cin >> parent1  >> parent2 ;
        if(parent1 != -1)
            graph[parent1][i] = 1;
        if(parent2 != -1)
            graph[parent2][i] = 1;     
    }
    return size;
}

void topological_sort(int vertices)
{
    int* sorted;
    sorted = new int[vertices];
    index_sorted = vertices - 1;
    for(int i =0;i<vertices;i++)
    {
        if(graph[i][i] != 1) //not visited
        {
            rec_topological_sort(i,vertices,sorted);
        }
    }
    for(int i =0;i<vertices;i++)
    {
        cout << sorted[i] << " ";
    }
}

void rec_topological_sort(int index, int vertices,int*sorted)
{
    graph[index][index] = 1; // mark as visited
    for(int i =0;i<vertices;i++)
    {
        if(index != i)
        {
            if(graph[index][i] == 1)
            {
                if(graph[i][i] != 1) //not visited
                {
                    rec_topological_sort(i,vertices,sorted);
                }
            }
        }
    }
    sorted[index_sorted] = index;
    index_sorted--;
}