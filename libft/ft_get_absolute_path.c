/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_absolute_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:57:47 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/15 07:32:51 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_absolute_path(char *relative_path, char **env)
{
	char	**expanded_path;
	int		i;
	char	*path;

	if (ft_strlen(relative_path) == 0)
		return (NULL);
	expanded_path = ft_get_expanded_path(env);
	if (!expanded_path)
	{
		if (ft_path_exist(relative_path))
			return (ft_strdup(relative_path));
		return (NULL);
	}
	i = 0;
	while (expanded_path[i])
	{
		path = ft_joinpath(expanded_path[i++], relative_path);
		if (ft_path_exist(path))
			return (ft_2darraydel(expanded_path), path);
		free(path);
	}
	ft_2darraydel(expanded_path);
	if (ft_path_exist(relative_path))
		return (ft_strdup(relative_path));
	return (NULL);
}
