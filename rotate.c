/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teams.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:12:56 by eesta            #+#    #+#             */
/*   Updated: 2021/10/12 17:24:27 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Эта функция берет первый элемент в верхней части "from_stack" и помещает его
** в верхней части "to_stack".
**
** @param t_stack **from_stack - стек, из которого нужно взять целое число.
** @param t_stack **to_stack - стек, в который должно помещаться целое число.
** @символ параметра *сообщение - сообщение, которое будет отображаться в конце
** функция.
** Возможные сообщения:
** "pa\n" - нажмите первый элемент 'stack_b', чтобы
** верхняя часть "стека_а".
** "pb\n" - нажмите первый элемент 'stack_a', чтобы
** в верхней части "stack_b".
*/

void	push_stack(t_stack **from, t_stack **to, char *str)
{
	if (!(*from))
		return ;
	ft_lstfront(to, ft_lstnew((*from)->data));
	ft_lstfree(from);
	ft_putstr(str);
}

/*
** Эта функция меняет местами первые 2 элемента в верхней части стека - либо
** "stack_a" или "stack_b" или оба - друг с другом.
**
** @param t_stack **обязательно - Замените первые два элемента этого стека на
** друг друга. Этот стек всегда будет меняться местами.
** @param t_stack **необязательно - Замените первые два элемента этого стека на
** друг друга. Этот стек является необязательным и не
** необходимо поменять местами.
** @символ параметра *сообщение - сообщение, которое будет отображаться в конце
** функция.
** Возможные сообщения:
** "sa\n" - поменять местами первые 2 элемента
** 'stack_a'.
** "sb\n: - поменять местами первые 2 элемента
** 'stack_b'.
** "ss\n" - поменять местами первые 2 элемента
** обе стопки.
*/

void	swap_stack(t_stack *one, t_stack *two, char *str)
{
	ft_swap(&(one->data), &(one->next->data));
	if (two)
		ft_swap(&(two->data), &(two->next->data));
	ft_putstr(str);
}

/*
** Эта функция сдвигает все элементы стека вверх на 1 - первый элемент
** становится последним.
**
** @param t_stack **обязательно - Стек для поворота - его первый элемент становится
** его последний. Этот стек всегда будет вращаться.
** @param t_stack **обязательно - Стек для поворота - его первый элемент становится
** его последний. Этот стек является необязательным и не
** необходимо повернуть.
** @символ параметра *сообщение - сообщение, которое будет отображаться в конце
** функция.
** Возможные сообщения:
** "ra\n" - Повернуть все элементы
** 'stack_a'.
** "rb\n" - Повернуть все элементы
** 'stack_b'.
** "rr\n" - Повернуть все элементы
** обе стопки.
*/

void	ft_rotate(t_stack **one, t_stack **two, char *str)
{
	int	data;

	data = ft_lstfirst(*one)->data;
	ft_lstfree(one);
	ft_lstback(one, ft_lstnew(data));
	if (two)
	{
		data = ft_lstfirst(*two)->data;
		ft_lstfree(two);
		ft_lstback(two, ft_lstnew(data));
	}
	ft_putstr(str);
}

/*
** Эта функция сдвигает все элементы стека вниз на 1 - последний элемент
** становится первым.
**
** @param t_stack **обязательно - Стек для обратного поворота - его первый элемент
** становится его последним. Этот стек всегда будет
** повернут.
** @param t_stack **обязательно - Стек для обратного поворота - его первый элемент
** становится его последним. Этот стек является необязательным и
** не нуждается в повороте.
** @символ параметра *сообщение - сообщение, которое будет отображаться в конце
** функция.
** Возможные сообщения:
** "rra\n" - Обратный поворот всех элементов
** 'stack_a'.
** "rrb\n" - Обратный поворот всех элементов
** 'stack_b'.
** "rrr\n" - Обратный поворот всех элементов
** обе стопки.
*/

void	ft_rotaterev(t_stack **one, t_stack **two, char *str)
{
	int		data;
	t_stack	*last_node;

	last_node = ft_lstlast(*one);
	data = last_node->data;
	ft_lstfree(&last_node);
	ft_lstfront(one, ft_lstnew(data));
	if (two)
	{
		last_node = ft_lstlast(*two);
		data = last_node->data;
		ft_lstfree(&last_node);
		ft_lstfront(two, ft_lstnew(data));
	}
	ft_putstr(str);
}

/*
** Эта функция поворачивает stack_a до тех пор, пока сортированные числа не будут найдены в
** нижняя часть стопки отсортирована в порядке убывания.
**
** @param t_stack *stack_a - стек для сортировки.
**
** @param t_stack **ограничения - вспомогательный стек для определения значений stack_a, которые
** сортируются.
*/

void	ft_rotatemax(t_stack **stack_a, t_stack *lim)
{
	t_stack	*dubble;
	int		num;
	int		index;

	dubble = ft_lstdubble2(*stack_a);
	ft_lstfront(&dubble, ft_lstnew(lim->data));
	ft_lstsort(&dubble);
	num = ft_lstget(dubble, ft_lstsearche(dubble, lim->data) - 1);
	ft_lstclear(&dubble);
	index = ft_lstsearche(*stack_a, num);
	if (num == -2147483648 || index == -2147483648)
		return ;
	if (index <= ft_lstlen(*stack_a) / 2)
		while (ft_lstlast(*stack_a)->data != num)
			ft_rotate(stack_a, 0, "ra\n");
	else
		while (ft_lstlast(*stack_a)->data != num)
			ft_rotaterev(stack_a, 0, "rra\n");
}
