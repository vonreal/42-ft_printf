/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:56:12 by jna               #+#    #+#             */
/*   Updated: 2021/01/29 18:56:12 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	count;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	count = 0;
	while (count < len)
	{
		ptr[count] = (unsigned char)c;
		count++;
	}
	return (b);
}

size_t		ft_strlen(const char *s)
{
	unsigned int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}
