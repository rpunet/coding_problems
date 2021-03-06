 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique_paths_III.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:03:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/09/19 19:36:31 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    grid[row][col] = -1;
    remain -= 1;
    i = 0;
    next_row = row;
    next_col = col;
    while (i < 4)
    {
        if (i == 0)
            next_row++;
        else if (i == 1)
            next_row--;
        else if (i == 2)
            next_col++;
        else if (i == 3)
            next_col--;
        if (next_row >= 0 && next_row < nrows && next_col >= 0 && next_col < ncols && grid[next_row][next_col] >= 0)
                ft_backtrack(grid, next_row, next_col, remain, counter, nrows, ncols);
        i++;
        next_row = row;
        next_col = col;
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
