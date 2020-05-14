class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        
        
        vector<string> subsquare,row,column;
        int i,j;
        for(i=0;i<9;i++){
            subsquare.push_back("000000000");
            column.push_back("000000000");
            row.push_back("000000000");
        }
        char cur;
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                //cout<<board[i][j]<< " ";
            }
            //cout<<endl;
        }
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                cur=board[i][j];
                
                if(cur>='1'&&cur<='9'){
                    row[i][(int)cur-49]='1';
                    column[j][(int)cur-49]='1';
                    subsquare[(i/3)*3 + j/3][(int)cur-49]='1';
                }
                
            }
            
        }
        /*
         for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                cout<<row[i][j]<< " ";
            }
            cout<<endl;
        }
        */
        vector <vector<char>> board1=board;
        solveSudoku(0,0,subsquare,row,column,board1,board);
        /*
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                board[i][j]=board1[i][j];
            }
        }
        */
        
        
        
        
    }
    void solveSudoku(int i,int j,vector<string> subsquare,vector<string> row,vector<string> column,vector<vector<char>> board,vector<vector<char>>& origboard){
        
        if(i>=9){
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
                    origboard[i][j]=board[i][j];
                    //cout<<board[i][j]<<" ";
                }
                //cout<<endl;
            }
            return;
        }
        if(board[i][j]!='.'){
            if(j<8){
                solveSudoku(i,j+1,subsquare,row,column,board,origboard);
            }
            else{
                solveSudoku(i+1,0,subsquare,row,column,board,origboard);
            }
            return;
        }
        int ss=(i/3)*3 + j/3;
        int i1;
        for(i1=0;i1<9;i1++){
            if(subsquare[ss][i1]=='0' && row[i][i1]=='0' && column[j][i1]=='0'){
                
                vector<string> newsubsquare=subsquare;
                newsubsquare[ss][i1]='1';
                vector<string> newrow=row;
                newrow[i][i1]='1';
                vector<string> newcolumn=column;
                newcolumn[j][i1]='1';
                vector<vector<char>> newboard=board;
                newboard[i][j]=49+(i1);
                //cout<<i<<" "<<j<<" "<<i1<<endl;
                if(j<8){
                    solveSudoku(i,j+1,newsubsquare,newrow,newcolumn,newboard,origboard);
                }
                else{
                    solveSudoku(i+1,0,newsubsquare,newrow,newcolumn,newboard,origboard);
                }
                //board[i][j]='.';
            }
        }
    }
};