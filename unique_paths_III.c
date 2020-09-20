
void    ft_backtrack(int **grid, int row, int col, int remain, int *counter, int nrows, int ncols)
{
    int temp;
    int next_row;
    int next_col;
    int i;
   
    if (grid[row][col] == 2 && remain == 1)
    {
        *counter += 1;
        return ;
    }
    temp = grid[row][col];
    grid[row][col] = -4;
    remain -= 1;
    i = 0;
    while (i < 4)
    {
        if (i == 0)
            next_row = row + 1;
        else if (i == 1)
            next_row = row - 1;
        else if (i == 2)
            next_col = col + 1;
        else if (i == 3)
            next_col = col  -1;
        if ((next_row >= 0 && next_row < nrows && next_col >= 0 && next_col < ncols) && (grid[next_row][next_col] >= 0))
//            if (grid[next_row][next_col] >= 0)
                ft_backtrack(grid, next_row, next_col, remain, counter, nrows, ncols);
        i++;
    }
    grid[row][col] = temp;     
}

int     uniquePathsIII(int** grid, int gridSize, int* gridColSize)
{
    int paths;
    int free_cells;
    int nrows;
    int ncols;
    int start_row;
    int start_col;
    
    free_cells = 0;
    nrows = gridSize;
    ncols = *gridColSize;
    start_row = 0;
    start_col = 0;
    
    int i = 0;
    int j;
    while (i < nrows)
    {
        j = 0;
        while (j < ncols)
        {
            if (grid[i][j] >= 0)
                free_cells += 1;
            if (grid[i][j] == 1)
            {
                start_row = i;
                start_col = j;
            }
            j++;
        }
        i++;        
    }
    paths = 0;
    ft_backtrack(grid, start_row, start_col, free_cells, &paths, nrows, ncols);
    return (paths);
}

