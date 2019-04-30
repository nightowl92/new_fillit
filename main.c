/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 19:07:32 by stherkil          #+#    #+#             */
/*   Updated: 2019/04/29 16:53:29 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_error(void)
{
	printf("out");
	return (0);
}

static int		ft_checklen(ssize_t nb)
{
	printf("%zd\n", nb);
	if (nb > 544 || nb < 19 || ((((nb - 19) % 21) > 0)))
		return (1);
	return (0);
}

static void		printtab(char tetris[28][4][4],int buflen)
{
	int ct;
	int i;
	int j;

	ct = 0;
	while (buflen > 0)
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while(++j < 4)
			{
				--buflen;
				printf("%c ",tetris[ct][i][j]);
			}
			printf("\n");
			--buflen;
		}
		--buflen;
		++ct;
		printf("\n");
	}
}

static void		buftotab(char tetris[28][4][4], char buf[545], int buflen)
{
	int ct;
	int i;
	int j;

	ct = 0;
	while (buflen && *buf)
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while(++j < 4)
			{
				if (*buf != '.')
					tetris[ct][i][j] = ct + 'A';
				else
					tetris[ct][i][j] = *buf;
				--buflen;
				buf++;
			}
			buf++;
			--buflen;
		}
		buf++;
		++ct;
	}
}

int main(int argc, char **argv)
{
	int     buflen;
	char	buf[545];
	char	tetris[28][4][4];
	int		fd;
	int     i;

	fd = open(argv[1], O_RDONLY);
	if (ft_checklen((buflen = read(fd, buf, 546))))
		return (ft_error());
	if (parser(buf))
		return (ft_error());
	buftotab(tetris, buf, buflen);
	printtab(tetris, buflen);
	algo(tetris, 2);
	return (0);
}
