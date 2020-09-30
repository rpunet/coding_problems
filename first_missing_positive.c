/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_missing_positive.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:03:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/09/19 19:36:31 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    ft_abs(int a)
{
    if (a < 0)
        return -a;
    return a;
}

int firstMissingPositive(int* nums, int numsSize)
{
    int i;
    int out;
    
    i = 0;
    out = 0;
    while (i < numsSize)
    {
        if (nums[i] > 0 && nums[i] <= numsSize)
        {
            out = nums[i];
            break;
        }
        i++;
    }
    i = 0;
    while (i < numsSize)
    {
        if (nums[i] <= 0 || nums[i] > numsSize)
            nums[i] = out;
        i++;
    }
    i = 0;
    while (i < numsSize)
    {
        if (nums[i] != 0)
            if (nums[ft_abs(nums[i]) - 1] > 0)
                nums[ft_abs(nums[i]) - 1] *= -1;
        i++;
    }
    i = 0;
    while (i < numsSize)
    {
        if (nums[i] >= 0)
            return (i + 1);
        i++;
    }
    return (i + 1);
}
