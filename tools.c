/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilona <ilona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:51:24 by ilona             #+#    #+#             */
/*   Updated: 2023/08/24 14:52:31 by ilona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philosopher.h"

int	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	return ((tv.tv_sec * (int)1000) + (tv.tv_usec / 1000));
}