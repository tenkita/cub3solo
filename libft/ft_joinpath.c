/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:55:23 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/08 12:56:02 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinpath(char *base, char *add_path)
{
	int		separate_flg;
	char	*final_path;
	size_t	size;

	size = ft_strlen(base);
	separate_flg = base[size - 1] == PATH_SEPARATE;
	size += ft_strlen(add_path) + 2 - separate_flg;
	final_path = (char *)xmalloc(sizeof(char) * size);
	if (!final_path)
		return (NULL);
	ft_strlcpy(final_path, base, size);
	if (!separate_flg)
		ft_strlcat(final_path, (char []){PATH_SEPARATE, '\0'}, size);
	ft_strlcat(final_path, add_path, size);
	return (final_path);
}
// check last char of base(/)
// if (!base || !path)
// return (NULL);
// (type){init_lst} 複合リテラル type:作成するオブジェクトの型 init_lst:オブジェクトを初期化するための値のリスト
//　型を指定して一時的なオブジェクトを作成し、そのオブジェクトへのポインタを即座に使用できる
// char[]: 要素数が自動的に決定される文字配列
// PATH_SEPARATE とヌル文字を含む 2要素の文字配列を作成
