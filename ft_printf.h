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
#include <limits.h>

typedef struct _Field
{
	char	_flag;
	int		_width;
	int		_precision;
	char	_type;
} Field;

int		ft_printf(const char *format, ...);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_signed(int n);
void	ft_putnbr_unsigned(unsigned int n, char type);
int		print_signed_int(int num, int value, int w, char c));
int		print_unsigned_int(unsigned int num, char type, int value, int w, char c));
int		get_digit(int n);
int		get_digit_unsigned(unsigned int num, unsigned int notation);
int		precision(int option, int length, char type);
int		width(int option, int length, char c);

#endif