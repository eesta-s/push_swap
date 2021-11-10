/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teams3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:37:50 by eesta            #+#    #+#             */
/*   Updated: 2021/10/12 17:29:13 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Эта функция перемещает два целых наименьших целых числа из stack_a в
** stack_b.
** Функция push_min_to_b() является вспомогательной функцией
** функция sorting_medium_algorithm(). Он повторяет stack_a в поисках своего
** целое число минимального значения путем поворота или обратного поворота стека, а затем -
** как только минимальное значение окажется вверху - функция push_stack() вызывается для
** переместите его в stack_b.
**
** @param t_stack **stack_a - стек для итерации в поисках минимального значения.
** @param t_stack **stack_b - стек, в который нужно поместить целое число с минимальным значением.
*/

void	ft_pushminb(t_stack **s_a, t_stack **s_b)
{
	int	min;

	min = ft_lstmin(*s_a);
	while ((*s_a)->data != min)
	{
		if ((*s_a)->data != min && (*s_a)->next->data != min)
			ft_rotaterev(s_a, 0, "rra\n");
		else
			ft_rotate(s_a, 0, "ra\n");
	}
	push_stack(s_a, s_b, "pb\n");
}

/*
** Эта функция разбивает 'stack_a' на 'stack_b' числа, пределы которых
** между первыми двумя элементами стека "пределы".
**
** @param t_stack **stack_a - Стек, подлежащий сортировке в конце. В конце
** функция split_a_to_b() эти стеки будут содержать
** только числа, которые больше второго
** элемент "пределов" или меньше первого.
**
** @param t_stack **stack_b - Вспомогательный стек. В конце split_a_to_b()
** функция этот стек будет содержать число между
** первый элемент "пределов" и последний
** элемент "ограничений".
**
** @param t_stack **ограничения - стек, содержащий ограничения, требуемые обоими
** стеки
**
** пример:
** - до
** ограничения: {14, 25, 50, 100}
** stack_a: [1, 13] отсортирован
** [14, 100] несортированный
** stack_b: пустой
** - после
** ограничения: {14, 25, 50, 100}
** stack_a: [1, 13] отсортирован
** ]25, 100] несортированные
** stack_b: [14, 25] несортированный
**
*/

void	ft_absplit(t_stack **s_a, t_stack **s_b, t_stack *lim)
{
	int	size;
	int	first;

	size = ft_counter(*s_a, lim);
	while (ft_lstlen(*s_b) < size)
	{
		first = ft_between(*s_a, lim);
		while (first--)
			ft_rotate(s_a, 0, "ra\n");
		push_stack(s_a, s_b, "pb\n");
	}
}

/*
** Эта функция принимает стек - 'stack_b' - и все его номера над
** ** второй элемент "лимитов" возвращен в "stock_a"
** пример:
** 50 случайных чисел от 1 до 50;
** stack_a: ]25, 50] несортированный
** stack_b: [1, 25] несортированный
** ограничения: {1, 13, 25, 50}
** ** все числа больше 13 должны вернуться в stock_a.
**
** @param t_stack **stack_a - стек, в который будут возвращаться числа.
** @param t_stack **stack_b - стек, в котором числа выше второго
** элемент "пределов" придется преодолеть.
** @param t_stack *ограничения - стек, содержащий ограничения
** разделы других стеков.
*/

void	ft_halfa(t_stack **s_a, t_stack **s_b, t_stack *lim)
{
	ft_newlim(&lim, *s_b, 0);
	while (ft_lstmore(*s_b, lim->next->data))
	{
		if ((*s_b)->data == ft_lstmin(*s_b))
		{
			push_stack(s_b, s_a, "pa\n");
			if ((*s_b)->data != ft_lstmin(*s_b)
				&& (*s_b)->data <= lim->next->data)
				ft_rotate(s_a, s_b, "rr\n");
			else
				ft_rotate(s_a, 0, "ra\n");
		}
		else if ((*s_b)->data > lim->next->data)
			push_stack(s_b, s_a, "pa\n");
		else
			ft_rotate(s_b, 0, "rb\n");
	}
}

/*
** Эта функция объединяет остальную часть stack_b' в 'stack_a' в отсортированном виде.
**
** @param t_stack **stack_a - стек, в который будут возвращаться числа
** сортировка.
** @param t_stack **stack_b - стек, где числа, где. В конце
** эта стопка будет пустой.
** @param t_stack *ограничения - стек, содержащий ограничения
** разделы других стеков.
*/

void	ft_sorta(t_stack **s_a, t_stack **s_b, t_stack *lim)
{
	t_stack	*dubble;

	dubble = ft_lstdubble2(*s_b);
	ft_lstsort(&dubble);
	while (ft_lstlen(*s_b))
	{
		if ((*s_b)->data == dubble->data)
		{
			push_stack(s_b, s_a, "pa\n");
			dubble = dubble->next;
			 if (ft_lstlen(*s_b) && (*s_b)->data != dubble->data
				&& (*s_b)->data != ft_lstmax(*s_b))
				ft_rotate(s_a, s_b, "rr\n");
			else
				ft_rotate(s_a, 0, "ra\n");
		}
		else if ((*s_b)->data == ft_lstmax(*s_b))
			push_stack(s_b, s_a, "pa\n");
		else
			ft_rotate(s_b, 0, "rb\n");
	}
	while (ft_lstlast(*s_a)->data != lim->next->data)
		ft_rotate(s_a, 0, "ra\n");
	lim->next->data = ft_nextnum(*s_a, &lim);
	ft_lstclear(&dubble);
}
