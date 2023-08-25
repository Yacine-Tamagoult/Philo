/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatamago <yatamago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:51:24 by ilona             #+#    #+#             */
/*   Updated: 2023/08/25 23:26:44 by yatamago         ###   ########.fr       */
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

void message(char *str, t_philo *philo)
{
	
	if(strcmp(str,"eat") == 0)
	{
		pthread_mutex_lock(&philo->data->write);
		printf("%d is eating\n", philo->id);
		pthread_mutex_unlock(&philo->data->write);
	}
	else if(strcmp(str,"think") == 0)
	{
		pthread_mutex_lock(&philo->data->write);
		printf("%d is thinking\n", philo->id);
		pthread_mutex_unlock(&philo->data->write);
	}
	else if(strcmp(str,"sleep") == 0)
	{
		pthread_mutex_lock(&philo->data->write);
		printf("%d is sleeping\n", philo->id);
		pthread_mutex_unlock(&philo->data->write);
	}
	else if(strcmp(str,"fork") == 0)
	{
		pthread_mutex_lock(&philo->data->write);
		printf("%d has taken a fork\n", philo->id);
		pthread_mutex_unlock(&philo->data->write);
	}
}