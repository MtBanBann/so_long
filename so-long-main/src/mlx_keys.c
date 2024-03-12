/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:11:26 by afavier           #+#    #+#             */
/*   Updated: 2024/03/13 00:11:30 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	left_key(t_vars *vars)
{
	if (vars->map->map[vars->perso.x][vars->perso.y - 1] == '1')
		return ;
	else
	{
		vars->nb_mouv += 1;
		if (ft_printf("%d steps \n", vars->nb_mouv) == -1)
			mlx_exit(vars);
		if (vars->map->map[vars->perso.x][vars->perso.y - 1] == 'C'
			&& vars->map->collectible != 0)
			vars->map->collectible -= 1;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->fond.img,
			vars->perso.width_perso, vars->perso.height_perso);
		vars->perso.y = vars->perso.y - 1;
		vars->perso.width_perso -= 100;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->perso.img_perso.img,
		vars->perso.width_perso, vars->perso.height_perso);
}

void	right_key(t_vars *vars)
{
	if (vars->map->map[vars->perso.x][vars->perso.y + 1] == '1')
		return ;
	else
	{
		vars->nb_mouv += 1;
		if (ft_printf("%d steps \n", vars->nb_mouv) == -1)
			mlx_exit(vars);
		if (vars->map->map[vars->perso.x][vars->perso.y + 1] == 'C'
			&& vars->map->collectible != 0)
			vars->map->collectible -= 1;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->fond.img,
			vars->perso.width_perso, vars->perso.height_perso);
		vars->perso.y = vars->perso.y + 1;
		vars->perso.width_perso += 100;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->perso.img_perso.img,
		vars->perso.width_perso, vars->perso.height_perso);
}

void	up_key(t_vars *vars)
{
	if (vars->map->map[vars->perso.x - 1][vars->perso.y] == '1')
		return ;
	else
	{
		vars->nb_mouv += 1;
		if (ft_printf("%d steps \n", vars->nb_mouv) == -1)
			mlx_exit(vars);
		if (vars->map->map[vars->perso.x - 1][vars->perso.y] == 'C'
			&& vars->map->collectible != 0)
			vars->map->collectible -= 1;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->fond.img,
			vars->perso.width_perso, vars->perso.height_perso);
		vars->perso.x = vars->perso.x - 1;
		vars->perso.height_perso -= 100;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->perso.img_perso.img,
		vars->perso.width_perso, vars->perso.height_perso);
}

void	down_key(t_vars *vars)
{
	if (vars->map->map[vars->perso.x + 1][vars->perso.y] == '1')
		return ;
	else
	{
		vars->nb_mouv += 1;
		if (ft_printf("%d steps \n", vars->nb_mouv) == -1)
			mlx_exit(vars);
		if (vars->map->map[vars->perso.x + 1][vars->perso.y] == 'C'
			&& vars->map->collectible != 0)
			vars->map->collectible -= 1;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->fond.img,
			vars->perso.width_perso, vars->perso.height_perso);
		vars->perso.x = vars->perso.x + 1;
		vars->perso.height_perso += 100;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->perso.img_perso.img,
		vars->perso.width_perso, vars->perso.height_perso);
}

int	close_window(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		ft_printf("%d", vars->nb_mouv);
		mlx_exit(vars);
	}
	if (keycode == LEFT_ARROW_KEY)
		left_key(vars);
	if (keycode == RIGHT_ARROW_KEY)
		right_key(vars);
	if (keycode == UP_ARROW_KEY)
		up_key(vars);
	if (keycode == DOWN_ARROW_KEY)
		down_key(vars);
	if (vars->map->collectible == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->escape.img,
			vars->map->width_e * 100, vars->map->height_e * 100);
		if (vars->perso.x == vars->map->height_e
			&& vars->perso.y == vars->map->width_e)
		{
			ft_printf("you win in : %d steps\n", vars->nb_mouv);
			mlx_exit(vars);
		}
	}
	return (0);
}
