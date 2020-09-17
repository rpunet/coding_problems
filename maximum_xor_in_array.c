/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maximum_xor_in_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 08:45:27 by rpunet            #+#    #+#             */
/*   Updated: 2020/09/17 09:50:33 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

typedef struct 	s_node
{
	struct s_node	*left;
	struct s_node	*right;
}				t_node;

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_pow(int a, int exp)
{
	int	ret;

	ret = 1;
	while (exp > 0)
	{
		ret *= a;
		exp--;
	}
	return (ret);
}

t_node	*new_node(void)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->left = NULL;
	new->right = NULL;
	return (new);
}

void	create_node(int num, t_node *head)
{
	int		temp;
	int		i;
	t_node	*trie_node;

	trie_node = head;
	i = 31;
	while (i >= 0)
	{
		temp = (num >> i) & 1;
		if (temp == 0)
		{
			if (!trie_node->left)
				trie_node->left = new_node();
			trie_node = trie_node->left;
		}
		else
		{
			if (!trie_node->right)
				trie_node->right = new_node();
			trie_node = trie_node->right;
		}
		i--;
	}
}

int		find_node(int num, t_node *head)
{
	int		temp;
	int		i;
	t_node	*trie_node;
	int		ret;

	trie_node = head;
	i = 31;
	ret = 0;
	while (i >= 0)
	{
		temp = (num >> i) & 1;
		if (temp == 0)
		{
			if (trie_node->right)
			{
				trie_node = trie_node->right;
				ret += ft_pow(2, i);
			}
			else
				trie_node = trie_node->left;

		}
		else
		{
			if (trie_node->left)
			{
				trie_node = trie_node->left;
				ret += ft_pow(2, i);
			}
			else
				trie_node = trie_node->right;
		}
		i--;
	}
	return (ret);
}

int		find_maximum_xor(int *nums, int numsSize)
{
	t_node	*head;
	int 	i;
	int		ret;

	head = new_node();

	i = 0;
	while (i < numsSize)
	{
		create_node(nums[i], head);
		i++;
	}
	i = 0;
	ret = 0;
	while (i < numsSize)
	{
		ret = ft_max(ret, find_node(nums[i], head));
		i++;
	}
	return (ret);
}

/*
int		main(void)
{
	int nums[3] = {25,5};
	printf("%d\n", find_maximum_xor(nums, 3));
	return (0);
}
*/

// O(n2) nested loop solution
//_------------------------------------------------------------------------------------------------------_//
/*
int ft_max(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

int findMaximumXOR(int* nums, int numsSize)
{
    int i;
    int j;
    int max;
    
    i = 0;
    j = 0;
    max = 0;
    while (i < numsSize - 1)
    {
        j = i + 1;
        while (j < numsSize)
        {
            max = ft_max(max, nums[i] ^ nums[j]);
            j++;
        }
        i++;
    }
    return (max);
}
*/
