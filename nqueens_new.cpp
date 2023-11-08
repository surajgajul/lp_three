#include <iostream>
#include <string>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<string> &board,int row,int col,int n){
    int i=row,j=col;

    while(i!=-1){
        if(board[i][j]=='Q')return false;
        i--;
    }

    i=row;
    while(i!=-1&&j!=-1){
        if(board[i][j]=='Q')return false;
        i--;
        j--;
    }

    i=row;
    j=col;
    while(i!=-1&&j!=n){
        if(board[i][j]!='.')return false;
        i--;
        j++;
    }

    return true;

}

void solve(vector<string> &board,vector<vector<string>> &ans, int row, int n){
    if(row==n){
        ans.push_back(board);
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n\n";
        return;
    }

    for(int i =0;i<n;i++){
        if(isSafe(board,row,i,n)){
            board[row][i]='Q';
            solve(board,ans,row+1,n);
            board[row][i]='.';
        }
    }

}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board;

    string s(n,'.');
    
    for(int i =0;i<n;i++){
        board.push_back(s);
    }

    solve(board,ans,0,n);

    return ans;

}

int main (){
    int n;cin>>n;
    solveNQueens(n);
    
    return 0;
}