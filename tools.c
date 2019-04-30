/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:18:08 by stherkil          #+#    #+#             */
/*   Updated: 2019/04/29 16:59:33 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	to_corner(char s[4][4], int *coo)
{
	char **ss;
	int i;
	int j;

	ss = *s;
	i = -1;
	while (++i <= coo[1] - coo[0])
	{
		j = -1;
		while (++j <= coo[3] - coo[2])
		{
			ss[i][j] = ss[coo[0] + i][coo[2] + j];
			ss[coo[0] + i][coo[2] + j] = '.';
		}
	}
	return (0);
}