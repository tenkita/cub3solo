/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_seed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 07:38:34 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/04 07:40:07 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t	ft_generate_seed(void)
{
	int			stack_var;
	uint32_t	seed;

	seed = (uint32_t)((uintptr_t)(&stack_var));
	return (seed);
}
