/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 09:00:06 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/26 17:33:19 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	display_usage(void)
{
	ft_printf("Usage:\t./push_swap [list of integers]\n"); 
	exit(0);
}

int			main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		display_usage();
	stack.size = argc - 1;
	stack.size_a = argc - 1;
	stack.size_b = 0;
	if (!(stack.a = (int *)malloc(sizeof(int) * stack.size)) ||
			!(stack.b = (int *)malloc(sizeof(int) * stack.size)))
		ft_error(2);
	fill_stack(&stack, argv + 1);
}
