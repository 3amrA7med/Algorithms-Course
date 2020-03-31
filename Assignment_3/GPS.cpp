/*
Name : Amr Ahmed Abdelbaqi Mahmoud
Section : 2
BN : 3


*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int,int> readInput(vector<int>&, int&);
long long calcNumberOfSubSequences(unordered_map<int,int>, vector<int>, int);

int main()
{
    vector<int> sequence;
    int ratio;
    unordered_map<int,int> table = readInput(sequence,ratio);
    long long numOfSubSequence = calcNumberOfSubSequences(table,sequence,ratio);
    cout << numOfSubSequence << endl;
    return 0; 
}

long long calcNumberOfSubSequences(unordered_map<int,int> freq, vector<int> sequence , int r)
{
    long long numOfSubSeq = 0;
    int element; 
    unordered_map<int,int> left,right;
    right = freq ;
    for(int i=0;i<sequence.size()-2;i++)
    {
        element = sequence[i]; // Middle element in subsequence
        if(element % r == 0) // Divible by r
            numOfSubSeq += right[element*r]*left[element/r]; // calculate the number of subsequences 
        right[element]--; // remove this element from the right map
        left[element]++;  // put this element in the left map
    }
    return numOfSubSeq;
}

unordered_map<int,int> readInput(vector<int>& sequence, int& ratio)
{
    unordered_map<int,int> umap;
    int key;
    cin >> ratio;
    while(cin>>key)
    {
        if (umap.find(key) == umap.end()) 
            umap.insert(make_pair(key, 1)); // Initialze the number with freq 1
        else
            umap[key] ++; // Increase frequency of the number
         sequence.push_back(key); // the sequence of the input numbers.
    }
    return umap;
}