/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:25:45 by soleil            #+#    #+#             */
/*   Updated: 2023/08/20 19:25:11 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


void init_philo(t_data *data)
{
    int i;

    i = 0;
    while(i < data->nombre_philo)
    {
        data->philos[i].data = data;
        data->philos[i].id = i + 1;
        data->philos[i].time_to_die = data->temps_mort;
        data->philos[i].eat_cont = 0;
        data->philos[i].eating = 0;
        data->philos[i].status = 1;
        pthread_mutex_init(&data->philos[i].lock, NULL);
        i++;
    }
}

int init_fourchette(t_data *data)
{
    int i;
    
    i = -1;
    while(++i < data->nombre_philo)
    {
        pthread_mutex_init(&data->fourchette[i],NULL);
    }
    i = 0;
    while (i < data->nombre_philo)
	{
		data->philos[i].l_fork = &data->fourchette[i];
		data->philos[i].r_fork = &data->fourchette[i - 1];
		i++;
	}
    return (0);
}

int	alloc(t_data *data)
{
	data->tid = malloc(sizeof(pthread_t) * data->nombre_philo);
	if (!data->tid)
		return (error(1));
	data->fourchette = malloc(sizeof(pthread_mutex_t) * data->nombre_philo);
	if (!data->fourchette)
		return (1);
	data->philos = malloc(sizeof(t_philo) * data->nombre_philo);
	if (!data->philos)
		return (1);
	return (0);
}

int init_data(t_data *data,char **av)
{
    data->nombre_philo = atoi(av[1]);
    data->temps_mort = atoi(av[2]);
    data->temps_repas = atoi(av[3]);
    data->temps_repos = atoi(av[4]);
    if(av == 6)
        data->nombre_repas = atoi(av[5]);
    else
        data->nombre_repas = -1;
    if (data->nombre_philo <= 0 || data->nombre_philo > 200 || data->temps_mort < 0
		|| data->temps_repas < 0 || data->temps_repos < 0)
            return (1);
    data->mort = 0;
    data->finis = 0;
    pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
}

int init(t_data *data,int ac, char **av)
{
    if(init_data(data,av))
        return (1);
    if(alloc(data))
        return(1);
    if(init_fourchette(data))
        return(1);
    init_philo(data);
    return (0);
}