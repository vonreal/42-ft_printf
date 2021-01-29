/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:18:16 by jna               #+#    #+#             */
/*   Updated: 2021/01/29 23:18:16 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		precision(int option, int length, char type)
{
    int         temp;

	if (type == 's')
	{
		if (option == 0)
			return (0);
		else if (option > 0 && option <= length)
			return (option);
	}
    else
    {
        if ((option -= length) > 0)
        {
            temp = option;
            while (temp-- > 0)
                write(1, "0", sizeof(char));
            return (option);
        }
    }
    return (length);
}

int		width(int option, int length, char c)
{
	int		temp;

	if ((option -= length) > 0)
	{
		temp = option;
		while (temp-- > 0)
		{
			if (c == '0')
				write(1, '0', sizeof(char));
			else
				write(1, ' ', sizeof(char));
		}
		return (option);
	}
	return (0);
}
