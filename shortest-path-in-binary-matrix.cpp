class Solution {
public:

    bool valid(int x,int y,int n){
        return x>=0 && x<=n-1 && y>=0 && y<=n-1;
    }
vector> moves={{0,-1},{-1,-1},{-1,0},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
    int shortestPathBinaryMatrix(vector>& grid) {
        int n=grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        
        queue> q;
        
        q.push({0,0,1});
        while(!q.empty()){
            vector prevcell=q.front();
            q.pop();
            if(prevcell[0]==n-1 && prevcell[1]==n-1)
                return prevcell[2];
            
            for(int i=0;i<8;i++){
                int x=prevcell[0]+moves[i].first;
                int y=prevcell[1]+moves[i].second;
                if(valid(x,y,grid.size()) && grid[x][y]==0){
                    grid[x][y]=1; 
                    q.push({x,y,prevcell[2]+1});
                }
            }
        }
        
        return -1;
    }
};
