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
{	//initial design for holding coloring for the walls, ceiling, and floor
	unsigned int	set;
	unsigned int	*rgb;
}					t_color;

typedef struct		s_key
{	//key events for navigation. Ripped from fractol
	char			up;
	char			left;
	char			down;
	char			right;
	char			shift;
	char			c;
	char			space;
}					t_key;

typedef struct		s_mouse
{	//mouse events for navigation. Ripped from fractol
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
	double			direction_vector; //direction vector should always be a bit longer than the camera plane
	double			camera_plane; // camera plane should always be perpendicular to the direction for smooth view
	double			field_of_vision; // sum of previous two struct members
	double			line_height; // calculated height of line to draw on screen
	double			draw_start; // calculate lowest and highest pixel to fill in current vertical stripe
	double			draw_end;
	// player handling
	double			pos_x:22; // represents the position vector of the player
	double			pos_y:12;
	double			ray_pos; // initially set to the position of the player (pos_x, pos_y)
	double			dir_x:-1; // represents the player's direction. combined to be camera_plane abpve
	double			dir_y:0;
	double			plane_x:0; //coods of the camera plane above
	double			plane_y:0.66; //length of the plance is modifiabel though
	// time concerns
	double			time; // time of current frame
	double			old_time; //time of previous frame
	double			time_diff; //difference between the two used to determine how much to mvoe when key event is activated
								//this is to move at a constant speed no matter how long the calculation of the frames takes
								//also serves as an FPS counter
	// more ray stuff relevant to the DDA Algorithm
	double			map_x; //represents the current square of the map the ray is in
	double			map_y;
	double			side_dst_x; //initally the distance ray has to travel from origin to first x-side & y-side. Will be repurposed later on
	double			side_dst_y; //step variables will always be either -1 or +1
	double			delta_dst_y; //distance ray has to travel from 1 x-side/y-side to the next x-side/y-side. Refer to notes for graphic
	double			delta_dst_x;
	double			wall_dst; //used to calculate length of the ray
	int				wall_hit; // used to tell if we can break out of the DDA loop.
	int				side;	// If an x-side is hit, it's zero else if an y-side is hit, side equals one
	// speed modifiers
	double			move_speed; // constant value in squares/secomd
	double			rot_speed; // constant value in radians/second
	// textures
	int				text_num; //value of the current map square - 1. Reasoing is that there exists a texture 0, but map tole 0 has no texture as it's empty space
							 //to be able to use texture 0 anyway, substract 1 so that map tiles with value 1 will give texture 0
	int				wall_x; // represents the exact value where the wall was hit, not just the ineger coordinates of the wall. 
							// Tells us which x-coord of the texture to used
	int				text_x; // x-coord of the texture which is calculated out of wall_x
	int				text_y; //correlates to the x-coord and is only ever set once we know what text_x is.
	// ~~~~ random ~~~~
	int				strafe_l; // made the same way as the up down keys, but using plane_x/plane_y instead of dir_x/dir_y
	int				strafe_r;
	int				game_loop;
	double			size;
	double			mid_x;
	double			mid_y;
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
