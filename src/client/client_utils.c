/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:36:04 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/22 13:20:46 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *c)
{
	int	sign;
	int	number;

	sign = 1;
	number = 0;
	while (ft_isspace(*c))
		c++;
	if (*c == '+')
		c++;
	else if (*c == '-')
	{
		sign = -1;
		c++;
	}
	while (*c && (*c >= '0' && *c <= '9'))
	{
		number *= 10;
		number += *c - '0';
		c++;
	}
	number *= sign;
	return (number);
}
