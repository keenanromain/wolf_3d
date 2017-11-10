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
	void			*mlx;
	void			*win;
	void			*p;
	void			*ptr;
	unsigned int	*pix;
	int				bits;
	int				bnum;
	int				endian;
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
	bool			is_texture:false;
}					t_env;

#endif
