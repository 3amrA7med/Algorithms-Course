#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
void readinput();
void bestMove();
int recBestMove(int,int,bool);
int N,A1,A2,B1,B2;
#define player1_loses -1
#define player1_wins 1
int player1_dp[10000][10000];
int player2_dp[10000][10000];
int main()
{
    readinput();
    bestMove();
    return 0;
}

void readinput()
{
    cin >> N;
    cin >> A1;
    cin >> A2;
    cin >> B1;
    cin >> B2;
}


// Dynamic programming solution
void bestMove()
{
    int player1 = N,player2 =N;
    bool player1_turn=true;
    // true => player1 , false => player2
    int who_wins = recBestMove(player1,player2,player1_turn);
    if (who_wins >0)
        cout << 1 << " " << who_wins - 1 << endl;
    else
        cout << 2 << " " << abs(who_wins + 1) << endl;
      

}

int recBestMove(int player1,int player2,bool player1_turn)
{
    // case both players reached zero
    if( player1 <= 0 && player2 <=0)
    {
        if (player1_turn)
            return player1_wins;
        else 
            return player1_loses;
    }
    // case one player won
    if( player1 <= 0 || player2 <=0)
    {
        // player1 lost
        if(player1 <=0)
            return player1_loses;
        // player 2 lost
        else
            return player1_wins;
    }
    if(player1_turn && player1_dp[player1][player2])
        return  player1_dp[player1][player2];
    if((!player1_turn )&& player2_dp[player1][player2])
        return player2_dp[player1][player2];
    
    if(player1_turn)
    {
        int temp =  max(recBestMove(player1 - A1,player2 -A2,false),
        recBestMove((player1%3==0)?player1:player1-B2,(player1%3==0)?player2 -B1:player2 - B2,false));
        if(temp >0)
            temp++;
        else
            temp--;
        player1_dp[player1][player2] = temp;
        return temp;
        
    }
    else {
        int temp = min (recBestMove(player1 - A2,player2 -A1 , true),
        recBestMove((player2%3==0)?player1-B1:player1-B2,(player2%3==0)?player2:player2 - B2,true));
        if(temp >0)
            temp++;
        else
            temp--;
        player2_dp[player1][player2] = temp;
        return temp;
    }
}
int max(int a, int b)
{
    return (a>b)?a:b;
}
int min(int a,int b)
{
    return (a<b)?a:b;
}