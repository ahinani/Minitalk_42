/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:26:27 by ahinani           #+#    #+#             */
/*   Updated: 2022/02/15 17:33:43 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# define YELLOW "\e[0;33m"
# define GREEN "\e[0;32m"
# define RED "\033[0;31m"
# define BLUE "\033[0;34m"

void	ft_putstr(char *str);
void	ft_putnbr(unsigned int nb);
int		ft_atoi(const char *str);
#endif