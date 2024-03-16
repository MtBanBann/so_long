/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:11:20 by afavier           #+#    #+#             */
/*   Updated: 2024/03/12 22:27:04 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_mlx(t_map *map, t_vars *new_vars)
{
	if (new_vars->fond.img)
		mlx_destroy_image(new_vars->mlx, new_vars->fond.img);
	if (new_vars->escape.img)
		mlx_destroy_image(new_vars->mlx, new_vars->escape.img);
	if (new_vars->perso.img_perso.img)
		mlx_destroy_image(new_vars->mlx, new_vars->perso.img_perso.img);
	if (new_vars->win)
		mlx_destroy_window(new_vars->mlx, new_vars->win);
	if (new_vars->mlx)
	{
		mlx_destroy_display(new_vars->mlx);
		free(new_vars->mlx);
	}
	free_tab(map->map);
	free(map);
	free(new_vars);
	exit(EXIT_FAILURE);
}

void	mlx_exit(t_vars *vars)
{
	if (vars->fond.img)
		mlx_destroy_image(vars->mlx, vars->fond.img);
	if (vars->escape.img)
		mlx_destroy_image(vars->mlx, vars->escape.img);
	if (vars->perso.img_perso.img)
		mlx_destroy_image(vars->mlx, vars->perso.img_perso.img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	free_tab(vars->map->map);
	free(vars->map);
	free(vars);
	exit(EXIT_FAILURE);
}

void	error_mlx_wall(t_map *map, t_vars *vars, t_data *wall, int i)
{
	if (i == 1)
		ft_dprintf(2, "Wrong pics \n");
	if (wall->img)
		mlx_destroy_image(vars->mlx, wall->img);
	free(wall);
	error_mlx(map, vars);
}

void	error_mlx_collect(t_map *map, t_vars *vars, t_data *wall,
		t_data *collect)
{
	ft_dprintf(2, "Wrong pics \n");
	if (collect->img)
		mlx_destroy_image(vars->mlx, collect->img);
	free(collect);
	error_mlx_wall(map, vars, wall, 0);
}

void	free_wall_collect(t_vars *vars, t_data *wall, t_data *collect)
{
	mlx_destroy_image(vars->mlx, wall->img);
	mlx_destroy_image(vars->mlx, collect->img);
	free(wall);
	free(collect);
}
