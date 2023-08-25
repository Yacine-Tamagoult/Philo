/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatamago <yatamago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 22:25:50 by yatamago          #+#    #+#             */
/*   Updated: 2023/08/25 23:26:54 by yatamago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void eat(t_philo *philo)
{
    pthread_mutex_lock(philo->r_fork);
    message("fork",philo);
    pthread_mutex_lock(philo->l_fork);
    message("fork",philo);
    message("eat",philo);
    philo->eat_cont++;
    usleep(10);
    pthread_mutex_unlock(philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
    
}