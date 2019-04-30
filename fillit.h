/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:17:15 by stherkil          #+#    #+#             */
/*   Updated: 2019/04/29 16:24:04 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H_
# define _FILLIT_H_

#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int parser(char buf[544]);
int algo(char tetri[28][4][4], int len);
int *getedges(char s[4][4]);

# endif