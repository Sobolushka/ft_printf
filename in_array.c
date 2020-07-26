/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: UTurkey <uturkey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 20:44:56 by UTurkey           #+#    #+#             */
/*   Updated: 2020/07/25 22:15:25 by UTurkey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	in_array(char c, const char *arr)
{
	if (!arr)
		return (0);
	while (*arr)
		if (*(arr++) == c)
			return (1);
	return (0);
}
