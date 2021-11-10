/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:10:23 by eesta            #+#    #+#             */
/*   Updated: 2021/10/12 17:21:48 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Эта функция проверяет, отсортирован ли стек.
** - Функция ft_stack_is_sorted() возвращает 1, если "стек" отсортирован;
** или 0, если это не так.
*/

int	ft_lstissort(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
** Функция разбивает "головку" стека на две половины - "первую", которая является
** первая половина - и "вторая", которая является второй половиной.
** ** Функция просто выполняет итерацию стека, увеличивая "быстро"
** переменная и впоследствии увеличивающаяся медленная переменная. К тому времени, как программа
** выходит из цикла while, "медленный" стек будет иметь будущую головку
** вторая половина стека - "вторая".
**
** @param t_stack *заголовок - стек ссылок для разделенного указателя на
** глава стека.
** @param t_stack *первый - стек, в который должна помещаться первая половина головы.
** @param t_stack *второй - стек, в который должна помещаться вторая половина головы.
*/

t_stack	*ft_lstsplit(t_stack *head)
{
	t_stack	*slow;
	t_stack	*fast;
	t_stack	*temporary;

	slow = head;
	fast = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	temporary = slow->next;
	slow->next = 0;
	return (temporary);
}

/*
** Эта функция объединяет stack_a со stack_b в отсортированном вопросе и возвращает
** заголовок ссылки на сортированный стек. Этот метод является рекурсивным
** @строка 77-83 - если первый узел первой половины больше, чем
** первый узел второй половины, затем ft_merge_sort() будет
** вызывается с увеличением первой половины на единицу.
** @строка 77-83 - если первый узел второй половины больше, чем
** первый узел первой половины, затем ft_merge_sort() будет
** вызывается со второй половиной, увеличенной на единицу.
** - ** - функция theft_merge_sort() возвращает заголовок отсортированного "стека".
*/

t_stack	*ft_lstmerge(t_stack *first, t_stack *second)
{
	if (!first)
		return (second);
	if (!second)
		return (first);
	if (first->data < second->data)
	{
		first->next = ft_lstmerge(first->next, second);
		first->next->prev = first;
		first->prev = 0;
		return (first);
	}
	else
	{
		second->next = ft_lstmerge(first, second->next);
		second->next->prev = second;
		second->prev = 0;
		return (second);
	}
}

//Эта функция дублирует стек

t_stack	*ft_lstdubble2(t_stack *stack)
{
	t_stack	*dubble;
	t_stack	*new;

	dubble = 0;
	while (stack)
	{
		new = ft_lstnew(stack->data);
		if (!new)
		{
			ft_lstclear(&dubble);
			return (0);
		}
		ft_lstback(&dubble, new);
		stack = stack->next;
	}
	return (dubble);
}

/*проверяет, есть ли в "стеке" какие-либо повторяющиеся целые числа
возвращает 1, если она содержит; или он возвращает 0, если это не так.*/

/*
** This function duplicates a stack.
** The ft_stack_duplicate() function copies a stack 'stack' and creates a
** duplicate of that stack 'duplicate'.
*/

int	ft_lstdubble(t_stack *stack)
{
	t_stack	*sort;

	sort = ft_lstdubble2(stack);
	ft_lstsort(&sort);
	while (sort->next)
	{
		if (sort->data == sort->next->data)
			return (1);
		sort = sort->next;
	}
	ft_lstclear(&sort);
	return (0);
}
