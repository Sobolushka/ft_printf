/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: UTurkey <uturkey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:05:10 by UTurkey           #+#    #+#             */
/*   Updated: 2020/07/27 00:26:12 by UTurkey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_s_ch(char c)
{
	write(1, &c, 1);
}

static void	flag_loc(int *rez, t_printf_format s_format, int *bef_dot, char sym)
{
	if (!s_format.pres_dot && sym == '\0' && s_format.set_dot)
		(*rez)--;
	if (s_format.set_dot)
		s_format.zero = ' ';
	*bef_dot = 0;
	if (s_format.zero == ' ')
		*rez = *rez + char_repeat(s_format.zero, s_format.num - *rez -
				*bef_dot);
	if (s_format.pres_dot || sym != '\0' || !s_format.set_dot)
		print_s_ch(sym);
}

static int	nbr_s(const char *str, int rez, int len, t_printf_format s_format)
{
	int		bef_dot;
	char	sym;

	len = len - 1;
	rez++;
	sym = str[len];
	if (len > 0)
	{
		rez = nbr_s(str, rez, len, s_format);
		print_s_ch(sym);
	}
	else
		flag_loc(&rez, s_format, &bef_dot, sym);
	return (rez);
}

int			print_s(const char *str, t_printf_format s_format)
{
	int		rez;
	int		bif;

	if (str == NULL)
		str = "(null)";
	if (*str == '\0')
	{
		return (s_format.num < 0) ? (rez = char_repeat(' ',
			(s_format.num * -1))) : (rez = char_repeat(' ', (s_format.num)));
	}
	bif = ft_strlen(str);
	if (s_format.pres_dot < bif && s_format.set_dot == 1)
		bif = s_format.pres_dot;
	rez = nbr_s(str, 0, bif, s_format);
	rez = rez + char_repeat(' ', (s_format.num * -1) - rez);
	return (rez);
}
