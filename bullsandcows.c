/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullsandcows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:22:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/07/27 22:07:16 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char * getHint(char * secret, char * guess)
{
    int i = 0;
    int a = 0;
    int b = 0;
    
    int len = strlen(secret);
    int hash[10] = {0}; 
    
    while (i < len)
    {
        hash[secret[i] - '0'] += 1;
        if (secret[i] == guess[i])
            a += 1;
        i++;
    }
    i = 0;
    while (i < len)
    {
        if (hash[guess[i] - '0'])
        {
            b += 1;
            hash[guess[i] - '0'] -= 1;
        }
        i++;
    }
    b = b - a;
    i = 1;
    int j = 1;
    int bull = a;
    int cow = b;
    while (a > 9)
    {
        a = a / 10;
        i++;
    }
    while (b > 9)
    {
        b = b / 10;
        j++;
    }
    char *ret;
    if (!(ret = (char *)malloc(sizeof(char) * (i + j + 3))))
        return (0);
    *(ret + i) = 'A';
    int i2 = i;
    i -= 1;
    while (i >= 0)
    {
        *(ret + i) = bull % 10 + '0';
        bull /= 10;
        i--;
    }
    *(ret + j + i2  + 1) = 'B';
    int j2 = j;
    j -= 1;
    while (j >= 0)
    {
        *(ret + i2 + j + 1) = cow % 10 + '0';
        cow /= 10;
        j--;
    }
    *(ret + i2 + j2 + 2) = '\0';
    return (ret);
}
