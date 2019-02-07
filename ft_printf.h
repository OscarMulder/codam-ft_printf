/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/05 07:43:01 by omulder        #+#    #+#                */
/*   Updated: 2019/02/07 12:14:54 by omulder       ########   odam.nl         */
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
	char	opt[7];
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

#endif