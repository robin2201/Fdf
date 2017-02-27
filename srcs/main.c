/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <rberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 12:54:39 by rberthie          #+#    #+#             */
/*   Updated: 2016/05/26 11:27:23 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int			main(int ac, char **av)
{
	t_e		e;

	if (ac == 2 && av[1] && ft_strstr(av[1], ".fdf") \
		&& ft_memset(&e, 0, sizeof(e)))
	{
		if ((e.ret = check_validity(&e, av[1])))
			ERROR;
		init_t_m(&e);
		create_img(&e);
		free_tab(&e);
		return (0);
	}
	else
		USAGE_ERROR;
}
