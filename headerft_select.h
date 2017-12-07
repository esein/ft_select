/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerft_select.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:01:46 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/07 06:06:20 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERFT_SELECT_H
# define HEADERFT_SELECT_H

# include "Libft/libft.h"
# include <termios.h>
# include <curses.h>
# include <term.h>

# define USAGE "usage: ft_select [name ...]"

# define UNKNOW_TERM 1
# define GET_ATTR    2
# define GET_STR     3
# define SET_ATTR    4
# define NO_ARG      5

typedef struct		s_elem
{
	char			*name;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

int			error_ft_select(int error_code, char *str);
void			set_back_term(void);
struct s_elem	*parse_entry(int argc, char **argv);

#endif
