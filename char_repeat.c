/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_repeat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: UTurkey <uturkey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 18:59:29 by UTurkey           #+#    #+#             */
/*   Updated: 2020/07/25 22:16:15 by UTurkey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		char_repeat(char c, int num)
{
	int	step;

	step = 0;
	while (step < num)
	{
		write(1, &c, 1);
		step++;
	}
	return (step);
}
