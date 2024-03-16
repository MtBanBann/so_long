/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:20:56 by afavier           #+#    #+#             */
/*   Updated: 2024/03/12 22:47:16 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_init.h"

t_map	*map_tab(char **argv, size_t len)
{
	t_map	*so_map;
	size_t	y;
	char	*line;
	int		fd;

	y = 0;
	fd = open_fd(argv);
	so_map = initialize_map(len, fd);
	line = get_next_line(fd);
	if (!line)
		error_read_line(fd);
	while (line)
	{
		so_map->map[y++] = ft_strdup_long(line);
		if (!so_map->map[y - 1])
			error_strdup_map(so_map, fd, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	so_map->map[y] = NULL;
	if (close(fd) == -1)
		error_close_fd_map(so_map, argv);
	map_edge(so_map, len, 0, 0);
	return (so_map);
}

static t_map	*initialize_map(size_t len, int fd)
{
	t_map	*new_map;

	new_map = malloc(sizeof(t_map));
	if (!new_map)
	{
		close(fd);
		ft_dprintf(2, "so_long : Error malloc new_map \n");
		exit(EXIT_FAILURE);
	}
	new_map->map = malloc(sizeof(char *) * (len + 1));
	if (!new_map->map)
	{
		close(fd);
		ft_dprintf(2, "so_long : Error malloc new_map \n");
		free(new_map);
		exit(EXIT_FAILURE);
	}
	new_map->width = 0;
	new_map->height = 0;
	new_map->collectible = 0;
	new_map->height_e = 0;
	new_map->width_e = 0;
	return (new_map);
}

static void	error_close_fd_map(t_map *so_map, char **argv)
{
	free_tab(so_map->map);
	free(so_map);
	ft_dprintf(2, "so_long: %s: %s\n", argv[1], strerror(errno));
	exit(EXIT_FAILURE);
}

static void	error_strdup_map(t_map *so_map, int fd, char *line)
{
	free_tab(so_map->map);
	free(so_map);
	ft_dprintf(2, "so_long : Error filling map \n");
	close(fd);
	free(line);
	exit(EXIT_FAILURE);
}
