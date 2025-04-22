/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:43:43 by tkitago           #+#    #+#             */
/*   Updated: 2025/04/10 11:03:31 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 1000
#define EOF -1

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	capa;
}			t_string;

int	get_next_line(int fd, char **line);

#endif
