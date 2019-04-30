/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:39:42 by stherkil          #+#    #+#             */
/*   Updated: 2019/04/29 16:29:08 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void ft_steinhaus(int n, int arr[],int arrLen)
{
    int flag = 1;
	int temp;
	int i;
 
	if(n==1){
		printf("\n[");
 
		for(i=0;i<arrLen;i++)
			printf("%d,",arr[i]);
		printf("\b] Sign : %d",flag);
 
		flag*=-1;
	}
	else{
		for(i=0;i<n-1;i++){
			ft_steinhaus(n-1,arr,arrLen);
 
			if(n%2==0){
				temp = arr[i];
				arr[i] = arr[n-1];
				arr[n-1] = temp;
			}
			else{
				temp = arr[0];
				arr[0] = arr[n-1];
				arr[n-1] = temp;
			}
		}
		ft_steinhaus(n-1,arr,arrLen);
	}
}

int algo(char tetri[28][4][4], int len)
{
    return (0);
}