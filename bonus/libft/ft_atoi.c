/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:45:37 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/20 18:38:13 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static int	skip_spaces_and_check_sign(int *i, const char *str)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			sign = -1;
		}
		(*i)++;
	}
	return (sign);
}

long	ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long		result;

	result = 0;
	i = 0;
	sign = skip_spaces_and_check_sign(&i, str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (result * sign);
		i++;
	}
	return (result * sign);
}
