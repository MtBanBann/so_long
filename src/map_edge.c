/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:20:43 by afavier           #+#    #+#             */
/*   Updated: 2024/03/16 20:54:40 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	wrong_hight_or_bottom(t_map *so_map);
static void	wrong_rate(t_map *so_map);

void	map_edge(t_map *so_map, size_t len, size_t i, size_t y)
{
	so_map->width = strlen(so_map->map[0]);
	while (i < len)
	{
		while (so_map->map[i][y])
		{
			if ((i == 0 || i == len - 1) && y < so_map->width - 2)
			{
				if (so_map->map[i][y] != '1')
					wrong_hight_or_bottom(so_map);
			}
			else if (so_map->map[i][0] != '1'
				|| so_map->map[i][so_map->width - 2] != '1')
				wrong_rate(so_map);
			y++;
		}
		y = 0;
		i++;
	}
	map_valide_collectable(so_map, len, 0);
	map_duplicate(so_map, len);
}

int	close_window_cross(t_vars *vars)
{
	mlx_exit(vars);
	return (0);
}

static void	wrong_hight_or_bottom(t_map *so_map)
{
	ft_dprintf(2, "Wrong hight or bottom invalid map \n");
	free_tab(so_map->map);
	free(so_map);
	exit(EXIT_FAILURE);
}

static void	wrong_rate(t_map *so_map)
{
	ft_dprintf(2, "Wrong rate invalid \n");
	free_tab(so_map->map);
	free(so_map);
	exit(EXIT_FAILURE);
}
