/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edemirer <edemirer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 01:52:13 by edemirer          #+#    #+#             */
/*   Updated: 2023/12/09 14:56:14 by edemirer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_error(char *str, char **tab)
{
	ft_putendl_fd(str, 2);
	ft_free_str(tab);
	exit(0);
}

static int	ft_isrepeat(int num, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_args(int ac, char **av)
{
	int		i;
	long	num;
	char	**tab;

	i = 0;
	if (ac == 2)
		tab = ft_split(av[1], ' ');
	else
	{
		i = 1;
		tab = av;
	}
	while (tab[i])
	{
		num = ft_atoi(tab[i]);
		if (!ft_isnum(tab[i]))
			ft_error("Error", tab);
		if (ft_isrepeat(num, tab, i))
			ft_error("Error", tab);
		if (num < -2147483648 || num > 2147483647)
			ft_error("Error", tab);
		i++;
	}
	if (ac == 2)
		ft_free_str(tab);
}
