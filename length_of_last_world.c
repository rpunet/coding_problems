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

int lengthOfLastWord(char * s)
{
    int i;
    int space;
    
    space = 0;
    i = 0;
    while (*s)
    {
        if (*s != ' ')
        {
            if (space == 1)
            {
                space = 0;
                i = 0;
            }
            i++;
        }
        else
            space = 1;
        s++;
    }
    return (i);
}
