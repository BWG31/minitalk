/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:20:15 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/22 13:22:03 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *c);

#endif