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

//_---------- OPTION 1 O(n) ------------------_//

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

//_---------- OPTION 2 O(n) FASTER SOLUTION ------------------_//
/*
bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity)
{
    int trip_cap[1001];
    int i;
    int passengers;
    
    i = 0;
    while (i < 1001)
        trip_cap[i++] = 0;
    i = 0;
    while (i < tripsSize)
    {
        trip_cap[trips[i][1]] += trips[i][0];
        trip_cap[trips[i][2]] -= trips[i][0];
        i++;
    }
    i = 0;
    passengers = 0;
    while (i < 1001)
    {
        passengers += trip_cap[i];
        if (passengers > capacity)
                return (false);
        i++;
    }
    return (true);
}
*/
