/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:49:23 by soleil            #+#    #+#             */
/*   Updated: 2023/09/02 15:35:24 by soleil           ###   ########.fr       */
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
