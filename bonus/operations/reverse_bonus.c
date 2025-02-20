/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:29:23 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/20 03:46:58 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	rra(t_stack **a, int n)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!a || !*a || !(*a)->next)
		return ;
	last = *a;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *a;
	*a = last;
	if (n == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int n)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!b || !*b || !(*b)->next)
		return ;
	last = *b;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *b;
	*b = last;
	if (n == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int n)
{
	if (a && *a && (*a)->next)
		rra(a, 1);
	if (b && *b && (*b)->next)
		rrb(b, 1);
	if (n == 0)
		write(1, "rrr\n", 4);
}
