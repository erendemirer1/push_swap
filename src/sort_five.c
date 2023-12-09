/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edemirer <edemirer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 01:52:40 by edemirer          #+#    #+#             */
/*   Updated: 2023/12/09 01:52:41 by edemirer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*end;
	int		flag;

	end = ft_lstlast(*stack_a);
	if (end->index == 0)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		flag = 0;
		ft_push_small_a(stack_a, stack_b, flag);
	}
	flag = 1;
	ft_push_small_a(stack_a, stack_b, flag);
	ft_sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
