class Solution {
    bool check(int r,int c,vector<vector<char>> &grid){
        int row = r;
        int col = c;
        while(row>=0&&col>=0){
            if(grid[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row = r;
        col = c;
        while(row>=0){
            if(grid[row][col]=='Q'){
                return false;
            }
            row--;
        }
        row = r;
        col = c;
        int n = grid.size();
        while(row>=0&&col<n){
            if(grid[row][col]=='Q'){
                return false;
            }
            row--;
            col++;
        }
        return true;

    }
public:
    void solve(int row,int &n,vector<vector<string>> &ans,vector<vector<char>> &grid){
        if(row==n){
            vector<string> curr;
            for(int i=0;i<n;i++){
                string s = "";
                for(int j=0;j<n;j++){
                    s.push_back(grid[i][j]);
                }
                curr.push_back(s);
            }
            ans.push_back(curr);
            return;
        }
        for(int c=0;c<n;c++){
            if(check(row,c,grid)){
                grid[row][c] = 'Q';
                solve(row+1,n,ans,grid);
                grid[row][c] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> grid(n,vector<char> (n,'.'));
        solve(0,n,ans,grid);
        return ans;
    }
};