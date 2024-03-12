/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:07:43 by afavier           #+#    #+#             */
/*   Updated: 2024/03/13 00:01:10 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/ft_dprintf.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define ESC_KEY 65307
# define LEFT_ARROW_KEY 65361
# define RIGHT_ARROW_KEY 65363
# define UP_ARROW_KEY 65362
# define DOWN_ARROW_KEY 65364

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;

}			t_data;

typedef struct s_map
{
	size_t	width;
	size_t	height;
	size_t	collectible;
	int		height_e;
	int		width_e;
	char	**map;
}			t_map;

typedef struct s_perso
{
	int		height_perso;
	int		width_perso;
	int		height;
	int		width;
	int		x;
	int		y;
	t_data	img_perso;
}			t_perso;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	size_t	nb_mouv;
	t_perso	perso;
	t_data	fond;
	t_data	escape;
	t_map	*map;
}			t_vars;

int			map_size(char **argv);
int			map_tab(char **argv, size_t i);
void		map_edge(t_map *so_map, size_t len, size_t i, size_t y);
char		*ft_strdup_long(const char *s);
int			close_window(int keycode, t_vars *vars);
size_t		ft_strlen_so_long(const char *str);
void		map_duplicate(t_map *so_map, size_t len);
int			map_two(char **map_dup, size_t len, t_map *so_map);
t_map		*initialize_map(size_t len, int fd);
void		free_tab(char **tab);
int			map_dup_good(char **map_dup, int height, int width);
void		map_valide_collectable(t_map *so_map, size_t len, int nb_p);
void		free_so_map(t_map *so_map);
void		error_close_fd(char **argv);
void		error_map_size(char *line, int fd, char **argv);
void		error_read_line(int fd);
int			open_fd(char **argv);

void		error_strdup_map(t_map *so_map, int fd, char *line);
void		error_close_fd_map(t_map *so_map, char **argv);
void		wrong_hight_or_bottom(t_map *so_map);
void		wrong_rate(t_map *so_map);

void		wrong_hight_or_bottom(t_map *so_map);
void		wrong_rate(t_map *so_map);
t_vars		*initialize_vars(t_map *map);
t_data		*initialize_wall(t_vars *vars, t_map *map);
t_data		*initialize_collect(t_vars *vars, t_map *map, t_data *wall);
void		error_mlx(t_map *map, t_vars *new_vars);
void		mlx_exit(t_vars *vars);
void		error_mlx_wall(t_map *map, t_vars *vars, t_data *wall, int i);
void		error_mlx_collect(t_map *map, t_vars *vars, t_data *wall,
				t_data *collect);
void		vars_put_img(t_vars *new_vars, t_map *map, int img_width,
				int img_height);
void		creat_window(t_data *wall, t_data *collect, t_vars *vars);
void		init_mlx_map(t_map *map);
void		pos_perso(t_vars *vars, size_t i, size_t y);

void		left_key(t_vars *vars);
void		right_key(t_vars *vars);
void		up_key(t_vars *vars);
void		down_key(t_vars *vars);
int			map_completed(char **map_dup, int i, int y, int p);
void		map_e(char **map_dup, int *e, int i, int y);
void		free_wall_collect(t_vars *vars, t_data *wall, t_data *collect);
void		free_map(char **map_dup, t_map *so_map);
void		error_free_map(t_map *map);
int			map_while(char **map_dup, t_map *so_map, int p);
void		free_map_dup_malloc(char **map_dup, t_map *so_map, int i);
int			check_e(t_map *so_map, int i, int y, int nb_e);
void		put_image_window(t_vars *vars, int i, int y, t_data *wall);
int			close_window_cross(t_vars *vars);
void		vars_put_img_following(t_vars *new_vars, t_map *map);

#endif