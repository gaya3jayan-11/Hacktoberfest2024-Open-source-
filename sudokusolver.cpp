#include<bits/stdc++.h>

using namespace std;

bool isValidNum(vector<vector<char>>& board, int row, int col, char ele)
{
    for(int i=0; i<9; i++)
    {
        if(board[row][i]==ele)
            return false;
    }
    for(int i=0; i<9; i++)
    {
        if(board[i][col]==ele)
            return false;
    }
    int blockRow=row-row%3,blockCol=col-col%3;
    for(int i=blockRow; i<blockRow+3; i++)
    {
        for(int j=blockCol; j<blockCol+3; j++)
        {
            if(board[i][j]==ele)
                return false;
        }
    }
    return true;
}
bool isSolvable(vector<vector<char>>&board, int row, int col)
{
    //cout<<"\n\nOutside: row= "<<row<<"   col= "<<col;
    if(row==8 && col==9)
        return true;
    if(col==9)
    {
        row++;
        col=0;
    }
    //cout<<"\nVal= "<<board[row][col];
    if(isdigit(board[row][col]))
        return isSolvable(board, row, col+1);
    //cout<<"\nInside: row= "<<row<<"   col= "<<col;
    for(char i='1'; i<='9'; i++)
    {
        //cout<<"\nnumber= "<<i;
        if(isValidNum(board,row,col,i))
        {
            //cout<<"\nValid= "<<i;
            board[row][col]=i;
            if(isSolvable(board, row, col+1))
                return true;
        }
        board[row][col]='.';
    }
    return false;
}
int main()
{
    cout<<"Enter the unsolved sudoku (use '.' for empty cells):\n";
    vector<vector<char>>board(9,vector<char>(9));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cin>>board[i][j];
    }
    if(isSolvable(board,0,0)){
        cout<<"\n\nSolved sudoku is:\n";
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
                cout<<board[i][j]<<"\t";
            cout<<"\n";
        }
    }
    else
        cout<<"\n\nThis sudoku cannot be solved";
}
