#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include "wolf_3d.h"

#define MAP_W 24
#define MAP_H 24

int		check_input(char *s)
{
	if (!ft_strstr(s, "map"))
		return (0);
	if (s)
}

int		main(int ac, char **av)
{
	t_env *env;

	if (ac != 2)
		return (ft_puterr(0));
	if (!(env = (t_env *)malloc(sizeof(t_env *))))
		return (ft_puterr(1));
	if (!check_input(av[1]))
		return (ft_puterr(2));
	env->map = av[1];
	return (proceed(env));
}
