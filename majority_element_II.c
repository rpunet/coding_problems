/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   majority_element_II.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:22:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/07/27 22:07:16 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int* majorityElement(int* nums, int numsSize, int* returnSize)
{
    int *ret;
    int count1;
    int count2;
    int i;
    
    *returnSize = 0;
    ret =  malloc(sizeof(int) * 2);
    count1 = 0;
    count2 = 0;
    i = 0;
    while (i < numsSize)
    {
        if (count1 == 0 && nums[i] != ret[1])
            ret[0] = nums[i];
        if (count2 == 0 && nums[i] != ret[0])
            ret[1] = nums[i];
        if (nums[i] == ret[0])
            count1++;
        else if (nums[i] == ret[1])
            count2++;
        if (nums[i] != ret[0] && nums[i] != ret[1])
        {
            count1--;
            count2--;
        }
        i++;
    }
    i = 0;
    count1 = 0;
    count2 = 0;
    while (i < numsSize)
    {
        if (ret[0] == nums[i])
            count1++;
        else if (ret[1] == nums[i])
            count2++;
        i++;
    }
    if (count1 > (numsSize / 3))
        ret[(*returnSize)++] = ret[0];
    if (count2 > (numsSize / 3))
        ret[(*returnSize)++] = ret[1];
    return (ret);            
}
