/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bigx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: UTurkey <uturkey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:04:48 by UTurkey           #+#    #+#             */
/*   Updated: 2020/07/26 11:05:39 by UTurkey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_x_ch(unsigned int n)
{
	char	sym;

	if (n < 10)
		sym = '0' + n;
	else
		sym = 'A' + (n - 10);
	write(1, &sym, 1);
}

static void	flag_loc(int *rez, t_printf_format s_format, int *def_dot, int sym)
{
	if (!s_format.pres_dot && sym == 0 && s_format.set_dot)
		(*rez)--;
	if (s_format.set_dot)
		s_format.zero = ' ';
	*def_dot = 0;
	if (*rez < s_format.pres_dot)
		*def_dot = s_format.pres_dot - *rez;
	if (s_format.is_octo && sym)
		(*rez) += 2;
	if (s_format.is_octo && s_format.num >= 2)
		s_format.num -= 2;
	if (s_format.zero == ' ')
		*rez = *rez + char_repeat(s_format.zero, s_format.num - *rez -
				*def_dot);
	if (s_format.is_octo && sym)
		write(1, "0X", 2);
	if (s_format.zero == '0')
		*rez = *rez + char_repeat(s_format.zero, s_format.num - *rez -
				*def_dot);
	if (*def_dot)
		*rez = *rez + char_repeat('0', *def_dot);
	if (s_format.pres_dot || sym != 0 || !s_format.set_dot)
		print_x_ch(sym);
}

static int	nbr_x(unsigned int n, int rez, t_printf_format s_format)
{
	int	step;
	int	bef_dot;
	int	sym;

	step = n / 16;
	rez++;
	sym = n % 16;
	if (step > 0)
	{
		rez = nbr_x(step, rez, s_format);
		print_x_ch(sym);
	}
	else
		flag_loc(&rez, s_format, &bef_dot, sym);
	return (rez);
}

int			print_bigx(unsigned int n, t_printf_format s_format)
{
	int	rez;

	if (s_format.is_octo && s_format.num > 0)
		s_format.num += 2;
	rez = nbr_x(n, 0, s_format);
	rez = rez + char_repeat(' ', (s_format.num * -1) - rez);
	return (rez);
}
