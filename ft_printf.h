/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:26:12 by jna               #+#    #+#             */
/*   Updated: 2021/02/05 15:03:43 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_field
{
	char	s_flag;
	int		s_width;
	int		s_precision;
	char	s_type;
}				t_field;

size_t			ft_strlen(const char *s);

void			ft_putnbr_signed(int n);
void			ft_putnbr_unsigned(unsigned long n, char type);

int				get_digit(int n);
int				get_digit_unsigned(unsigned long num, unsigned int notation);

void			setting_option(t_field *opt);
int				get_output_size_precision(t_field *opt, int length);
int				get_output_size_width(int *width, int length);
int				apply_precision(t_field *opt, int length);
int				apply_width(t_field *opt, int length);

int				print_character(t_field *fields, char c);
int				print_string(t_field *fields, char *s);
int				print_pointer(t_field *fields, unsigned long u_num);
int				print_signed_int(t_field *fields, int num);
int				print_unsigned_int(t_field *fields, unsigned int u_num);

int				set_num(int *dst, const char *format, va_list *ap);
int				find_flag_and_set(const char *format, char *flag);
int				find_width_and_set(const char *format, int *width, va_list *ap);
int				find_precision_and_set(const char *format, int *pre, va_list *ap);
int				find_type_and_set(const char *format, char *type);

int				ft_printf(const char *format, ...);

#endif
