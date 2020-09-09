/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   version_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:22:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/07/27 22:07:16 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int compareVersion(char * version1, char * version2)
{
    int i = 0;
    int j = 0;
    int num1 = 0;
    int num2 = 0;
    
    while (version1[i] || version2[j])
    {
        while (version1[i] != '.' && version1[i] != '\0')
        {
            num1 = 10 * num1 + version1[i] - '0';
            i++;
        }
        while (version2[j] != '.' && version2[j] != '\0')
        {
            num2 = 10 * num2 + version2[j] - '0';
            j++;
        }
        if (num1 > num2)
                return (1);
        else if (num1 < num2)
                return (-1);
        num1 = 0;
        num2 = 0;
        if (version1[i] == '.')
            i++;
        if (version2[j] == '.')
            j++;
    }
    return (0);
}
