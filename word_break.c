/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_break.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:03:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/09/19 19:36:31 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//_--------------------- Backtrack Recursive Solution O(n^2)--------------------------------------------_

bool    backtrack(char *s, char **wordDict, int start, int wordDictSize, int slen)
{
    int j; 
    
    j = 0;
    if (!*s)
        return (true);
    while (j < wordDictSize)
    {
        if (start == wordDictSize)
            start = 0;
        if (strncmp(s, wordDict[start], strlen(wordDict[start])) == 0)
            if (backtrack(s + strlen(wordDict[start]), wordDict, start, wordDictSize, slen) == true)
                return (true);
        start++;
       
        j++; 
    }
    return (false);
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize)
{
    int     i;
    int     j;
    int     slen;
    char    *temp;

    temp = s;
    slen = strlen(s);
    i = 0;
    while (i < wordDictSize)
    {
        if (backtrack(s, wordDict, i, wordDictSize, slen) == true)
            return (true);
        i++;
    }
    return (false);
}
