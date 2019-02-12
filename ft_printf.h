/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/05 07:43:01 by omulder        #+#    #+#                */
/*   Updated: 2019/02/12 15:11:11 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>

typedef struct	s_fmt
{
	int		opt[6];
	int		width;
	int		prec;
	int		length;
	char	conv;
}				t_fmt;

int				ft_printf(const char *format, ...);
int				ft_rputstr(char const *s);
int				ft_rputnbr(int n);
void			debug_printfmt(t_fmt *fmt);
t_fmt			*check_format(const char **format);
void			find_conversion(const char **format, t_fmt *fmt);
void			find_length(const char **format, t_fmt *fmt);
void			find_precision(const char **format, t_fmt *fmt);
void			find_width(const char **format, t_fmt *fmt);
void			find_options(const char **format, t_fmt *fmt);
t_fmt			*new_fmt(void);
int				find_case(char c);
int				find_base(char c);
int				is_length(char c);
int				is_conversion(char c);
int				is_flag(char c);
int				is_int(char c);
int				is_double(char c);
int				is_char(char c);
int				is_charp(char c);
int				is_voidp(char c);
int				is_longint(char c);
int				is_long(char c, int l);
int				is_wcharp(char c, int l);
int				print_var(t_fmt *fmt, va_list ap);
void			ft_putnnbr(int n, int len);
int				ft_rputchar(int c);
int				print_padding(char c, int size);
void			find_escape(const char **format, t_fmt *fmt);
int				print_int(t_fmt *fmt, int num);
int				print_char(t_fmt *fmt, int c);
int				print_charp(t_fmt *fmt, char *str);
void			ft_putnbr_base(int n, int base, int up);
void			ft_putlong_base(long long n, int base, int up);;
int				ft_longlen(long long n, int base);
int				print_long(t_fmt *fmt, long long num);
int				print_prehex(int hash, char c);
int				is_unsigned(char c);
void			ft_putulong_base(unsigned long long n, int base, int up);
void			ft_putunbr_base(unsigned int n, int base, int up);
int				ft_ulonglen(unsigned long long n, int base);
int				ft_uintlen(unsigned int n, int base);
int				print_uint(t_fmt *fmt, unsigned int num);
int				print_ulong(t_fmt *fmt, unsigned long long num);
int				is_short(int l);
void			ft_putcharsign(int c);
int				is_charsign(char c, int l);
int				print_short(t_fmt *fmt, short num);
void			ft_putshort(int c);
int				print_charsign(t_fmt *fmt, signed char num);

#endif
