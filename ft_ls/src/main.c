/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:22:50 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/28 21:41:57 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>

void	get_file_info(char *str, t_list *lst)
{
	struct stat *buff;
	t_file_info	*info;
	t_file_info *new;
	DIR			*d;
	struct dirent	*dir;

	info = (t_file_info *)ft_memalloc(sizeof(t_file_info));
	new = (t_file_info *)ft_memalloc(sizeof(t_file_info));
	buff = (struct stat *)ft_memalloc(sizeof(struct stat));
	dir = (struct dirent *)ft_memalloc(sizeof(struct dirent));
	lstat(str, buff);
	info->name = str;
	ft_lst_add_to_end(ft_lstnew(info, sizeof(t_file_info)), &lst);
	if (S_ISDIR(buff->st_mode))
	{
		d = opendir(str);
		while ((dir = readdir(d)))
		{
			new->name = dir->d_name;
			ft_lst_add_to_end(ft_lstnew(new, sizeof(t_file_info)), &(info->files));
			free(new);
		}
		closedir(d);
	}
}

int		main(int argc, char **argv)
{
	int  i;
	t_list *lst;
	//DIR *d;
	//struct dirent *dir;
	t_options *opt;
	opt = init_options();
	//t_list	*lst;
/*
	if (argc == 1)
		d = opendir(".");
	else
		d = opendir(argv[1]);
*/
	//lst = ft_lstnew(0,0);
	lst = (t_list *)ft_memalloc(sizeof(t_list));
	i = get_options(argc, argv, opt);
	while (i < argc)
	{
		get_file_info(argv[i], lst);
		i++;
	}
//	print_lst(lst);
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
	while (lst)
	{
		printf("file name is %s\n", lst->content->name);
		lst = lst->next;
	}
	printf("l is %d\n", opt->l);
	printf("R is %d\n", opt->R);
	printf("a is %d\n", opt->a);
	printf("r is %d\n", opt->r);
	printf("t is %d\n", opt->t);
	return (0);
}
