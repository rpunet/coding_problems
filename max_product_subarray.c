/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_product_subarray.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:22:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/07/27 22:07:16 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long		ft_max(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}

int maxProduct(int* nums, int numsSize)
{
    int i = 0;
    long max;
    long start = 1;
    long end = 1;
    long temp;
    
    i = 0;
    max = INT_MIN;
    while (i < numsSize)
    {
        start = start * nums[i];
        end = end * nums[numsSize - 1 - i];
        temp = ft_max(start, end);
        max = ft_max(max, temp);
        if (nums[i] == 0)
            start = 1;
        if (nums[numsSize -1 - i] == 0)
            end = 1;
        i++;
    }
    return (max);
}
