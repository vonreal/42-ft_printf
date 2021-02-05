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

size_t		ft_strlen(const char *s);

void	ft_putnbr_signed(int n);
void	ft_putnbr_unsigned(unsigned long n, char type);

int		get_digit(int n);
int		get_digit_unsigned(unsigned long num, unsigned int notation);

void	setting_option(Field *opt);
int		get_precision(Field *opt, int length);
int		get_output_size_width(int *width, int length);
int		apply_precision(Field *opt, int length);
int		apply_width(Field *opt, int length);

int		print_character(Field *fields, char c);
int		print_string(Field *fields, char *s);
int		print_pointer(Field *fields, unsigned long u_num);
int		print_signed_int(Field *fields, int num);
int		print_unsigned_int(Field *fields, unsigned int u_num, char type);

int		set_num(int *dst, const char *format, va_list *ap);
int		find_flag_and_set(const char *format, char *flag);
int		find_width_and_set(const char *format, int *width, va_list *ap);
int		find_precision_and_set(const char *format, int *precision, va_list *ap);
int		find_type_and_set(const char *format, char *type);

int		ft_printf(const char *format, ...);

#endif