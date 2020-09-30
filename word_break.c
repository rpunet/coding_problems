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

//_--------------------- Backtrack Recursive with Memoization Solution O(n^2)--------------------------------------------_

int     *create_hash(int len)
{
    int *ret;
    int i;
    
    ret = malloc(sizeof(int) * len);
    i = 0;
    while (i < len)
        ret[i++] = 0;
    return (ret);
}

bool    backtrack(char *s, char **wordDict, int start, int wordDictSize, int slen, int i, int *hash)
{
    int j;
    
    j = 0;
    if (!*s)
        return (true);
    else if (hash[i] == 1)
        return (hash[i]);
    while (j < wordDictSize)
    {
        if (start == wordDictSize)
            start = 0;
        if (strncmp(s, wordDict[start], strlen(wordDict[start])) == 0)
            if (backtrack(s + strlen(wordDict[start]), wordDict, start, wordDictSize, slen, i + strlen(wordDict[start]), hash) == true)
            {
                hash[i] == 1;
                return (true);
            }
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
    int     *hash;
    
    slen = strlen(s);
    hash = create_hash(slen);
    i = 0;
    j = 0;
    while (j < wordDictSize)
    {
        if (backtrack(s, wordDict, j, wordDictSize, slen, i, hash) == true)
            return (true);
        j++;
    }
    return (false);
}
