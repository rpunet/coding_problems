/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeated_substring.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:22:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/07/27 22:07:16 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    get_subs(char *s, int n, int *subs)
{
    int len = 0;
    int i;
    
    subs[0] = 0;
    i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            subs[i] = len;
            i++;
        }
        else
        {
            if (len > 0)
                len = subs[len - 1];
            else if (len == 0)
            {
                subs[i] = 0;
                i++;
            }
        }
    }
}
bool repeatedSubstringPattern(char * s)
{
    int n = strlen(s);
    int subs[n];
    
    get_subs(s, n, subs);
    int len;
    len = subs[n - 1];
    if (len > 0 && (n % (n - len) == 0))
        return (true);
    else
        return (false);
    
}
