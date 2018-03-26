/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 09:01:07 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/26 17:33:22 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_stack
{
	int			size;
	int			size_a;
	int			size_b;
	int			*a;
	int			*b;
}				t_stack;

void			print_stack(t_stack stack, int a, int b);
void			fill_stack(t_stack *stack, char **argv);
void			error(int type);
void			push(t_stack *stack, int a);
void			swap(t_stack *stack, int a, int b);
void			rotate(t_stack *stack, int a, int reverse);

#endif
