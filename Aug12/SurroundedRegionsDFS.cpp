//Link: https://leetcode.com/problems/surrounded-regions/description/
int xMove[] = {0,0,1,-1};
int yMove[] = {1,-1,0,0};
class Solution {
public:
    
    bool isSafe(int c,int r, int m,int n){
        return (c>=0 && r>=0 && c<m && r<n);
    }
    
    void dfs(int c,int r, vector<vector<bool> > &visited, vector<vector<char> > &board,int m,int n){
        visited[c][r] = true;
        board[c][r] = 'O';
        
        for(int i=0;i<4;i++){
            
            int newC = c + xMove[i];
            int newR = r + yMove[i];
            
            if(isSafe(newC,newR,m,n) && !visited[newC][newR] && board[newC][newR]=='_'){
                    dfs(newC,newR,visited,board,m,n);
            }
            
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m==0) return;
        int n = board[0].size();
        if(n==0) return;
        
        
        //make all border 'O' to '_'
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j] = '_';
            }
        }
        
       
        
        
        vector<vector<bool> > visited(m,vector<bool> (n,false));
        
        //consider all border elements which are '_' and apply dfs on them to find all '_'s connected to them
        for(int i=0;i<n;i++)
            if(!visited[0][i] && board[0][i]=='_')
                dfs(0,i,visited,board,m,n);
        
        for(int i=1;i<m;i++)
            if(!visited[i][n-1] && board[i][n-1]=='_')
                dfs(i,n-1,visited,board,m,n);
        
        for(int i = n-2;i>=0;i--)
            if(!visited[m-1][i] && board[m-1][i]=='_')
                dfs(m-1,i,visited,board,m,n);
        
        for(int i=m-2;i>=1;i--)
            if(!visited[i][0] && board[i][0]=='_')
                dfs(i,0,visited,board,m,n);
        
        
        //convert remaining '_' to 'X' since they are not connected to outside
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]=='_')
                    board[i][j] = 'X';
        
        
    }
};
