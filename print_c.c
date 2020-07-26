/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: UTurkey <uturkey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:05:03 by UTurkey           #+#    #+#             */
/*   Updated: 2020/07/26 11:41:51 by UTurkey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_c(char c, t_printf_format s_format)
{
	int	rez;
	int	sym_add;

	rez = 1;
	sym_add = char_repeat(s_format.zero, s_format.num - rez);
	write(1, &c, rez);
	rez = rez + char_repeat(' ', (s_format.num * -1) - rez - sym_add);
	return (rez + sym_add);
}
