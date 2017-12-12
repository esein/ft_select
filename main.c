/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:17:26 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/12 14:15:55 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

void		handle_signal(void)
{
	
}

void		send(struct s_elem *elem)
{

}

int			main(int argc, char **argv)
{
	struct termios		old_config;
	struct termios		term;
	struct s_elem		*entries;
	struct s_infos		infos;

	if (argc < 2)
		return (error_ft_select(NO_ARG, NULL));
	handle_signal();
	entries = parse_entry(argc, argv);
	init_term(&term);
	calculs(entries, &infos);
	print(entries);
	send(entries);
	return (0);
}
