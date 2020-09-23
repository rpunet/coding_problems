/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gas_station.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:03:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/09/19 19:36:31 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
    int i;
    int start;
    int tank;
    int total;

    i = 0;
    start = 0;
    tank = 0;
    total = 0;
    while (i < gasSize)
    {   
        total += gas[i] - cost[i];
        tank += gas[i] - cost[i];
        if (tank < 0)
        {
            tank = 0;
            start = i + 1;
        }
        i++;
    }
    return (total < 0 ? -1 : start);
}
