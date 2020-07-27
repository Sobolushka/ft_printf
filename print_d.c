/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: UTurkey <uturkey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:05:10 by UTurkey           #+#    #+#             */
/*   Updated: 2020/07/27 15:42:18 by UTurkey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_d_ch(int n)
{
	char	sym;

	if (n < 10)
		sym = '0' + n;
	write(1, &sym, 1);
}

static void	flag_neg(int *rez, t_printf_format s_format, int *bef_dot, int sym)
{
	if (!s_format.pres_dot && sym == '0' && s_format.set_dot)
		(*rez)--;
	if (s_format.set_dot)
		s_format.zero = ' ';
	*bef_dot = 0;
	if (*rez < s_format.pres_dot)
		*bef_dot = s_format.pres_dot - *rez;
	if (s_format.zero == ' ')
		*rez = *rez + char_repeat(s_format.zero, s_format.num - *rez -
			*bef_dot - 1);
	write(1, "-", 1);
	if (s_format.zero == '0')
		*rez = *rez + char_repeat(s_format.zero, s_format.num - *rez -
				*bef_dot - 1);
	if (*bef_dot)
		*rez = *rez + char_repeat('0', *bef_dot);
	if (s_format.pres_dot || sym != '0' || !s_format.set_dot)
		print_d_ch(sym);
}

static void	flag_loc(int *rez, t_printf_format s_format, int *bef_dot, int sym)
{
	if (!s_format.pres_dot && sym == '0' && s_format.set_dot)
		(*rez)--;
	if (s_format.set_dot)
		s_format.zero = ' ';
	*bef_dot = 0;
	if (*rez < s_format.pres_dot)
		*bef_dot = s_format.pres_dot - *rez;
	if (s_format.zero == ' ')
		*rez = *rez + char_repeat(s_format.zero, s_format.num - *rez -
				*bef_dot);
	if (s_format.is_space == ' ')
	{
		write(1, " ", 1);
		rez--;
	}
	if (s_format.zero == '0')
		*rez = *rez + char_repeat(s_format.zero, s_format.num - *rez -
				*bef_dot);
	if (*bef_dot)
		*rez = *rez + char_repeat('0', *bef_dot);
	if (s_format.pres_dot || sym != '0' || !s_format.set_dot)
		print_d_ch(sym);
}

static int	nbr_d(int n, int rez, int bif, t_printf_format s_format)
{
	int	step;
	int	bef_dot;
	int	sym;

	step = n / 10;
	rez++;
	sym = n % 10;
	if (step > 0)
	{
		rez = nbr_d(step, rez, bif, s_format);
		print_d_ch(sym);
	}
	else
		(bif == 1) ? flag_neg(&rez, s_format, &bef_dot, sym) :
			flag_loc(&rez, s_format, &bef_dot, sym);
	return (rez);
}

int			print_d(int n, t_printf_format s_format)
{
	int		rez;
	int		kk;

	kk = (n == -2147483648) ? (1) : 0;
	rez = (n == -2147483648) ? (1) : 0;
	n = (n == -2147483648) ? (n / 10) : (n);
	if (s_format.set_dot == 1 && n == 0 && s_format.pres_dot == 0)
	{
		return (s_format.num < 0) ? (rez = char_repeat(' ',
			(s_format.num * -1))) : (rez = char_repeat(' ', (s_format.num)));
	}
	if (n < 0)
	{
		rez = nbr_d(n * (-1), 0, 1, s_format);
		s_format.num++;
		(kk == 1) ? (write(1, "8", 1)) : 0;
		rez = rez + char_repeat(' ', (s_format.num * -1) - rez);
	}
	else
	{
		rez = nbr_d(n, 0, 0, s_format);
		rez = rez + char_repeat(' ', (s_format.num * -1) - rez);
	}
	return (rez);
}
