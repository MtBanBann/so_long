/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:37:51 by afavier           #+#    #+#             */
/*   Updated: 2024/03/16 18:43:34 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_INIT_H
# define SO_LONG_INIT_H

static t_map	*initialize_map(size_t len, int fd);
static void		error_close_fd_map(t_map *so_map, char **argv);
static void		error_strdup_map(t_map *so_map, int fd, char *line);
void			map_edge(t_map *so_map, size_t len, size_t i, size_t y);

#endif