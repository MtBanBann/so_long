/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:10:56 by afavier           #+#    #+#             */
/*   Updated: 2024/03/12 22:46:29 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

t_vars	*initialize_vars(t_map *map)
{
	t_vars	*new_vars;

	new_vars = malloc(sizeof(t_vars));
	if (!new_vars)
		error_free_map(map);
	new_vars->mlx = mlx_init();
	if (new_vars->mlx == NULL)
		error_mlx(map, new_vars);
	new_vars->win = mlx_new_window(new_vars->mlx, 1920, 500, "so long");
	if (new_vars->win == NULL)
		error_mlx(map, new_vars);
	new_vars->map = map;
	new_vars->fond.img = NULL;
	new_vars->escape.img = NULL;
	new_vars->perso.img_perso.img = NULL;
	vars_put_img(new_vars, map, 100, 100);
	new_vars->perso.width_perso = 0;
	new_vars->perso.height_perso = 0;
	new_vars->perso.x = 0;
	new_vars->perso.y = 0;
	new_vars->perso.height = 0;
	new_vars->perso.width = 0;
	new_vars->nb_mouv = 0;
	return (new_vars);
}

void	vars_put_img(t_vars *new_vars, t_map *map, int img_width,
		int img_height)
{
	char	*perso;
	char	*background;
	char	*escape;

	perso = "./pics/perso.xpm";
	background = "./pics/fond.xpm";
	escape = "./pics/escape.xpm";
	new_vars->fond.img = mlx_xpm_file_to_image(new_vars->mlx, background,
			&img_width, &img_height);
	if (new_vars->fond.img == NULL)
		error_mlx(map, new_vars);
	new_vars->escape.img = mlx_xpm_file_to_image(new_vars->mlx, escape,
			&img_width, &img_height);
	if (new_vars->escape.img == NULL)
		error_mlx(map, new_vars);
	new_vars->perso.img_perso.img = mlx_xpm_file_to_image(new_vars->mlx, perso,
			&img_width, &img_height);
	if (new_vars->perso.img_perso.img == NULL)
		error_mlx(map, new_vars);
	vars_put_img_following(new_vars, map);
}

void	vars_put_img_following(t_vars *new_vars, t_map *map)
{
	new_vars->fond.addr = mlx_get_data_addr(new_vars->fond.img,
			&new_vars->fond.bits_per_pixel,
			&new_vars->fond.line_length,
			&new_vars->fond.endian);
	if (new_vars->fond.addr == NULL)
		error_mlx(map, new_vars);
	new_vars->escape.addr = mlx_get_data_addr(new_vars->escape.img,
			&new_vars->escape.bits_per_pixel,
			&new_vars->escape.line_length,
			&new_vars->escape.endian);
	if (new_vars->escape.addr == NULL)
		error_mlx(map, new_vars);
	new_vars->perso.img_perso.addr = mlx_get_data_addr(
			new_vars->perso.img_perso.img,
			&new_vars->perso.img_perso.bits_per_pixel,
			&new_vars->perso.img_perso.line_length,
			&new_vars->perso.img_perso.endian);
	if (new_vars->perso.img_perso.addr == NULL)
		error_mlx(map, new_vars);
}

t_data	*initialize_wall(t_vars *vars, t_map *map)
{
	char	*wall;
	t_data	*new_wall;

	wall = "./pics/wall.xpm";
	new_wall = malloc(sizeof(t_data));
	if (!new_wall)
		error_mlx_wall(map, vars, new_wall, 1);
	new_wall->img_width = 0;
	new_wall->img_height = 0;
	new_wall->img = mlx_xpm_file_to_image(vars->mlx, wall, &new_wall->img_width,
			&new_wall->img_height);
	if (!new_wall->img)
		error_mlx_wall(map, vars, new_wall, 1);
	new_wall->addr = mlx_get_data_addr(new_wall->img, &new_wall->bits_per_pixel,
			&new_wall->line_length, &new_wall->endian);
	if (new_wall->addr == NULL)
		error_mlx_wall(map, vars, new_wall, 1);
	return (new_wall);
}

t_data	*initialize_collect(t_vars *vars, t_map *map, t_data *wall)
{
	char	*collectible;
	t_data	*new_collec;

	collectible = "./pics/collectible.xpm";
	new_collec = malloc(sizeof(t_data));
	if (!new_collec)
		error_mlx_collect(map, vars, wall, new_collec);
	new_collec->img_width = 0;
	new_collec->img_height = 0;
	new_collec->img = mlx_xpm_file_to_image(vars->mlx, collectible,
			&new_collec->img_width, &new_collec->img_height);
	if (!new_collec->img)
		error_mlx_collect(map, vars, wall, new_collec);
	new_collec->addr = mlx_get_data_addr(new_collec->img,
			&new_collec->bits_per_pixel,
			&new_collec->line_length,
			&new_collec->endian);
	if (new_collec->addr == NULL)
		error_mlx_collect(map, vars, wall, new_collec);
	return (new_collec);
}
