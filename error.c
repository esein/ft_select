/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:41:13 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/12 10:43:21 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

static void		with_set_back(int error_code, char *str)
{
	
}

static void		with_exit(int error_code,  char *str)
{
	if (error_code == UNKNOW_TERM)
		ft_putendl_fd("terminal inconnu", 2);
	else if (error_code == GET_ATTR)
	{
		ft_putendl_fd("can't get the termios data in ", 2);
		ft_putstr_fd(str, 2);
	}
	else if (error_code == GET_STR)
	{
		ft_putstr_fd("unable to set term capacity : ", 2);
		ft_putendl_fd(str, 2);
	}
	else if (error_code == SET_ATTR)
	{
		ft_putstr_fd("can't set term attr in ", 2);
		ft_putendl_fd(str, 2);
	}
	else if (error_code == NO_ARG)
	{
		ft_putendl_fd("no arguments", 2);
		ft_putendl_fd(USAGE, 2);
	}
	else
		ft_putstr_fd("undefined error", 2);
	exit(error_code);
}

int				error_ft_select(int error_code, char *str)
{
	if (error_code >= UNKNOW_TERM && error_code <= SET_ATTR)
		with_exit(error_code, str);
	if (error_code == GET_STR_BACK)
		{
			ft_putstr_fd("unable to set back capacity : ", 2);
			ft_putendl_fd(str, 2);
		}
		return (-1);
}
