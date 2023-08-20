/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleil <soleil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:47:23 by soleil            #+#    #+#             */
/*   Updated: 2023/08/20 19:25:47 by soleil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	struct s_data	*data;//
	pthread_t		t1; //0
	int				id; //
	int				eat_cont; //
	int				status; //
	int				eating; //
	uint64_t		time_to_die; //
	pthread_mutex_t	lock; //
	pthread_mutex_t	*r_fork; //
	pthread_mutex_t	*l_fork; //
}	t_philo;

typedef struct s_data
{
	pthread_t		*tid; //
	int				nombre_philo; //
	int				nombre_repas; //
	int				mort; //
	int				finis; //
	t_philo			*philos; //
	uint64_t		temps_mort; //
	uint64_t		temps_repas; //
	uint64_t		temps_repos; //
	uint64_t		start_time;
	pthread_mutex_t	*fourchette; //
	pthread_mutex_t	lock; // 
	pthread_mutex_t	write; //
}	t_data;