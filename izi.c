/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   izi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:34:50 by eesta            #+#    #+#             */
/*   Updated: 2021/10/12 17:30:49 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ** Функция ft_stack_first() возвращает первый элемент списка.
**
** @param t_stack *стек - начало списка.
**
** @возврат
** - ** - функция ft_stack_last() возвращает первый элемент списка.
*/

t_stack	*ft_lstfirst(t_stack *stack)
{
	if (!stack)
		return (NULL);
	return (stack);
}

/*
* Эта функция выполняет итерацию стека 'stack_a' и возвращает его максимальное значение.
*/

int	ft_lstmax(t_stack *s_a)
{
	int	max;

	max = s_a->data;
	while (s_a)
	{
		if (s_a->data > max)
			max = s_a->data;
		s_a = s_a->next;
	}
	return (max);
}

/*
* Эта функция выполняет итерацию стека 'stack_a' и возвращает его минимальное значение.
*/

int	ft_lstmin(t_stack *s_a)
{
	int	min;

	min = s_a->data;
	while (s_a)
	{
		if (s_a->data < min)
			min = s_a->data;
		s_a = s_a->next;
	}
	return (min);
}

/*
** Функция ft_stack_size() подсчитывает количество элементов в стеке.
*/

int	ft_lstlen(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

/*
** Эта функция добавляет элемент в стек.
** Функция ft_stack_add_front() добавляет элемент "новый" в начале
** стек.
*/

void	ft_lstfront(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	temp = *stack;
	if (temp)
	{
		new->next = temp;
		temp->prev = new;
	}
	*stack = new;
}
