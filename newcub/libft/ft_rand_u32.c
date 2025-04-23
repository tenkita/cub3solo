/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand_u32.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 06:36:06 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/04 06:59:33 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint32_t	xorshift32(t_xorshift32_state *state)
{
	uint32_t	x;

	x = state->a;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return (state->a = x);
}

uint32_t	ft_rand_u32(uint32_t seed)
{
	static t_xorshift32_state	state;
	static int					is_initialized = 0;

	if (!is_initialized)
	{
		state.a = seed;
		if (seed == 0)
			state.a = 42;
		is_initialized = 1;
	}
	return (xorshift32(&state));
}
