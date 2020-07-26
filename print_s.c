/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: UTurkey <uturkey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:05:10 by UTurkey           #+#    #+#             */
/*   Updated: 2020/07/26 16:23:07 by UTurkey          ###   ########.fr       */
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
	if (*rez < s_format.pres_dot)
		*bef_dot = s_format.pres_dot - *rez;
	(*rez) += 2;
	if (s_format.zero == ' ')
		*rez = *rez + char_repeat(s_format.zero, s_format.num - *rez -
				*bef_dot);
	if (s_format.zero == '0')
		*rez = *rez + char_repeat(s_format.zero, s_format.num - *rez -
				*bef_dot);
	if (*bef_dot)
		*rez = *rez + char_repeat('0', *bef_dot);
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
	int	rez;

	if (str == NULL)
		str = "(null)";
	if (*str == '\0')
		return (rez = char_repeat(' ', (s_format.num * -1)));
	rez = nbr_s(str, 0, ft_strlen(str), s_format);
	rez = rez + char_repeat(' ', (s_format.num * -1) - rez);
	return (rez);
}
