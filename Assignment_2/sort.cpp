#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;

const int ConvertToInsertion = 10;

// Function Declrations
// Utilities functions
void Swap(vector<int>&, int, int);
int ExtractMin(vector<int>&, int);
void Merge(vector<int>&,int,int,int);
void HybridInsertionSort(vector<int>&, int, int);

// Main Algorithms
void SelectionSort(vector<int>&);
void InsertionSort(vector<int>&);
void MergeSort(vector<int>&, int, int);
void QuickSort(vector<int>&, int, int);
void HybridSort(vector<int>&, int, int);

// Read And Write input
void WriteOutput(string, vector<int>);
vector<int> ReadInput(string);
void WriteRunningTime(string, double);

int main(int argc, char *argv[]) 
//int main()
{       
    vector<int> unsortedNumbers;
    vector<int> sortedNumbers;
  
    string strSortingIndex = argv[1];
    int sortingIndex = stoi(strSortingIndex);
    string outFileName = (string)argv[3];
    string inFileName = (string)argv[2];
    string timeFileName = (string)argv[4];
    cout << sortingIndex << " " << outFileName << inFileName << timeFileName;
    unsortedNumbers = ReadInput(inFileName);
    auto start = chrono::steady_clock::now() ,end = chrono::steady_clock::now();
    switch(sortingIndex)
    {
        //Selection sort
        case 0:
        SelectionSort(unsortedNumbers);
        sortedNumbers = unsortedNumbers; // After sorting them implicitly
        end = chrono::steady_clock::now();
        break;
        
        case 1:
        InsertionSort(unsortedNumbers);
        sortedNumbers = unsortedNumbers; // After sorting them implicitly
        end = chrono::steady_clock::now();
        break;

        case 2:
        MergeSort(unsortedNumbers, 0, unsortedNumbers.size()-1);
        sortedNumbers = unsortedNumbers; // After sorting them implicitly
        end = chrono::steady_clock::now();
        break;

        case 3:
        QuickSort(unsortedNumbers,0,unsortedNumbers.size()-1);
        sortedNumbers = unsortedNumbers; // After sorting them implicitly
        end = chrono::steady_clock::now();
        break;

        case 4:
        HybridSort(unsortedNumbers,0,unsortedNumbers.size()-1);
        sortedNumbers = unsortedNumbers; // After sorting them implicitly
        end = chrono::steady_clock::now();
        break;

        default:
        cout << "Wrong sorting index, Exiting Program" <<endl;
        return 0;
    }
  

    auto diff = chrono::duration <double, milli>(end-start);
	cout << endl << diff.count() << endl;

    WriteOutput(outFileName , sortedNumbers);
    return 0;
 }
//=========================Input and output handling
 vector<int> ReadInput(string fileName)
 {
    vector<int>numbers;
    ifstream inFile;
    int data;
    inFile.open(fileName);
    while(!inFile.eof())
    {
        inFile >> data ;
        numbers.push_back(data);    
    }
    numbers.pop_back();
    return numbers;
}

void WriteOutput(string fileName, vector<int>sortedNumbers)
{
    ofstream outFile;
    outFile.open(fileName);
    for(int i=0 ;i<sortedNumbers.size();i++)
    {
        outFile << sortedNumbers[i] << " ";
    }
}

//=========================Utility functions
void swap(vector<int>& vec, int i, int j)
{   
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

int ExtractMin(vector<int>& vec, int startingIndex)
{
    int min=numeric_limits<int>::max();
    int minIndex;
    for(int i = startingIndex; i<vec.size(); i++)
    {
        if(min > vec[i])
        {
            min = vec[i];
            minIndex = i;        
        }    
    }
    return minIndex;
}

void Merge(vector<int>&numbers ,int left ,int mid ,int right)
{
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;
    vector<int>leftPart, rightPart;
    int l = 0, r = 0;

    for(int i = 0 ; i<sizeLeft;i++)
        leftPart.push_back(numbers[left + i]);

    for(int i = 0 ; i<sizeRight;i++)
        rightPart.push_back(numbers[mid + 1 + i]);
    
    int i;
    for(i = left ; i <= right ; i++)
    {
        if(sizeLeft!=l && sizeRight!=r)
        {
            if(leftPart[l]<rightPart[r])
            {
                numbers[i] = leftPart[l];
                l++;
            }
            else
            {
                numbers[i] = rightPart[r]; 
                r++;
            }
        }
        else 
            break;
    }
    while(sizeLeft!=l)
    {
        numbers[i] = leftPart[l];
        l++;
        i++;
    }
    while(sizeRight!=r)
    {
        numbers[i] = rightPart[r];
        r++;
        i++;
    }
}

void HybridInsertionSort(vector<int>& numbers, int starting, int end)
{
    int j; 
    for(int i = starting ;i<=(end-1);i++)
    {
        j = i;
        while((j>=starting)&&(numbers[j+1]<numbers[j]))
        {
            swap(numbers,j,j+1);
            j--;
        }
    }
}
//=====================================Main Algorithms================================
void InsertionSort(vector<int>& numbers)
{
    int j; 
    for(int i = 0;i<(numbers.size()-1);i++)
    {
        j = i;
        while((j>=0)&&(numbers[j+1]<numbers[j]))
        {
            swap(numbers,j,j+1);
            j--;
        }
    }
}

void SelectionSort(vector<int>& numbers)
{
    int minIndex;
    for(int i =0; i< numbers.size(); i++)
    {
        minIndex = ExtractMin(numbers,i);
        if(i!=minIndex)
            swap(numbers,i,minIndex);
    }
}


void MergeSort(vector<int>& numbers, int left, int right)
{
    if(left == right)
        return;
    int mid = (right + left)/2;
    MergeSort(numbers,left, mid);
    MergeSort(numbers,mid+1,right);
    Merge(numbers,left, mid, right);
}


void QuickSort(vector<int>& numbers, int left, int right)
{
    if(right <= left)
        return;
    // Pivot is the last element
    int pivot = numbers[right];
    int i = left-1;

    for(int j=left;j<right;j++)
    {
        if(numbers[j]<pivot)
        {
            i++;
            swap(numbers,i,j);
        }    
    }
    i++;
    swap(numbers,i,right);
    QuickSort(numbers,left,i-1);
    QuickSort(numbers,i+1,right);
}

void HybridSort(vector<int>&numbers, int left, int right)
{
    if((right-left) <= ConvertToInsertion )
    {
        HybridInsertionSort(numbers, left, right);
        return;
    }
    // Pivot is the last element
     int pivot = numbers[right];
    int i = left-1;

    for(int j=left;j<right;j++)
    {
        if(numbers[j]<pivot)
        {
            i++;
            swap(numbers,i,j);
        }    
    }
    i++;
    swap(numbers,i,right);
    HybridSort(numbers,left,i-1);
    HybridSort(numbers,i+1,right);
}