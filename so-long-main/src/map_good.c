/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_good.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:20:50 by afavier           #+#    #+#             */
/*   Updated: 2024/03/12 22:26:57 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	map_duplicate(t_map *so_map, size_t len)
{
	char	**map_dup;
	size_t	i;

	i = 0;
	map_dup = malloc(sizeof(char *) * (len + 1));
	if (!map_dup)
	{
		ft_dprintf(2, "Error malloc map_dup\n");
		free_tab(so_map->map);
		free(so_map);
		exit(EXIT_FAILURE);
	}
	while (len > i)
	{
		map_dup[i] = ft_strdup(so_map->map[i]);
		if (!map_dup[i])
			free_map_dup_malloc(map_dup, so_map, i);
		i++;
	}
	map_dup[i] = NULL;
	map_two(map_dup, len, so_map);
	free_tab(map_dup);
	init_mlx_map(so_map);
}

int	map_two(char **map_dup, size_t len, t_map *so_map)
{
	size_t	p;

	p = 1;
	so_map->height = len;
	while (p == 1)
		p = map_while(map_dup, so_map, p);
	if (map_dup_good(map_dup, so_map->height, so_map->width) == -1)
		free_map(map_dup, so_map);
	return (0);
}

int	map_while(char **map_dup, t_map *so_map, int p)
{
	size_t	i;
	size_t	y;
	int		*e;

	e = 0;
	p = 0;
	i = 1;
	y = 1;
	while (so_map->height > i)
	{
		while (so_map->width > y)
		{
			map_e(map_dup, e, i, y);
			p = map_completed(map_dup, i, y, p);
			y++;
		}
		y = 1;
		i++;
	}
	return (p);
}

int	map_completed(char **map, int i, int y, int p)
{
	if (map[i][y] == 'P' || map[i][y] == '2')
	{
		if (map[i + 1][y] == '0' || map[i + 1][y] == 'C' || map[i +1][y] == 'E')
		{
			map[i + 1][y] = '2';
			p = 1;
		}
		if (map[i - 1][y] == '0' || map[i - 1][y] == 'C' || map[i -1][y] == 'E')
		{
			map[i - 1][y] = '2';
			p = 1;
		}
		if (map[i][y - 1] == '0' || map[i][y - 1] == 'C' || map[i][y -1] == 'E')
		{
			map[i][y - 1] = '2';
			p = 1;
		}
		if (map[i][y + 1] == '0' || map[i][y + 1] == 'C' || map[i][y +1] == 'E')
		{
			map[i][y + 1] = '2';
			p = 1;
		}
	}
	return (p);
}

int	map_dup_good(char **map_dup, int height, int width)
{
	int	i;
	int	y;

	i = 1;
	y = 1;
	while (height > i)
	{
		while (width > y)
		{
			if (map_dup[i][y] == 'C' || map_dup[i][y] == 'E')
			{
				return (-1);
			}
			y++;
		}
		y = 1;
		i++;
	}
	return (0);
}
