/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:28:49 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/23 18:21:22 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra(t_stack **a, int n)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	if (n == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int n)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	if (n == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int n)
{
	ra(a, 1);
	rb(b, 1);
	if (n == 0)
		write(1, "rr\n", 3);
}
