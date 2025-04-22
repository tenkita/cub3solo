#include "cub3d.h"

char	**realloc_2d(char **old, int size, int new_capa)
{
	int		i;
	char	**new_arr;

	i = 0;
	new_arr = malloc(sizeof(char *) * new_capa);
	while (i < size)
	{
		new_arr[i] = old[i];
		i++;
	}
	free(old);
	return (new_arr);
}
