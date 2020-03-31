/*
Name : Amr Ahmed Abdelbaqi Mahmoud
Section : 2
BN : 3


*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
#define levelsSize 1000

struct node {
    int data;
    node*left;
    node*right;

    node(int val, node * l = NULL , node * r = NULL)
    {
        data = val;
        left = l;
        right = r;
    }
};


void calculate(node *,double*,double*);
void recCalculate(node *,double*,double*,int);
void printAverage(double*,double*);
node * constructTree(); // Read edges and construct the tree


int main()
{
    double sum[levelsSize]={0};
    double size[levelsSize]={0};
    node * root = constructTree();
    calculate(root,sum,size);
    printAverage(sum,size);
    return 0; 
}

node * constructTree()
{
    vector<node *> nodes;
    int data , numNodes , numEdges;
    node * newNode = NULL;
    cin >> numNodes;
    for(int i = 0 ; i < numNodes ; i++)
    {
        cin >> data;
        newNode = new node(data);
        nodes.push_back(newNode);
    }
    cin >> numEdges;
    node * root = NULL;
    if(nodes.size() == 0)
        return root;
    root = nodes[0];
    char childPos;
    int parent , child;
    for(int i = 0 ; i < numEdges ; i++)
    {
        cin >> childPos >> parent >> child;
        if(int(childPos) == int('L'))
            nodes[parent]->left = nodes[child];  
        else 
            nodes[parent]->right = nodes[child]; 
    }
    return root;
}

void calculate(node * root ,double*sum , double* size)
{
    recCalculate(root,sum , size ,0);
}
void recCalculate(node* currNode , double* sum , double* size, int currLevel)
{
    if(currNode == NULL)
        return;
    sum[currLevel]+=currNode->data;
    size[currLevel]++;
    recCalculate(currNode->right, sum , size ,currLevel+1);
    recCalculate(currNode->left, sum , size , currLevel+1);
}
void printAverage(double*sum , double* size)
{
    for(int i = 0; i < levelsSize ; i++)
    {
        if(sum[i] == 0)
            break;
        else
            cout << sum[i]/size[i] << " " ;
        
    }
}
