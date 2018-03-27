/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:22:50 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/26 21:55:17 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdio.h>

void	init_options(t_options *opt)
{
	opt->l = 0;
	opt->R = 0;
	opt->a = 0;
	opt->r = 0;
	opt->t = 0;
}

void	get_options(char *options, t_options *opt)
{
	if (ft_strchr(options, 'l'))
		opt->l = 1;
	if (ft_strchr(options, 'R'))
		opt->R = 1;
	if (ft_strchr(options, 'a'))
		opt->a = 1;
	if (ft_strchr(options, 'r'))
		opt->r = 1;
	if (ft_strchr(options, 't'))
		opt->t = 1;
}

int		main(int argc, char **argv)
{
	size_t i;
	DIR *d;
	struct dirent *dir;
	t_options *opt;
	
	opt = (t_options *)ft_memalloc(sizeof(t_options));
	init_options(opt);
	i = 1;
/*
	if (argc == 1)
		d = opendir(".");
	else
		d = opendir(argv[1]);
*/
	while (i < argc && argv[i][0] == '-')
	{
		get_options(argv[i], opt);
		i++;
	}
/*
	if (d)
	{
		while ((dir = readdir(d)))
		{
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
*/
	printf("l is %d\n", opt->l);
	printf("R is %d\n", opt->R);
	printf("a is %d\n", opt->a);
	printf("r is %d\n", opt->r);
	printf("t is %d\n", opt->t);
	return (0);
}
