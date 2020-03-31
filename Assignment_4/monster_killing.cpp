#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector<int> readinput(vector<int>&);
void minSum(vector<int>&,vector<int>&);
int recMinSum(vector<int>&,int, int&);
int *dp;


int main()
{
    vector<int> monsters;
    vector<int> weapons = readinput(monsters);
    minSum(weapons,monsters);
    return 0;
}

vector<int> readinput(vector<int>&monsters)
{
    int v, size;
    vector<int> weapons;
    cin >> size;
    for(int i=0;i<size;i++)
    {
        cin >> v;
        monsters.push_back(v);
    }
    cin >> size;
    for(int i =0 ; i<size ; i++)
    {
        cin >> v;
        weapons.push_back(v);
    }
    return weapons;
}
// GREEDY solution
void minSum(vector<int>& weapons,vector<int>&monsters)
{
    sort(weapons.begin(),weapons.end(),greater<int>());
    int total_hits_per_monster=0,current_weapon_hits;
    for(int i=0;i<monsters.size();i++)
    {
        for(int j =0;j<weapons.size();j++)
        {
            if(weapons[j] <= monsters[i])
            {
                current_weapon_hits = int(monsters[i]/weapons[j]);
                total_hits_per_monster += current_weapon_hits;
                monsters[i]-= weapons[j]*current_weapon_hits;
            }
        }
        cout << total_hits_per_monster << endl;
        total_hits_per_monster = 0;
    }
}


/*
Dynamic programming solution
void minSum(vector<int>& weapons,vector<int>&monsters)
{
    int result,size;
    int min_fp = *min_element(weapons.begin(), weapons.end()) - 1;
    for(int i = 0 ;i<monsters.size();i++)
    {
        size = monsters[i]+1;
        dp = new int[size];
        memset(dp,0,sizeof dp);
        result = recMinSum(weapons,monsters[i],min_fp);
        cout << result << endl;
        delete dp;
    }
}

int recMinSum(vector<int>&weapons,int val,int&min_fp)
{
    if(val == 0)
        return 0;
    if (val < 0)
        return 10e7;
    if(dp[val])
        return dp[val];
    int min = 10e7;
    int current;
    if(val > min_fp)
    {
        for(int i = 0;i<weapons.size();i++)+
        {   
            current = 1 + recMinSum(weapons,val-weapons[i],min_fp);
            if(current < min)
                min = current;
        }
    }
    else 
        min = 0;
    
    dp[val] = min;
    return min;
}*/