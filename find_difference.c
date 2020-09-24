  
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_difference.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:03:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/09/19 19:36:31 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char findTheDifference(char * s, char * t)
{
    char    letters[26];
    int     i;
    
    i = 0;
    while (i < 26)
        letters[i++] = 0;
    i = 0;
    while (s[i])
        letters[s[i++] - 97] += 1;
    i = 0;
    while (t[i])
    {
        letters[t[i] - 97] -= 1;
        if (letters[t[i] - 97] < 0)
            return (t[i]);
        i++;
    }
    return (0);
}

/*
//_------------------------- SOLUTION 2 (USING XOR) ---------------------------_

char findTheDifference(char * s, char * t)
{
    int     i;
    char    res = 0;
    
    i = 0;
    while (s[i])
        res = res ^ s[i++]; 
    i = 0;
    while (t[i])
        res = res ^ t[i++];
    return (res);
}

*/
