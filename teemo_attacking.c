/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teemo_attacking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:22:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/07/27 22:07:16 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_min(int a, int b)
{
    if (a < b)
        return (a);
    return (b);
}

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration)
{
    int i;
    int tot;
    
    if (timeSeriesSize == 0)
        return (0);
    i = -1;
    tot = 0;
    while (++i < (timeSeriesSize - 1))
        tot += ft_min(timeSeries[i + 1] - timeSeries[i], duration);
    return (tot + duration);
}
