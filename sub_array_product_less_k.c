/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_array_product_less_k.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:03:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/09/19 19:36:31 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int numSubarrayProductLessThanK(int* nums, int numsSize, int k)
{
    int prod;
    int count;
    int i;
    int j;
   
    if (k == 0)
        return (0);
    prod = 1;
    count = 0;
    i = 0;
    j = 0;
    while (j < numsSize)
    {
        prod *= nums[j];
        while (prod >= k && i <= j)
        {
            prod = prod / nums[i];
            i++;
        }
        j++;
        count += j - i;
    }
    return (count);
}
