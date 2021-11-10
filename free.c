/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:53:08 by eesta            #+#    #+#             */
/*   Updated: 2021/10/12 17:22:21 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstfree(t_stack **stack)
{
	t_stack	*s;

	if (!stack)
		return ;
	s = *stack;
	if (s->next)
		s->next->prev = s->prev;
	if (s->prev)
		s->prev->next = s->next;
	if (s->prev)
		*stack = s->prev;
	else
		*stack = s->next;
	free(s);
}

void	ft_lstclear(t_stack **stack)
{
	t_stack	*s;

	s = *stack;
	if (!stack)
		return ;
	while (*stack)
		ft_lstfree(stack);
}

t_stack	*ft_lstlast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_lstback(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!*stack)
		*stack = new;
	else
	{
		last = ft_lstlast(*stack);
		new->prev = last;
		last->next = new;
	}
}

t_stack	*ft_lstnew(int data)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!stack)
		return (NULL);
	stack->data = data;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}
