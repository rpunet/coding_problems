/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:22:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/07/27 22:07:16 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * ((int)ft_strlen(s1) + (int)ft_strlen(s2)) + 1);
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

static int	ft_dec_count(unsigned int ncpy, int lng)
{
	while (ncpy >= 10)
	{
		ncpy /= 10;
		lng++;
	}
	return (lng);
}

char		*ft_itoa(long int n)
{
	long int		nbr;
	int				len;
	char			*itoa;
	int				sign;

	sign = (n < 0) ? 1 : 0;
	nbr = (n < 0) ? -n : n;
	len = ft_dec_count(nbr, 1);
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

static char	*ft_hourtoa(int h)
{
	int		hrs;
	int		mins;
	char	*itoamins;
	char	*itoahrs;
	char	*h_str;
	char	*m_str;
	char	*ret1;
	char	*ret2;

	hrs = h / 60;
	mins = h % 60;
	itoamins = ft_itoa(mins);
	m_str = mins < 10 ? ft_strjoin("0", itoamins) : itoamins;
	itoahrs = ft_itoa(hrs);
	if (hrs < 10)
		h_str = ft_strjoin("0", itoahrs);
	else
		h_str = itoahrs;
	ret1 = ft_strjoin(h_str, ":");
	ret2 = ft_strjoin(ret1, m_str);

    free(m_str);
    free(h_str);
    free(ret1);

	
	return (ret2);
}

static int	heap_algorithm_min(int *A, int h)
{
	int		i;
	int		minute;
	int		ret;
	int		max;

	ret = -2147483648;
	i = 2;
	while (i < 4)
	{
		ft_swap(&A[2], &A[i]);
		minute = A[2]*10 + A[3];
		if (minute < 60)
		{
			max = h*60 + minute;
			ret = ft_max(ret, max);
		}
		ft_swap(&A[2], &A[i]);
		i++;
	}
	return (ret);
}

static int	heap_algorithm_hour(int* A)
{
	int		i;
	int		j;
	int		hour;
	int		ret;

	i = 0;
	j = 1;
	ret = -2147483648;
	while (i < 4)
	{
		ft_swap(&A[0], &A[i]);
		while (j < 4)
		{
			ft_swap(&A[1], &A[j]);
			hour = A[0]*10 + A[1];
			if (hour < 24)
				ret = ft_max(ret, heap_algorithm_min(A, hour));
			ft_swap(&A[1], &A[j]);
			j++;
		}
		ft_swap(&A[0], &A[i]);
		j = 1;
		i++;
	}
	return (ret);
}

char 		*largestTimeFromDigits(int* A, int ASize)
{
	int		nb;
	char	*ret;

	if (ASize != 4)
		return (0);
	nb = heap_algorithm_hour(A);
	if (nb == -2147483648)
	{
		if (!(ret = (char*)malloc(sizeof(char) * 1)))
			return (0);
		ret[0] = (char)NULL;
	}
	else
		ret = ft_hourtoa(nb);
	return (ret);
}
