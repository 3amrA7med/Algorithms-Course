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

node * constructTree(); // Read edges and construct the tree
void printGST(node *);
void recPrintGST(node * , vector<int>& , int&);

int main()
{
    node * root = constructTree();
    printGST(root);
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


void printGST(node * root )
{
    vector<int> toBePrinted;
    int val = 0;
    recPrintGST(root , toBePrinted , val);
    for(int i = toBePrinted.size()-1; i>=0 ; i--)
        cout<<toBePrinted[i]<<" ";
}

void recPrintGST(node * curr , vector<int>&toBePrinted , int& val)
{
    if(curr == NULL)
        return ;
    recPrintGST(curr->right, toBePrinted, val);
    toBePrinted.push_back(val);
    val = val+curr->data;
    recPrintGST(curr->left, toBePrinted, val);
    
}