class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> st;
        vector<string> board(n,string(n,'.'));
        string s(n,'.');
        solve(0,board,st,n);
        return st;
    }
    bool issafe(int row,int col,vector<string> &board,int n){
        int rw = row;
        int cl = col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }

        row=rw;
        col=cl;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        col = cl;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            col--;
            row++;
        }
        return true;
    }

    void solve(int col,vector<string>& board,vector<vector<string>> &st,int n){
        if(col == n){
            st.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++){
            if(issafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,st,n);
                board[row][col]='.';
            }
        }
    }
};