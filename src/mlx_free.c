/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:53:56 by afavier           #+#    #+#             */
/*   Updated: 2024/03/16 20:54:06 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_free_map(t_map *map)
{
	free_tab(map->map);
	free(map);
	exit(EXIT_FAILURE);
}

void	free_map(char **map_dup, t_map *so_map)
{
	ft_dprintf(2, "so_long : invalid Map not finish \n");
	free_tab(map_dup);
	free_tab(so_map->map);
	free(so_map);
	exit(EXIT_FAILURE);
}

void	free_map_dup_malloc(char **map_dup, t_map *so_map, int i)
{
	ft_dprintf(2, "Error malloc ft_strdup map_dup \n");
	if (i > 0)
		free_tab(map_dup);
	free(map_dup);
	free_tab(so_map->map);
	free(so_map);
	exit(EXIT_FAILURE);
}

void	map_e(char **map_dup, int *e, int i, int y)
{
	if (map_dup[i][y] == 'E')
		e++;
}

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
