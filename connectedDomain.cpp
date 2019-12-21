class connectedDomain{
public:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    
    int maxArea(vector<vector<int>>& grid>){
        int m = grid.size(), n = grid[0].size(),res= 0;
        for(int i = 0; i < m; i++){
            for(int j =0; j< n; j++){
                if(grid[i][j]!= 1) continue;
                int cnt = 0;
                helper(grid,i,j,cnt,res);
            }
        }
        return res;
    }
    
    void helper(vector<vector<int>>& grid, int i, int j, int& cnt, int& res){
        m = grid.size();n = grid[0].size();
        if(i<0|| i>=m||j<0||j>=n||gird[i][j]!=1) return;
        res = max(res,++cnt);
        grid[i][j] = -1;
        for(auto dir:dirs){
            helper(grid, i+dir[0],j+dir[1],cnt,res);
        }
    }
}


bool hasPath(char* matrix, char* str,int rows, int cols){
    if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr) return false;
    bool* visited = new bool[rows*cols];
    memset(visited, 0 ,rows*cols);
    int pathLength = 0;
    for(int i=0; i< rows; ++i){
        for(int j=0; j<cols;++j){
            if(helper(matrix,str,visited,pathLength,rows,cols,i,j)) return true;
        }
    } 
    delete[] visited;
    return false;
}

bool helper(char* matrix, char* str,  bool* visited, int& pathLength, int rows, int cols,int i, int j){
    if(str[pathLength] == '\0') return true;
    bool hasPath = false;
    if(!visited[i*rows+j] && matrix[i*rows+j]==str[pathLength] && i >=0 && i < rows && j >=0 && j<cols){
        pathLength++;
        visited[i*rows+j]=true;
        hasPath = helper(matrix,str,visited,pathLength, rows,cols,i,j+1) || helper(matrix,str,visited,pathLength,rows,cols,i,j-1) || helper(matrix,str,visited,pathLength,rows,cols,i+1,j) ||  helper(matrix,str,visited,pathLength,rows,cols,i-1,j)

        if(!hasPath){
            pathLength--;
            visited[row*cols+col] = false;
        }
    }
    return hasPath;
}