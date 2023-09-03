/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilona <ilona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:31:56 by soleil            #+#    #+#             */
/*   Updated: 2023/09/03 15:33:44 by ilona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_info
{
	int						ttd;
	int						tte;
	int						tts;
	int						i_ate;
	int						index;
	int						i_mort;
	int						notepme;
	int						nb_de_philos;
	struct timeval			debut;
	pthread_mutex_t			m_ate;
	pthread_mutex_t			m_stop;
	pthread_mutex_t			m_printf;
	pthread_mutex_t			mutex_mort;
	struct s_philosophes	**actuel_philo;
}	t_info;

typedef struct s_philosophes
{
	int						i;
	int						vie;
	int						sdk;
	int						i_ate;
	int						nb_de_repas;
	void					*fourchette_g;
	long int				time_of_death;
	pthread_t				philo;
	struct s_info			*info;
	pthread_mutex_t			m_tod;
	pthread_mutex_t			mutex;
	pthread_mutex_t			fourchette_d;
}	t_philosophe;

typedef struct s_struct
{
	struct s_info			info;
	struct s_philosophes	*tab;
}	t_struct;

// Checkers

int				ft_isdigit(int c);
int				ft_onlynum(char **av, int j, int i);
int				parsing(int ac, char **av, t_info *ma_structure);
void			ft_init_info(char **av, t_info *info);

// Creation thread

int				ft_join(t_struct *ma_structure);
int				ft_init_struct(t_struct *ma_structure);
int				ft_lunch_thread(t_struct *ma_structure);
void			ft_init_tableau(t_struct *ma_structure);
int				ft_create_tab(t_struct *m_s);

// Utils

int				ft_atoi(const char *nptr);
int				ft_print(t_philosophe *actuel, char *str, int eat_or_not);
void			ft_usleep(int tmp, t_philosophe *philo);
long int		ft_time(t_philosophe *philo);
long int		ft_time_diff_ms(struct timeval debut, struct timeval actuel);

// Utils 2

void			ft_destroy(t_struct *m_s);

//	Repas

int				ft_eat(t_philosophe *actuel);
void			*ft_philo(void *philo);
void			ft_countrepas(t_philosophe *actuel);
void			ft_throw_fork(t_philosophe *actuel);

// Routine

int				ft_sleep(t_philosophe *actuel);
int				ft_gauchers(t_philosophe *actuel);
int				ft_droitiers(t_philosophe *actuel);

// Verif Mort

int				ft_mort(t_philosophe *actuel);
int				ft_check_death_deux(t_struct *m_s, int j);
int				ft_verif_philos(t_philosophe *actuel);
void			check_death(t_struct *m_s);

void			unphilo(t_struct *m_s);
void			*onephilo(void *philo);

#endif