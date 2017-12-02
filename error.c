/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:41:13 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/02 19:44:03 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

void	error_ft_select(int error_code, char *str)
{
	if (error_code == UNKNOW_TERM)
		ft_putendl_fd("terminal inconnu", 2);
	else if (error_code == GET_ATTR)
		ft_putendl_fd("can't get the termios data", 2);
	else if (error_code == GET_STR)
	{
		ft_putstr_fd("can't find term capacity : ", 2);
		ft_putendl_fd(str, 2);
	}
	else if (error_code == SET_ATTR)
	{
		ft_putstr_fd("can't set attr", 2);
		ft_putendl_fd(str, 2);
	}
	else
	{
		ft_putstr_fd("undefined error", 2);
		exit (1);
	}
	exit(error_code);
}
