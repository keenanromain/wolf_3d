#ifndef WOLF3D_H
# define WOLF3D_H
# define WS 1024
# define NB_C 10
# define L_CLICK 1
# define R_CLICK 2
# define S_UP 4
# define S_DOWN 5
# define MAP_W 24
# define MAP_H 24

# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_keys_macos.h"
# include "../libft/libft.h"

typedef struct		s_color
{
	unsigned int	set;
	unsigned int	*rgb;
}					t_color;

typedef struct		s_key
{
	char			up;
	char			left;
	char			down;
	char			right;
	char			shift;
	char			c;
	char			space;
}					t_key;

typedef struct		s_mouse
{
	char			left;
	char			right;
	char			up;
	char			down;
	int				horz;
	int				vert;
}					t_mouse;

typedef struct		s_env
{
	// the following values will be used to connect to the mlx server for rendering
	void			*mlx;
	void			*win;
	void			*p;
	void			*ptr;
	unsigned int	*pix;
	int				bits;
	int				bnum;
	int				endian;
	// the next subset of values are for calculating the field of vision
	float			direction_vector;
	float			camera_plane;
	float			field_of_vision; // sum of previous two struct members
	float			direction_distance;
	float			x_coord;
	float			y_coord;
	float			size;
	float			mid_x;
	float			mid_y;
	int				max_i;
	t_color			*colors;
	t_key			*keys;
	t_mouse			*mouse;
	void			*reset_func;
	void			*redraw_func;
	bool			status:true;
	bool			is_textured:false;
	char			*map;
}					t_env;

#endif
