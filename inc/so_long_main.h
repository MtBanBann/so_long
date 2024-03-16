/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:38:08 by afavier           #+#    #+#             */
/*   Updated: 2024/03/16 18:38:09 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MAIN_H
# define SO_LONG_MAIN_H

static void	init_mlx_map(t_map *map);
static void	creat_window(t_data *wall, t_data *collect, t_vars *vars);
static void	pos_perso(t_vars *vars, size_t i, size_t y);
static void	put_image_window(t_vars *vars, int i, int y, t_data *wall);
t_vars		*initialize_vars(t_map *map);
t_data		*initialize_wall(t_vars *vars, t_map *map);
t_data		*initialize_collect(t_vars *vars, t_map *map, t_data *wall);

#endif