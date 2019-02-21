/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/05 07:43:01 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 16:05:32 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# define HASH opt[0]
# define ZERO opt[1]
# define MIN opt[2]
# define SPACE opt[3]
# define PLUS opt[4]
# define APST opt[5]

typedef struct	s_fmt
{
	int		opt[6];
	int		width;
	int		prec;
	int		length;
	char	conv;
}				t_fmt;

double			ft_pow(double x, double y);
int				(*get_ulenfunc(t_fmt fmt))(unsigned long long, int);
int				find_base(t_fmt fmt);
int				find_case(t_fmt fmt);
int				ft_abs(int n);
int				ft_intlen(long long n, int base);
int				ft_longlen(long long n);
int				ft_printf(const char *format, ...);
int				ft_rputchar(int c);
int				ft_rputnbr(int n);
int				ft_rputstr(char const *s);
int				ft_ucharlen(unsigned long long n, int base);
int				ft_uintlen(unsigned long long n, int base);
int				ft_ulonglen(unsigned long long n, int base);
int				is_char(t_fmt fmt);
int				is_charp(t_fmt fmt);
int				is_charsign(t_fmt fmt);
int				is_conversion(char c);
int				is_double(t_fmt fmt);
int				is_flag(char c);
int				is_int(t_fmt fmt);
int				is_length(char c);
int				is_long(t_fmt fmt);
int				is_longint(t_fmt fmt);
int				is_octal(t_fmt fmt);
int				is_option(char c);
int				is_short(t_fmt fmt);
int				is_signed(t_fmt fmt);
int				is_uchar(t_fmt fmt);
int				is_uint(t_fmt fmt);
int				is_ulong(t_fmt fmt);
int				is_unsigned(t_fmt fmt);
int				is_ushort(t_fmt fmt);
int				is_voidp(t_fmt fmt);
int				is_wcharp(t_fmt fmt);
int				print_char(t_fmt fmt, unsigned int c);
int				print_charp(t_fmt fmt, char *str);
int				print_charsign(t_fmt fmt, signed char num);
int				print_double(t_fmt fmt, double num);
int				print_int(t_fmt fmt, int num);
int				print_long(t_fmt fmt, long long num);
int				print_padding(char c, int size);
int				print_pointer(t_fmt fmt, unsigned long long num);
int				print_prehex(t_fmt fmt);
int				print_short(t_fmt fmt, short num);
int				print_uchar(t_fmt fmt, unsigned char num);
int				print_uint(t_fmt fmt, unsigned int num);
int				print_ulong(t_fmt fmt, unsigned long long num);
int				print_ushort(t_fmt fmt, unsigned long long num);
int				print_var(t_fmt fmt, va_list ap);
int				print_wcharp(t_fmt fmt, wchar_t *str);
int				printed_chars(t_fmt fmt, long long num);
int				printed_uchars(t_fmt fmt, unsigned long long num);
int      		is_hex(char c, int l);
size_t			ft_wstrlen(const wchar_t *s, int prec);
t_fmt			*new_fmt(void);
t_fmt			check_format(t_fmt fmt, const char **format, va_list ap);
t_fmt			find_conversion(const char **format, t_fmt fmt);
t_fmt			find_length(const char **format, t_fmt fmt);
t_fmt			find_options(const char **format, t_fmt fmt);
t_fmt			find_precision(const char **format, t_fmt fmt, va_list ap);
t_fmt			find_width(const char **format, t_fmt fmt, va_list ap);
t_fmt  			reset_fmt(t_fmt fmt);
void			debug_printfmt(t_fmt fmt); //rm
void			find_escape(const char **format, t_fmt *fmt);
void			ft_putcharsign(long long c);
void			ft_putlong_base(long long n, int base, int up);;
void			ft_putnbr_base(int n, int base, int up);
void			ft_putnnbr(int n, int len);
void			ft_putnwstr(wchar_t const *s, size_t len);
void			ft_putshort(long long c);
void			ft_putuchar_base(unsigned long long n, int base, int up);
void			ft_putulong_base(unsigned long long n, int base, int up);
void			ft_putunbr_base(unsigned long long n, int base, int up);
void			ft_putushort_base(unsigned long long n, int base, int up);
void			ft_putwstr(wchar_t const *s);
void			put_backpadding(t_fmt fmt, long long num, int ilen);
void			put_paddingandsign(t_fmt fmt, long long num, int ilen);
void			put_upaddingandsign(t_fmt fmt, unsigned long long num, int ilen);
int				print_unsigned(t_fmt fmt, unsigned long long num);
int				print_signed(t_fmt fmt, long long num);

#endif
