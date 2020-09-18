/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_buy_and_sell_stock.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 08:45:27 by rpunet            #+#    #+#             */
/*   Updated: 2020/09/17 09:50:33 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

int maxProfit(int* prices, int pricesSize)
{
    int i = 0;
    int min_price = 2147483647;
    int prof = 0;
    
    while (i < pricesSize - 1)
    {
        min_price = min(min_price, prices[i]);
        prof = max(prof, prices[i + 1] - min_price);
        i++;
    }
    return (prof);
}

// O(n2) nested loop solution
//_------------------------------------------------------------------------------------------------------------_//
/*
int maxProfit(int* prices, int pricesSize)
{
    int i, j;
    int prof;
    
    prof = 0;
    i = 0;
    while (i < pricesSize - 1)
    {
        j = i + 1;
        while (j < pricesSize)
        {
            prof = max(prof, (prices[j] - prices[i]));
            j++;
        }
        i++;        
    }
    return (prof);
}
*/
