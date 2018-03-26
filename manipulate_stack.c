/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:45:56 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/26 17:33:21 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		move_stack_down(int **stack, int size)
{
	int	i;
	int	to_push;

	if (!size)
		return (0);
	i = size; 
	to_push = (*stack)[i];
	while (i > 0)
	{
		(*stack)[i] = (*stack)[i - 1];
		i--;
	}
	return (to_push);
}

int		move_stack_up(int **stack, int size)
{
	int	i;
	int	to_push;

	if (!size)
		return (0);
	to_push = (*stack)[0];
	i = 0;
	while (i < size - 1)
	{
		(*stack)[i] = (*stack)[i + 1];
		i++;
	}
	return (to_push);
}

void	rotate(t_stack *stack, int a, int reverse)
{
	if (a)
	{
		if (reverse)
			stack->a[0] = move_stack_down(&stack->a, stack->size_a);
		else
			stack->a[stack->size_a - 1]
				= move_stack_up(&stack->a, stack->size_a);
	}
	else
	{
		if (reverse)
			stack->b[0] = move_stack_down(&stack->b, stack->size_b);
		else
			stack->b[stack->size_b - 1]
				= move_stack_up(&stack->b, stack->size_b);
	}
}
void	swap(t_stack *stack, int a, int b)
{
	int	tmp;

	if (a && stack->size_a > 1)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	}
	if (b && stack->size_b > 1)
	{
		tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
	}
}

void	push(t_stack *stack, int a)
{
	int	i;
	int	to_push;

	i = 0;
	if ((a && stack->size_b == 0) || (!a && stack->size_a == 0))
		return ;
	if (a)
	{
		move_stack_down(&stack->a, stack->size_a);
		to_push = move_stack_up(&stack->b, stack->size_b);
		stack->a[0] = to_push;
		(stack->size_b)--;
		(stack->size_a)++;
	}
	else
	{
		move_stack_down(&stack->b, stack->size_b);
		to_push = move_stack_up(&stack->a, stack->size_a);
		stack->b[0] = to_push;
		(stack->size_b)++;
		(stack->size_a)--;
	}
}
