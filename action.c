/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:49:23 by soleil            #+#    #+#             */
/*   Updated: 2023/09/02 15:36:02 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// Fonction principale de chaque thread
void	*ft_philo(void *philo)
{
	t_philosophe	*tab;

	tab = (t_philosophe *) philo;
	if (tab->i % 2)
		ft_usleep(tab->info->tte * 0.2, tab);
	while (ft_verif_philos(tab))
	{
		if (ft_verif_philos(tab))
		{
			if (ft_eat(tab))
				return (NULL);
		}
		if (ft_verif_philos(tab))
		{
			if (ft_sleep(tab))
				return (NULL);
		}
		if (ft_verif_philos(tab))
		{
			if (ft_print(tab, "is thinking", 0))
				return (NULL);
		}
	}
	return (NULL);
}

// Compte le nombre de repas qu'a pris le philosophe
void	ft_countrepas(t_philosophe *actuel)
{
	if (actuel->info->notepme != -1)
	{
		pthread_mutex_lock(&actuel->mutex);
		actuel->nb_de_repas++;
		if (actuel->nb_de_repas == actuel->info->notepme)
			actuel->i_ate = 1;
		pthread_mutex_unlock(&actuel->mutex);
	}
}

// Les philosophes prennent leur fourchettes et mangent
int	ft_eat(t_philosophe *actuel)
{
	if (actuel->i % 2 == 0)
	{
		if (ft_gauchers(actuel))
			return (1);
	}
	else
		if (ft_droitiers(actuel))
			return (1);
	if (ft_print(actuel, "is eating", 1))
	{
		pthread_mutex_unlock(actuel->fourchette_g);
		pthread_mutex_unlock(&actuel->fourchette_d);
		return (1);
	}
	ft_usleep(actuel->info->tte, actuel);
	ft_countrepas(actuel);
	ft_throw_fork(actuel);
	return (0);
}

// Libère les fouchettes
void	ft_throw_fork(t_philosophe *actuel)
{
	pthread_mutex_unlock(actuel->fourchette_g);
	pthread_mutex_unlock(&actuel->fourchette_d);
}
