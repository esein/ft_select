/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:17:26 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/09 05:35:52 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

void		handle_signal(void)
{
}

int			main(int argc, char **argv)
{
	struct termios old_config;
	struct termios term;
	struct s_elem *entries;

	if (argc < 2)
		return (error_ft_select(NO_ARG, NULL));
	entries = parse_entry(argc, argv);
	handle_signal();
	return (0);
}
