/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: UTurkey <uturkey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:05:57 by UTurkey           #+#    #+#             */
/*   Updated: 2020/07/26 18:26:30 by UTurkey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_u_ch(unsigned int n)
{
	char	sym;

	if (n < 10)
		sym = '0' + n;
	write(1, &sym, 1);
}

static void	flag_loc(int *rez, t_printf_format s_format,
						int *bef_dot, unsigned int sym)
{
	if (!s_format.pres_dot && sym == 0 && s_format.set_dot)
		(*rez)--;
	if (s_format.set_dot)
		s_format.zero = ' ';
	*bef_dot = 0;
	if (*rez < s_format.pres_dot)
		*bef_dot = s_format.pres_dot - *rez;
	if (s_format.zero == ' ')
		*rez = *rez + char_repeat(s_format.zero, s_format.num - *rez -
			*bef_dot);
	if (s_format.zero == '0')
		*rez = *rez + char_repeat(s_format.zero, s_format.num - *rez -
			*bef_dot);
	if (*bef_dot)
		*rez = *rez + char_repeat('0', *bef_dot);
	if (s_format.pres_dot || sym != 0 || !s_format.set_dot)
		print_u_ch(sym);
}

static int	nbr_u(unsigned int n, int rez, int bif, t_printf_format s_format)
{
	unsigned int	step;
	int	bef_dot;
	unsigned int	sym;

	step = n / 10;
	rez++;
	sym = n % 10;
	if (step > 0)
	{
		rez = nbr_u(step, rez, bif, s_format);
		print_u_ch(sym);
	}
	else
		flag_loc(&rez, s_format, &bef_dot, sym);
	return (rez);
}

int			print_u(unsigned int n, t_printf_format s_format)
{
	int	rez;

	rez = nbr_u(n, 0, 0, s_format);
	rez = rez + char_repeat(' ', (s_format.num * -1) - rez);
	return (rez);
}
