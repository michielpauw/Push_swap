/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 09:53:16 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/26 14:35:43 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_is_number(char *in)
{
	if (*in == '-' || *in == '+')
		in++;
	while (*in)
	{
		if (!ft_isdigit(*in))
		{
			ft_putchar(*in);
			ft_error(3);
		}
		in++;
	}
}

static void	check_duplicate(t_stack *stack, int number, int cur)
{
	int	i;

	i = 0;
	while (i < cur)
	{
		if (number == stack->a[i])
			ft_error(3);
		i++;
	}
}

void	fill_stack(t_stack *stack, char **argv)
{
	int		i;
	double	number;
	char	*in;

	i = 0;
	while (i < stack->size)
	{
		in = argv[i];
		number = ft_atoi(in);
		if (number == 0)
			check_is_number(in);
		if (number > INT_MAX || number < INT_MIN)
			ft_error(3);
		check_duplicate(stack, (int)number, i);
		stack->a[i] = (int)number;
		i++;
	}
}
