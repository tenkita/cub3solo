/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:58:17 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/26 16:41:35 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llstclear(void *lst_ptr, size_t size)
{
	while (*(void **)lst_ptr)
		ft_llstdel(lst_ptr, size, 0, NULL);
}
// *(void **)lst_ptr: get ptr of head node of lst
// delete first node of lst(node index 0)