/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:21:00 by afavier           #+#    #+#             */
/*   Updated: 2024/03/16 20:53:35 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	error_close_fd(char **argv);
static void	error_map_size(char *line, int fd, char **argv);

int	map_size(char **argv)
{
	char	*line;
	int		fd;
	size_t	i;
	size_t	len;

	i = 0;
	fd = open_fd(argv);
	line = get_next_line(fd);
	if (!line)
		error_read_line(fd);
	while (line)
	{
		if (i == 0)
			len = ft_strlen_so_long(line);
		else if (len != ft_strlen_so_long(line) || i > 4 || len > 19)
			error_map_size(line, fd, argv);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (close(fd) == -1)
		error_close_fd(argv);
	return (i);
}

int	open_fd(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_dprintf(2, "so_long: %s: %s\n", argv[1], strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	error_read_line(int fd)
{
	close(fd);
	ft_dprintf(2, "so_long: error for read map get_next_line \n");
	exit(EXIT_FAILURE);
}

static void	error_close_fd(char **argv)
{
	ft_dprintf(2, "so_long: %s: %s\n", argv[1], strerror(errno));
	exit(EXIT_FAILURE);
}

static void	error_map_size(char *line, int fd, char **argv)
{
	close(fd);
	free(line);
	ft_dprintf(2, "so_long: %s: \n", argv[1]);
	exit(EXIT_FAILURE);
}
