/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:27:50 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/07 22:28:39 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(t_stack **a, int n)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (n == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int n)
{
	t_stack	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (n == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int n)
{
	sa(a, 1);
	sb(b, 1);
	if (n == 0)
		write(1, "ss\n", 3);
}
