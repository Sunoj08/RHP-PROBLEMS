class Solution {
    final int diff[][]={{0,-1},{0,1},{-1,0},{1,0}};
    private void dfs(char grid[][],int R,int C,int row, int col){
        grid[row][col]='0';
        for(int i=0;i<4;i++){
            int ar=row+diff[i][0],ac=col+diff[i][1];
            if(ar>=0&&ar<R&&ac>=0&&ac<C&&grid[ar][ac]=='1'){
                dfs(grid,R,C,ar,ac);
            }
        }
    }
    public int numIslands(char[][] grid) {
        int R=grid.length,C=grid[0].length;
        int islands=0;
        for(int row=0;row<R;row++){
            for(int col=0;col<C;col++){
                if(grid[row][col]=='1'){
                    islands++;
                    dfs(grid,R,C,row,col);
                }
            }
        }
        return islands;
    }
}
