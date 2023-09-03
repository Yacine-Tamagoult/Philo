/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilona <ilona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:49:23 by soleil            #+#    #+#             */
/*   Updated: 2023/09/03 15:39:07 by ilona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_sleep(t_philosophe *actuel)
{
	if (ft_print(actuel, "is sleeping", 0))
		return (1);
	ft_usleep(actuel->info->tts, actuel);
	actuel->sdk = 1;
	return (0);
}

// Le philosophe commence en prenant sa fourchette gauche
int	ft_gauchers(t_philosophe *actuel)
{
	pthread_mutex_lock(actuel->fourchette_g);
	if (ft_print(actuel, "has taken a fork", 0))
	{
		pthread_mutex_unlock(actuel->fourchette_g);
		return (1);
	}
	pthread_mutex_lock(&actuel->fourchette_d);
	if (ft_print(actuel, "has taken a fork", 0))
	{
		pthread_mutex_unlock(actuel->fourchette_g);
		pthread_mutex_unlock(&actuel->fourchette_d);
		return (1);
	}
	return (0);
}

// Le philosophe commence en prenant sa fourchette droite
int	ft_droitiers(t_philosophe *actuel)
{
	if (actuel->info->nb_de_philos % 2)
		ft_usleep(actuel->info->tte * 0.2, actuel);
	pthread_mutex_lock(&actuel->fourchette_d);
	if (ft_print(actuel, "has taken a fork", 0))
	{
		pthread_mutex_unlock(&actuel->fourchette_d);
		return (1);
	}
	pthread_mutex_lock(actuel->fourchette_g);
	if (ft_print(actuel, "has taken a fork", 0))
	{
		pthread_mutex_unlock(&actuel->fourchette_d);
		pthread_mutex_unlock(actuel->fourchette_g);
		return (1);
	}
	return (0);
}

void	unphilo(t_struct *m_s)
{
	pthread_create(&m_s->tab[0].philo, NULL, onephilo, &m_s->tab[0]);
}

void	*onephilo(void *philo)
{
	t_philosophe	*onemore;

	onemore = (t_philosophe *) philo;
	pthread_mutex_lock(&onemore->fourchette_d);
	ft_print(onemore, "has taken a fork", 0);
	pthread_mutex_unlock(&onemore->fourchette_d);
	pthread_mutex_lock(&onemore->info->mutex_mort);
	onemore->info->i_mort = 0;
	pthread_mutex_unlock(&onemore->info->mutex_mort);
	return (NULL);
}
