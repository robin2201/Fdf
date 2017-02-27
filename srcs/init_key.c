/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <rberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:27:50 by robin             #+#    #+#             */
/*   Updated: 2016/05/27 12:16:12 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static	void			key1(int key, t_e *e)
{
	if (key == 126)
		e->yst -= 10;
	else if (key == 125)
		e->yst += 10;
	else if (key == 124)
		e->xst += 10;
	else if (key == 123)
		e->xst -= 10;
	else if (key == 84)
		e->c.c4 += 0.05;
	else if (key == 85)
		e->c.c4 -= 0.05;
}

static	void			key_vue(int key, t_e *e)
{
	if (key == 35)
	{
		e->para = 1;
		e->iso = 0;
	}
	else if (key == 31)
	{
		e->para = 0;
		e->iso = 1;
	}
}

static	void			key_zd(int key, t_e *e)
{
	if (key == 69)
		e->zoom += 1;
	else if (key == 78)
	{
		if (e->zoom - 1 == 0)
			e->zoom = -1;
		e->zoom -= 1;
	}
}

static	void			key_deep(int key, t_e *e)
{
	if (key == 67)
	{
		if (e->iso == 1)
			e->c.c3 += 0.1;
		else if (e->deep + 1 == 0)
			e->deep = 1;
		else
			e->deep += 1;
	}
	else if (key == 75)
	{
		if (e->iso == 1)
			e->c.c3 -= 0.1;
		else if (e->deep - 1 == 0)
			e->deep -= 2;
		else
			e->deep -= 1;
	}
}

int						key(int key, t_e *e)
{
	if (key == 53)
		exit(0);
	else if ((key >= 123 && key <= 126) || key == 84 || key == 85)
		key1(key, e);
	else if (key == 35 || key == 31)
		key_vue(key, e);
	else if (key == 69 || key == 78)
		key_zd(key, e);
	else if (key == 67 || key == 75)
		key_deep(key, e);
	else if (key == 83)
	{
		if (e->c.var2 == 0)
			e->c.var2 = 1;
		else
		{
			e->c.var2--;
			e->c.var1++;
			if (e->c.var1 == 20)
				e->c.var1 = 0;
		}
	}
	new_img(e);
	return (1);
}
