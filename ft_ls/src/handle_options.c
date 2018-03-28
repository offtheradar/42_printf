/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:17:39 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/28 11:24:32 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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
