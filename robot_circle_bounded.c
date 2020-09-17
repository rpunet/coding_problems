/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   robot_circle_bounded.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 08:45:27 by rpunet            #+#    #+#             */
/*   Updated: 2020/09/17 09:50:33 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    go_robot(int *pos, int dir)
{
    if (dir == 1)
        pos[1]++;
    if (dir == 2)
        pos[0]++;
    if (dir == 3)
        pos[1]--;
    if (dir == 4)
        pos[0]--;
}

bool isRobotBounded(char *instruction)
{  
    int dir;
    int pos[2] = {0,0};
    
    dir = 1;
    while (*instruction)
    {
        if (*instruction == 'L')
        {
            dir--;
            if (dir == 0)
                dir = 4;
        }
        if (*instruction == 'R')
        {
            dir++;
            if (dir == 5)
                dir = 1;
        }
        if (*instruction == 'G')
            go_robot(pos, dir);
        instruction++;
    }
    if ((pos[0] == 0 && pos[1] == 0) || dir != 1)
        return (true);
    return (false);
}
