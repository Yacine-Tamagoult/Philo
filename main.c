/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilona <ilona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:19:56 by soleil            #+#    #+#             */
/*   Updated: 2023/09/03 15:11:44 by ilona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	t_struct	ma_structure;

	if (ac > 6)
		printf("Erreur : trop d'arguments\n");
	else if (ac < 5)
		printf("Erreur : pas assez d'arguments\n");
	else if (ac == 6 || ac == 5)
	{
		if (!parsing(ac, av, &ma_structure.info))
		{
			gettimeofday(&ma_structure.info.debut, NULL);
			if (ft_create_tab(&ma_structure))
				printf("erreur\n");
		}
	}
	return (0);
}
