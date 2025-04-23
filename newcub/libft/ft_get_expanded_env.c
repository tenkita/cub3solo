/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_expanded_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:56:07 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/24 12:09:09 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_get_expanded_env(char *key, char sep, char **env)
{
	char	*value;
	char	**expanded_env;

	value = ft_get_env(key, env);
	if (!value)
		return (NULL);
	expanded_env = ft_split(value, sep);
	if (!expanded_env)
		return (NULL);
	return (expanded_env);
}
