/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:31:58 by afavier           #+#    #+#             */
/*   Updated: 2024/03/13 00:09:25 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	map_valide_collectable(t_map *so_map, size_t len, int nb_p)
{
	size_t	i;
	size_t	y;
	int		nb_e;

	i = 0;
	y = 0;
	nb_e = 0;
	while (i < len - 1)
	{
		while (so_map->map[i][y])
		{
			nb_e = check_e(so_map, i, y, 0) + nb_e;
			if (so_map->map[i][y] == 'C')
				so_map->collectible += 1;
			if (so_map->map[i][y] == 'P')
				nb_p++;
			y++;
		}
		y = 0;
		i++;
	}
	if (so_map->collectible == 0 || nb_e != 1 || nb_p != 1)
		free_so_map(so_map);
}

int	check_e(t_map *so_map, int i, int y, int nb_e)
{
	if (so_map->map[i][y] != 'E' && so_map->map[i][y] != '0' &&
		so_map->map[i][y] != 'C' && so_map->map[i][y] != '1' &&
		so_map->map[i][y] != 'P' && so_map->map[i][y +1] != '\0')
		free_so_map(so_map);
	if (so_map->map[i][y] == 'E')
	{
		so_map->height_e = i;
		so_map->width_e = y;
		nb_e++;
	}
	return (nb_e);
}

void	free_so_map(t_map *so_map)
{
	ft_dprintf(2, "Map invalide");
	free_tab(so_map->map);
	free(so_map);
	exit(EXIT_FAILURE);
}

char	*ft_strdup_long(const char *s)
{
	size_t	i;
	size_t	y;
	char	*tab;

	i = ft_strlen(s);
	y = 0;
	tab = malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	while (s[y])
	{
		tab[y] = s[y];
		y++;
	}
	tab[y] = '\0';
	return (tab);
}

size_t	ft_strlen_so_long(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
