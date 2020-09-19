/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequential_digits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:03:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/09/19 12:55:37 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
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
	ft_sort(res, *returnSize);
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
