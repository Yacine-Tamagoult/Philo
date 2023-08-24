/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilona <ilona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:19:56 by soleil            #+#    #+#             */
/*   Updated: 2023/08/24 16:22:55 by ilona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


void *test(void *pp)
{
	t_philo *philo;

	philo = (t_philo *) pp;
	printf("salut je suis le philos n. : %i tu va bien ?\n", philo->id);
	return NULL;
}

int thread_init(t_data *data)
{
    int			i;
	pthread_t	t0;

	i = -1;
	data->start_time = get_time();
	if (data->nombre_repas > 0)
	{
		pthread_create(&t0, NULL, &test, &data->philos[i]);
	}
	while (++i < data->nombre_philo)
	{
		pthread_create(&data->tid[i], NULL, &test, &data->philos[i]);
		usleep(1);
	}
	i = -1;
	while (++i < data->nombre_philo)
	{
		pthread_join(data->tid[i], NULL);
	}
	return (0);
}




int main(int ac, char **av)
{
    t_data	data;
	
    if(ac < 5 || ac > 6)
	{
		return (1);
	}
    else if(init(&data,ac,av))
	{
		return (1);
	}
	thread_init(&data);
	return 0;
}