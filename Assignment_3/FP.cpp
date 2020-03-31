/*
Name : Amr Ahmed Abdelbaqi Mahmoud
Section : 2
BN : 3


*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
unordered_map<int,int> readInput(vector<int>&);
int calcNumberOfPairs(unordered_map<int,int>, vector<int>);

int main()
{
    vector<int> distinct;
    unordered_map<int,int> table = readInput(distinct);
    int numOfPairs = calcNumberOfPairs(table,distinct);
    cout << numOfPairs << endl;
    return 0; 
}

int calcNumberOfPairs(unordered_map<int,int> freq, vector<int> distinct)
{
    int sum = 0;
    for(int i=0;i<distinct.size();i++)
    {
        for(int j=0;j<distinct.size();j++)
        {
            if((freq[distinct[i]] >= distinct[j])&&(freq[distinct[j]] >= distinct[i]))
                sum++;
        }
    }
    return sum;
}

unordered_map<int,int> readInput(vector<int>& distinct)
{
    unordered_map<int,int> umap;
    int key;
    while(cin>>key)
    {
        if (umap.find(key) == umap.end()) 
        {   
            distinct.push_back(key); // the sequence of distinct numbers.
            umap.insert(make_pair(key, 1)); // Initialze the number with freq 1
        }
        else
            umap[key] ++; // Increase frequency of the number
    }
    return umap;
}
