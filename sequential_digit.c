/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequential_digits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:03:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/09/19 19:36:31 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort(int *res, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (res[j] > res[i])
				ft_swap(&res[j], &res[i]);
			j++;
		}
		j = 0;
		i++;
	}
}

/* 
//_------------------------QUICK-SORT ALGORITHM------------------------------------------_

int		ft_partition(int *items, int left, int right)
{
	int pivot;
	int	l;
	int	r;

	l = left;
	r = right;
	pivot = items[(r + l) / 2];
	while (l <= r)
	{
		while (items[l] < pivot)
			l++;
		while (items[r] > pivot)
			r--;
		if (l <= r)
		{
			ft_swap(&items[l], &items[r]);
			l++;
			r--;
		}
	}
	return (l);
}

void	ft_quick_sort(int *items, int left_index, int right_index)
{
	int	pivot;

	if ((right_index - left_index) >= 1)
	{
		pivot = ft_partition(items, left_index, right_index);
		if (left_index < pivot - 1)
			ft_quick_sort(items, left_index, pivot - 1);
		if (pivot < right_index)
			ft_quick_sort(items, pivot, right_index);
	}
}
//-------------------------------------------------------------------------------------------------
*/

int		*sequentialDigits(int low, int high, int *returnSize)
{
	int	*res;
	int	num;
	int	digit;
	int	next;
	int i;

	digit = 1;
	i = 0;
	while (digit < 10)
	{
		num = digit;
		next = digit;
		while (num <= high && next < 10)
		{
			if (num >= low)
				i++;
			next += 1;
			num = num * 10 + next;
		}
		digit++;
	}
	*returnSize = i;
	res = malloc(sizeof(int) * i);

	digit = 1;
	i = 0;
	while (digit < 10)
	{
		num = digit;
		next = digit;
		while (num <= high && next < 10)
		{
			if (num >= low)
				res[i++] = num;
			next += 1;
			num = num * 10 + next;
		}
		digit++;
	}
	//_--------------------------- TWO SORT SOLUTIONS -----------------------_
	ft_sort(res, *returnSize);				
	//ft_quick_sort(res, 0, *returnSize - 1);
	//_----------------------------------------------------------------------_
	return (res);
}

/*
int	main(void)
{
	int	*seq;
	int	returnSize = 0;
	int	low = 1000;
	int	high = 13000;

	seq = sequentialDigits(low, high, &returnSize);

	printf("[");
	int	i = 0;

	while (i < returnSize - 1)
	{
		printf("%d,", seq[i]);
		i++;
	}
	printf("%d", seq[i]);
	printf("]\n");
	return (0);
}
*/
