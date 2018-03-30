/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:22:50 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/30 10:25:44 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>

t_file_info		*init_file_info(void)
{
	t_file_info *root;

	root = (t_file_info *)ft_memalloc(sizeof(t_file_info));
	root->is_dir = 0;
//	root->parent = root;
	root->next = NULL;
//	root->files = (t_file_info *)ft_memalloc(sizeof(t_file_info));
	return (root);
}

t_file_info		*get_file_info(char *str)
{
	struct stat *buff;
	t_file_info *new;
	t_file_info *root;
	DIR			*d;
	struct dirent	*dir;

	new = init_file_info();
	root = new;
	buff = (struct stat *)ft_memalloc(sizeof(struct stat));
	dir = (struct dirent *)ft_memalloc(sizeof(struct dirent));
	new->name = ft_strnew(ft_strlen(str));
	new->name = str;
	if (S_ISDIR(buff->st_mode))
	{
		new->is_dir = 1;
		new->next= new;
		d = opendir(str);
		while ((dir = readdir(d)))
		{
			new = init_file_info();
			new->name = ft_strnew(ft_strlen(dir->d_name));
			new->name = dir->d_name;
			if (S_ISDIR(buff->st_mode))
				new->is_dir = 1;
			new->next = new;
			new = new->next;
		}
		closedir(d);
	}
	return (root);
}

void	order_f_info_lst(t_file_info **root, t_options *opt)
{
	return ;
}

void	print_lst_info(t_file_info *root)
{
	while (root)
	{
		printf("%s\n", root->name);
		root = root->next;
	}
}

int		main(int argc, char **argv)
{
	int  i;
	t_file_info *root;
	t_options *opt;
	opt = init_options();
	i = get_options(argc, argv, opt);
	while (i < argc)
	{
		root = get_file_info(argv[i]);
		print_lst_info(root);
		if (opt->t || opt->r)
			order_f_info_lst(root,opt);
		/*if (opt->R)
		{
			while (root)
			{
				if (root->is_dir)
					main()
			}
		}*/
		free(root);
		i++;
	}
	printf("l is %d\n", opt->l);
	printf("R is %d\n", opt->R);
	printf("a is %d\n", opt->a);
	printf("r is %d\n", opt->r);
	printf("t is %d\n", opt->t);
	return (0);
}
