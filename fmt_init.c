/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/24 13:27:16 by omulder        #+#    #+#                */
/*   Updated: 2019/02/25 13:37:01 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct state;
typedef void state_fn(struct state *, const char *format);

typedef struct	s_state
{
	state_fn *next;
	t_fmt fmt;
}				t_state;

void	fmt_set(t_state *state, const char *format)
{
	
}

void	fmt_param(t_state *state, const char *format)
{

}

void	fmt_opt(t_state *state, const char *format)
{
    printf("%s %i\n", __func__, ++state->i);
    state->next = state->i < 10 ? foo : 0;
}

void	fmt_width(t_state *state, const char *format)
{
    printf("%s %i\n", __func__, ++state->i);
    state->next = bar;
}

void	fmt_wild(t_state *state, const char *format)
{

}

void	fmt_prec(t_state *state, const char *format)
{
    printf("%s %i\n", __func__, ++state->i);
    state->next = state->i < 10 ? foo : 0;
}

void	fmt_len(t_state *state, const char *format)
{
    printf("%s %i\n", __func__, ++state->i);
    state->next = state->i < 10 ? foo : 0;
}

void	fmt_conv(t_state *state, const char *format)
{
    printf("%s %i\n", __func__, ++state->i);
    state->next = state->i < 10 ? foo : 0;
}


t_fmt	fmt_init(t_fmt fmt, const char **format, va_list ap)
{
	const t_state state = { fmt_set, fmt };
	while (state.next)
	{
		state.next(&state, *format);
	}
}