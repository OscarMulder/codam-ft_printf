/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/05 07:43:01 by omulder        #+#    #+#                */
/*   Updated: 2019/02/07 16:31:17 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <libft.h>

typedef struct s_fmt 
{
	int		opt[6];
	int 	width;
	int		prec;
	int		length;
	char	conv;
}				t_fmt;

int		ft_printf(const char *format, ...);
int		ft_rputstr(char const *s);
int		ft_rputnbr(int n);
void	debug_printfmt(t_fmt *fmt);
t_fmt	*check_format(const char **format);
void	find_conversion(const char **format, t_fmt *fmt);
void	find_length(const char **format, t_fmt *fmt);
void	find_precision(const char **format, t_fmt *fmt);
void	find_width(const char **format, t_fmt *fmt);
void	find_options(const char **format, t_fmt *fmt);
t_fmt	*new_fmt(void);
int		is_length(char c);
int		is_conversion(char c);
int		is_flag(char c);
int		is_int(char c);
int 	is_double(char c);
int		is_char(char c);
int		is_charp(char c);
int		is_voidp(char c);
int		is_longint(char c);
int		is_wcharp(char c, int l);
int		print_var(t_fmt *fmt, va_list ap);
void	ft_putnnbr(int n, int len);

#endif