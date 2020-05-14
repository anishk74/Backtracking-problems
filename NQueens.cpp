class Solution {
public:
    int i=0;
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        vector<vector<string>> ans;
        string temp;
        
        int i;
        for(i=0;i<n;i++)
            temp+='.';
        for(i=0;i<n;i++){
            board.push_back(temp);
        }
        
        return solveNQueens(0,n,board,ans);
        
    }
    vector<vector<string>> solveNQueens(int i,int n, vector<string> board, vector<vector<string>> ans) {
        //cout<<"void"<<i<<endl;
        if(i==n){
            
             //cout<<"size: ";
            //cout<<ans.size()<<endl;
            //cout<<i<<endl;
            int i1,j1;
            for(i1=0;i1<n;i1++){
                for(j1=0;j1<n;j1++){
                    if(board[i1][j1]=='|'){
                        board[i1][j1]='.';
                    }
                }
            }
            ans.push_back(board);
            return ans;
        }
        //cout<<"void"<<i<<endl;
        int j,k;
        for(j=0;j<n;j++){
            if(board[i][j]=='.'){
                vector<string> newboard=board;
                int count=0;
                newboard[i][j]='Q';
                for(k=1;k<n-i;k++){
                    newboard[i+k][j]='|';
                    if(j-k>=0)
                    newboard[i+k][j-k]='|';
                    if(j+k<n)
                    newboard[i+k][j+k]='|';
                }
                /*
                for(k=0;k<n;k++){
                    cout<<newboard[k]<<endl;
                    
                }
                */
                ans=solveNQueens(i+1,n,newboard,ans);
            }
        }
        return ans;
    }
};