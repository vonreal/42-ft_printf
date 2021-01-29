/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:26:12 by jna               #+#    #+#             */
/*   Updated: 2021/01/29 17:26:12 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd);

#endif