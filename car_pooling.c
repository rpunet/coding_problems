/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   car_pooling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:03:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/09/19 19:36:31 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity)
{
    int trip_cap[1001];
    int i;
    int pick;
    
    i = 0;
    while (i < 1001)
        trip_cap[i++] = 0;
    i = 0;
    while (i < tripsSize)
    {
        pick = trips[i][1];
        while (pick < trips[i][2])
        {
            trip_cap[pick] += trips[i][0];
            if (trip_cap[pick] > capacity)
                return (false);
            pick++;
        }
        i++;
    }
    return (true);
}
