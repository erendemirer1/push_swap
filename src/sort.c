/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edemirer <edemirer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 01:52:43 by edemirer          #+#    #+#             */
/*   Updated: 2023/12/09 01:52:44 by edemirer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_other_three(t_list **stack_a, int *nums)
{
	if (nums[0] > nums[1] && nums[1] > nums[2])
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (nums[0] < nums[1] && nums[1] > nums[2]
		&& nums[0] < nums[2])
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	ft_sort_three(t_list **stack_a)
{
	t_list	*head;
	int		nums[3];
	int		i;

	i = 0;
	head = *stack_a;
	while (head != 0)
	{
		nums[i] = head->content;
		head = head->next;
		i++;
	}
	if (nums[0] > nums[1] && nums[1] < nums[2] && nums[0] < nums[2])
		sa(stack_a);
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[0] > nums[2])
		rra(stack_a);
	else if (nums[0] > nums[1] && nums[1] < nums[2] && nums[0] > nums[2])
		ra(stack_a);
	else
		ft_other_three(stack_a, nums);
}

void	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	int	flag;

	flag = 0;
	ft_push_small_a(stack_a, stack_b, flag);
	ft_sort_three(stack_a);
	pa(stack_a, stack_b);
}
