/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 21:01:29 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/28 21:08:52 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# include "libft/libft.h"
# include <sys/stat.h>
# include <dirent.h>

typedef struct		s_options
{
	int		l;
	int		R;
	int		a;
	int		r;
	int		t;
}					t_options;

typedef	struct		s_file_info
{
	char	*name;
	int		is_hidden;
	int		is_dir;
	t_list	*files;
}					t_file_info;

t_options			*init_options(void);

void				set_options(char *options, t_options *opt);

int					get_options(int argc, char **argv, t_options *opt);

void				get_file_info(char *str, t_list *lst);
#endif
