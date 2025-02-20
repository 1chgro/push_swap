/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:34:26 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/15 05:35:14 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

char	*get_next_word(char *str, int *i)
{
	char	*word;
	int		start;
	int		len;
	int		j;

	while (str[*i] && str[*i] == ' ')
		(*i)++;
	start = *i;
	len = 0;
	while (str[*i + len] && str[*i + len] != ' ')
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = str[start + j];
		j++;
	}
	word[j] = '\0';
	*i += len;
	return (word);
}

t_stack	*validate_and_add_num(char *word, t_stack *stack_a)
{
	long	num;

	if (!word || !is_number(word))
	{
		free(word);
		free_stack_and_exit(&stack_a);
	}
	num = ft_atoi(word);
	if (num > INT_MAX || num < INT_MIN)
	{
		free(word);
		free_stack_and_exit(&stack_a);
	}
	if (!add_number(&stack_a, num))
	{
		free(word);
		free_stack_and_exit(&stack_a);
	}
	free(word);
	return (stack_a);
}

t_stack	*process_argument(char *arg, t_stack *stack_a)
{
	int		j;
	char	*word;

	j = 0;
	while (arg[j] && is_space(arg[j]))
		j++;
	if (!arg[j])
		free_stack_and_exit(&stack_a);
	while (arg[j])
	{
		while (arg[j] && is_space(arg[j]))
			j++;
		if (arg[j])
		{
			word = get_next_word(arg, &j);
			stack_a = validate_and_add_num(word, stack_a);
		}
	}
	return (stack_a);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		j;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] && is_space(argv[i][j]))
			j++;
		if (!argv[i][j])
			free_stack_and_exit(&stack_a);
		stack_a = process_argument(argv[i], stack_a);
		i++;
	}
	if (has_duplicates(stack_a))
		free_stack_and_exit(&stack_a);
	return (stack_a);
}
