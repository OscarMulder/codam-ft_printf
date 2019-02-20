/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/05 07:43:01 by omulder        #+#    #+#                */
/*   Updated: 2019/02/20 14:34:27 by omulder       ########   odam.nl         */
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
t_fmt			find_conversion(const char **format, t_fmt fmt);
t_fmt			find_length(const char **format, t_fmt fmt);
t_fmt			find_precision(const char **format, t_fmt fmt);
t_fmt			find_width(const char **format, t_fmt fmt);
t_fmt			find_options(const char **format, t_fmt fmt);
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
int				print_var(t_fmt fmt, va_list ap);
void			ft_putnnbr(int n, int len);
int				ft_rputchar(int c);
int				print_padding(char c, int size);
void			find_escape(const char **format, t_fmt *fmt);
int				print_int(t_fmt fmt, int num);
int				print_char(t_fmt fmt, unsigned int c);
int				print_charp(t_fmt fmt, char *str);
void			ft_putnbr_base(int n, int base, int up);
void			ft_putlong_base(long long n, int base, int up);;
int				ft_longlen(long long n, int base);
int				print_long(t_fmt fmt, long long num);
int				print_prehex(int hash, char c);
int				is_unsigned(char c);
void			ft_putulong_base(unsigned long long n, int base, int up);
void			ft_putunbr_base(unsigned int n, int base, int up);
int				ft_ulonglen(unsigned long long n, int base);
int				ft_uintlen(unsigned int n, int base);
int				print_uint(t_fmt fmt, unsigned int num);
int				print_ulong(t_fmt fmt, unsigned long long num);
int				is_short(int l);
void			ft_putcharsign(int c);
int				is_charsign(char c, int l);
int				print_short(t_fmt fmt, short num);
void			ft_putshort(int c);
int				print_charsign(t_fmt fmt, signed char num);
int      		is_hex(char c, int l);
int				printed_chars(t_fmt fmt, long long num);
int				printed_uchars(t_fmt fmt, unsigned long long num);
void			put_backpadding(t_fmt fmt, long long num, int ilen);
void			put_paddingandsign(t_fmt fmt, long long num, int ilen);
void			put_upaddingandsign(t_fmt fmt, unsigned long long num, int ilen);
double			ft_pow(double x, double y);
int				print_double(t_fmt fmt, double num);
int				is_option(char c);
t_fmt  			reset_fmt(t_fmt fmt);
t_fmt			check_format(t_fmt fmt, const char **format);
int				print_pointer(t_fmt fmt, unsigned long long num);
void			ft_putwstr(wchar_t const *s);
void			ft_putnwstr(wchar_t const *s, size_t len);
size_t			ft_wstrlen(const wchar_t *s, int prec);
int				print_wcharp(t_fmt fmt, wchar_t *str);
int				is_ushort(t_fmt fmt);
int				print_ushort(t_fmt fmt, short num);
void			ft_putushort_base(unsigned short n, int base, int up);
int				is_uchar(t_fmt fmt);
int				ft_ucharlen(unsigned char n, int base);
void			ft_putuchar_base(unsigned char n, int base, int up);
int				print_uchar(t_fmt fmt, unsigned char num);

#endif
