/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:02:36 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/26 14:35:40 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_end(int a, int b)
{
	ft_printf("-\t-\n");
	if (a && b)
		ft_printf("a\tb\n");
	else if (a)
		ft_printf("a\n");
	else if (b)
		ft_printf("b\n");
}

void	print_stack(t_stack stack, int a, int b)
{
	int	i;
	int	lines;

	i = 0;
	if (a && b)
		lines = (stack.size_a > stack.size_b) ? stack.size_a : stack.size_b;
	else
		lines = a ? stack.size_a : stack.size_b;
	while (i < lines && (a || b))
	{
		if (a && b)
		{
			if (i < stack.size_a)
				ft_printf("%d", stack.a[i]);
			if (i < stack.size_b)
				ft_printf("\t%d", stack.b[i]);
			ft_printf("\n");
		}
		else if (a)
			ft_printf("%d\n", stack.a[i]);
		else
			ft_printf("%d\n", stack.b[i]);
		i++;
	}
	print_end(a, b);
}
