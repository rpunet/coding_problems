/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 13:43:35 by rpunet            #+#    #+#             */
/*   Updated: 2020/09/25 18:25:21 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_count_digit(int num)
{
	int count;

	count = 1;
	while (num >= 10)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	unsigned int	nbr;
	int				len;
	char			*itoa;
	int				sign;

	sign = (n < 0) ? 1 : 0;
	nbr = (n < 0) ? (unsigned int)-n : (unsigned int)n;
	len = ft_count_digit(nbr);
	len += sign;
	if (!(itoa = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	itoa[len] = '\0';
	while (len-- > sign)
	{
		itoa[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign == 1)
		itoa[0] = '-';
	return (itoa);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ret)
		return (NULL);
	while (*s1)
	{
		ret[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		ret[i] = *s2;
		i++;
		s2++;
	}
	ret[i] = '\0';
	return (ret);
}

int		ft_pow(int a, int exp)
{
	int ret;

	ret = 1;
	while (exp-- > 0)
		ret *= a;
	return (ret);
}

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort(int *nums, int size)
{
	int i;
	int j;
	int temp_i;
	int temp_j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (ft_count_digit(nums[i]) != ft_count_digit(nums[j]))
			{
				temp_i = nums[i] * ft_pow(10, ft_count_digit(nums[j])) + nums[j];
				temp_j = nums[j] * ft_pow(10, ft_count_digit(nums[i])) + nums[i];
				if (temp_j < temp_i)
					ft_swap(&nums[j], &nums[i]);
			}
			else
			{
				if (nums[j] < nums[i])
					ft_swap(&nums[j], &nums[i]);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

char *largestNumber(int* nums, int numsSize)
{
	int		i;
	char    *ret;
	char	*temp_itoa;
	char	*free_temp;
	int		zeroes;

	ft_sort(nums, numsSize);
	i = 0;
	zeroes = 0;
	while (i < numsSize)
	{
		if (nums[i] == 0)
			zeroes += 1;
		if (i == 0)
			ret = ft_itoa(nums[i]);
		else
		{
			temp_itoa = ft_itoa(nums[i]);
			free_temp = ret;
			ret = ft_strjoin(ret, temp_itoa);
			free(free_temp);
			free(temp_itoa);
		}
		i++;
	}
	if (zeroes == numsSize)
	{
		free(ret);
		return ("0");
	}
	return (ret);
}

/*

int		main(void)
{
	int	nums[2] = {0,0};
	int nums2[2] = {121,12};


	char *res = largestNumber(nums, 2);
	char *res2 = largestNumber(nums2, 2);
	printf("%s\n %s", res, res2);
	// free(res);
	// free(res2);
	return (0);
}

*/
