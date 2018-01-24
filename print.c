/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:25:01 by gcadiou           #+#    #+#             */
/*   Updated: 2018/01/24 01:13:18 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

int			check_file(char *name, struct stat *stats)
{
	if ((lstat(name, stats)) >= 0)
	{
		if (S_ISLNK(stats->st_mode))
			ft_putstr_fd(MAGENTA, 0);
		else if (S_ISDIR(stats->st_mode))
			ft_putstr_fd(S_CYAN, 0);
		else if (stats->st_mode & (S_IXUSR | S_IXGRP | S_IXOTH))
			ft_putstr_fd(RED, 0);
	}
	ft_putstr_fd(name, 0);
	ft_putstr_fd(NONE, 0);
	return (0);
}

void		print_name(t_elem *elem)
{
	struct stat		stats;

	if (elem->cursor_on == 1)
	{
		if (tputs(tgetstr("us", NULL), 0, (void*)putchar_select) == ERR)
			error_ft_select(GET_STR, "us");
	}
	if (elem->selected == 1)
	{
		if (tputs(tgetstr("so", NULL), 0, (void*)putchar_select) == ERR)
			error_ft_select(GET_STR, "us");
	}
	check_file(elem->name, &stats);
	if (tputs(tgetstr("ue", NULL), 0, (void*)putchar_select) == ERR)
		error_ft_select(GET_STR, "ue");
	if (tputs(tgetstr("se", NULL), 0, (void*)putchar_select) == ERR)
		error_ft_select(GET_STR, "se");
}

int			print(struct s_elem *elem, struct s_infos *infos)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (tputs(tgetstr("cl", NULL), 0, (void*)putchar_select) == ERR)
		error_ft_select(GET_STR, "cl");
	while (elem != NULL)
	{
		if (x >= infos->nb_per_line)
		{
			write(0, "\n", 1);
			x = 0;
			y++;
		}
		print_name(elem);
		ft_putchar_nb_fd(0, ' ',
				(infos->max_size_elem - elem->name_len + SPACE_ELEM));
		x++;
		elem = elem->next;
	}
	return (0);
}
