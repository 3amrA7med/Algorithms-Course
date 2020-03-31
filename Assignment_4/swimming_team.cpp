#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector<int> readinput(vector<int>&);
int bestTeam(vector<int>&,vector<int>&);

int main()
{
    vector<int> first_team;
    vector<int> second_team = readinput(first_team);
    int bestStamina = bestTeam(first_team,second_team);
    if (first_team.size()==0)
    {
        cout<<0;
        return 0;
    }
    if (first_team.size()==1)
    {
        cout << max(first_team[0],second_team[0]);
        return 0;
    }
    cout << bestStamina << endl;
    return 0;
}

vector<int> readinput(vector<int>&first_team)
{
    int v, size;
    vector<int> second_team;
    cin >> size;
    for(int i=0;i<size;i++)
    {
        cin >> v;
        first_team.push_back(v);
    }
    for(int i =0 ; i<size ; i++)
    {
        cin >> v;
        second_team.push_back(v);
    }
    return second_team;
}
// GREEDY solution
int bestTeam(vector<int>& first_team,vector<int>&second_team)
{
    int temp1 = first_team[0];
    int temp2 = second_team[0];
    int s1,s2;
    for(int i=1;i<first_team.size();i++)
    {
        s1 = max(temp1 , temp2+first_team[i]);
        s2 = max(temp2 , temp1+second_team[i]);
        temp1 = s1;
        temp2 = s2;
    }
    int maxx = max(temp1,temp2);
    return maxx;
}

int max(int a, int b)
{
    return (a>b)?a:b;
}
