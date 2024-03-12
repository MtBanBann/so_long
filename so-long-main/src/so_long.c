/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:31:53 by afavier           #+#    #+#             */
/*   Updated: 2024/03/12 22:21:03 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
	{
		ft_dprintf(2, "Wrong number of argument\n");
		return (0);
	}
	else
	{
		while (argv[1][i])
			i++;
		if (!(argv[1][i - 1] == 'r' && argv[1][i - 2] == 'e' &&
				argv[1][i - 3] == 'b' && argv[1][i - 4] == '.'))
		{
			ft_dprintf(2, "Wrong extension \n");
			return (0);
		}
		map_size(argv);
	}
	return (0);
}

void	init_mlx_map(t_map *map)
{
	t_data	*wall;
	t_data	*collect;
	t_vars	*vars;

	vars = initialize_vars(map);
	wall = initialize_wall(vars, map);
	collect = initialize_collect(vars, map, wall);
	creat_window(wall, collect, vars);
	free_wall_collect(vars, wall, collect);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->perso.img_perso.img,
		vars->perso.width_perso, vars->perso.height_perso);
	mlx_hook(vars->win, 2, 1L << 0, close_window, vars);
	mlx_hook(vars->win, 17, 1L << 0, close_window_cross, vars);
	mlx_loop(vars->mlx);
}

void	creat_window(t_data *wall, t_data *collect, t_vars *vars)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (y < 5)
	{
		while (i < vars->map->width - 1)
		{
			put_image_window(vars, i, y, wall);
			if (vars->map->map[y][i] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, collect->img,
					vars->perso.width, vars->perso.height);
			vars->perso.width += 100;
			i++;
		}
		vars->perso.width = 0;
		vars->perso.height += 100;
		i = 0;
		y++;
	}
}

void	pos_perso(t_vars *vars, size_t i, size_t y)
{
	vars->perso.height_perso = vars->perso.height;
	vars->perso.width_perso = vars->perso.width;
	vars->perso.x = y;
	vars->perso.y = i;
}

void	put_image_window(t_vars *vars, int i, int y, t_data *wall)
{
	if (vars->map->map[y][i] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->fond.img,
			vars->perso.width, vars->perso.height);
	if (vars->map->map[y][i] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, wall->img,
			vars->perso.width, vars->perso.height);
	if (vars->map->map[y][i] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->fond.img,
			vars->perso.width, vars->perso.height);
	if (vars->map->map[y][i] == 'P')
		pos_perso(vars, i, y);
}
