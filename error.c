/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:41:13 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/21 16:12:52 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

static void		with_exit(int error_code, char *str)
{
	if (error_code == UNKNOW_TERM)
		ft_putstr_fd("can't find terminal : ", 2);
	else if (error_code == GET_ATTR)
		ft_putendl_fd("can't get the termios data at ", 2);
	else if (error_code == GET_STR)
	{
		set_back_term();
		ft_putstr_fd("unable to set term capacity : ", 2);
	}
	else if (error_code == SET_ATTR)
		ft_putstr_fd("can't set term attr at  ", 2);
	else if (error_code == NO_ARG)
		ft_putendl_fd("no arguments", 2);
	else if (error_code == IOCTL_FAIL)
	{
		set_back_term();
		ft_putstr_fd("ioctl call failed at ", 2);
	}
	ft_putendl_fd(str, 2);
	exit(error_code);
}

static void		error_size(void)
{
	tputs(tgetstr("cl", NULL), 0, (void*)putchar_select);
	ft_putstr_fd("WINDOW TOO SMALL !", 2);
}

int				error_ft_select(int error_code, char *str)
{
	if (error_code >= UNKNOW_TERM && error_code <= IOCTL_FAIL)
		with_exit(error_code, str);
	else if (error_code == NO_SIZE)
		error_size();
	if (error_code == GET_STR_BACK)
	{
		ft_putstr_fd("unable to set back capacity : ", 2);
		ft_putendl_fd(str, 2);
	}
	if (error_code == CODING_BUG)
	{
		set_back_term();
		ft_putstr_fd("erreur de code dans : ", 2);
		ft_putendl_fd(str, 2);
		exit(error_code);
	}
	return (-1);
}
