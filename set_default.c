/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: UTurkey <uturkey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:06:11 by UTurkey           #+#    #+#             */
/*   Updated: 2020/07/26 11:46:42 by UTurkey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_default(char *format_let, int *neg, t_printf_format *s_format)
{
	s_format->zero = ' ';
	s_format->add_plus = '\0';
	s_format->num = 0;
	s_format->set_dot = 0;
	s_format->pres_dot = 0;
	s_format->is_space = '\0';
	s_format->is_octo = '\0';
	*neg = 1;
	*format_let = '\0';
}
