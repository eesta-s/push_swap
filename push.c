/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:57:23 by eesta            #+#    #+#             */
/*   Updated: 2021/10/12 17:46:25 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Эта функция сортирует стек с помощью алгоритма сортировки слиянием.
** 1 - Если в стеке ноль или один элемент, программа останавливается, потому что
 нет необходимости в сортировке.
** 2 - Разделите стопку на две стопки - первую и вторую - с
** ** функция ft_stack_split()
** 3 - Отсортируйте обе половины с помощью ft_stack_sort()
** 4 - Объедините отсортированную половину  с помощью ft_merge_sort(),*/

void	ft_lstsort(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	if (!first || !first->next)
		return ;
	second = ft_lstsplit(first);
	ft_lstsort(&first);
	ft_lstsort(&second);
	*stack = ft_lstmerge(first, second);
}

/*
** Эта функция сортирует стопки размером более 5. Логика, стоящая за этим
** алгоритм немного сложнее, но я все равно попытаюсь его объяснить:
** Я решил разделить алгоритм на две разные фазы: фазу разделения
** и фазу слияния.
**
** Разделенная Фаза:
** Эта фаза сосредоточена на продвижении к stack_b, числу между определенным
** кусок. Инструкции, используемые для этой части, являются "ra", "rra" и "pb". Этот
** фаза заканчивается, когда все номера фрагмента находятся в stack_b.
** пример:
** 100 случайных и уникальных чисел от 1 до 100.
** 1-й кусок: числа от 1 до 50 в stack_b.
** 2-й кусок: числа от 50 до 100 в стеке_a.
**
** Затем программа выберет между:
** - Фаза Обратного Слияния:
** Эта фаза происходит, если размер stack_b слишком велик для фазы сортировки слиянием.
** Итак, что здесь произойдет, так это то, что половина значений stack_b вернется назад
** для стека_a - в частности, значения, которые больше среднего значения
** из stack_b. Это произойдет, в то же время пытаясь отсортировать
** что возможно вернуть в stack_a.
**
** - Этап сортировки Слиянием:
** Эта фаза происходит, если stack_b готов к сортировке обратно в stack_a - имеет
** несколько чисел, которые позволяют им вернуться назад
** сортируется в stack_a.
*/

void	sort4(t_stack **s_a, t_stack **s_b, t_stack **lim, int i)
{
	if (ft_lstlen(*lim) == 1)
	{
		ft_lstclear(lim);
		return ;
	}
	if (ft_lstlen(*lim) == 2
		&& ft_counter(*s_a, *lim) >= 20)
		ft_newlim(lim, *s_a, 1);
	if (!ft_lstlen(*s_b))
	{
		ft_absplit(s_a, s_b, *lim);
		ft_rotatemax(s_a, *lim);
	}
	if (ft_lstlen(*s_b) >= 20)
		ft_halfa(s_a, s_b, *lim);
	else
	{
		ft_sorta(s_a, s_b, *lim);
		ft_lstfree(lim);
	}
	sort4(s_a, s_b, lim, ++i);
}

/*
** Эта функция сортирует stack_a размером от 4 до 5. Логика, стоящая за этим
** алгоритм просто разделен на три этапа:
**
** @строка 135,136: вызовите инструкции push_stack(), чтобы нажать две самые маленькие
** номера от stack_a до stack_b - например:
** stack_a - это 3 2 5 1 4 - мы хотим, чтобы stack_b подтолкнул
** числа 1 и 2, и stack_a будет иметь: 3 5 4
**
** @строка 137: как только stack_a содержит только три целых числа для сортировки, вызовите
** функция sorting_small_algorithm() для сортировки стека_а.
** Следуя приведенному выше примеру, stack_a теперь будет: 3 4 5.
**
** @** @ строка 139: наконец, программе нужно только нажать числа stack_b
** ** вернемся к stock_a.
** до:
** стек_а: 3 4 5
** stack_b: 2 1
** после:
** стек_а: 1 2 3 4 5
** stack_b: -
**
*/

void	sort3(t_stack **s_a, t_stack **s_b)
{
	while (ft_lstlen(*s_a) > 3)
		ft_pushminb(s_a, s_b);
	sort2(s_a);
	while (ft_lstlen(*s_b))
		push_stack(s_b, s_a, "pa\n");
}

/*
** Эта сортирует stack_a размером менее 3. Только три типа
** используются инструкции: rra, ra, sa.
** @строка 43: здесь мы проверяем, соответствует ли второй элемент stack_a
** максимальное значение стека, и если первое значение не является
** минимальное значение - пример: 2 3 1 - Здесь решение простое,
** для сортировки этого алгоритма нам нужно повернуть стек вспять.
**
** @строка 45: здесь мы проверяем, соответствует ли первый элемент stack_a
** минимальное значение стека, и если второе значение не является
** максимальное значение - пример: 3 1 2 - Здесь решение простое,
** для сортировки этого алгоритма нам нужно перевернуть стек.
**
** @строка 48: если ничего из вышеперечисленного не происходит, мы меняем местами первые два элемента
** из stack_a либо для его сортировки, либо для последующего обратного поворота, либо
** поворот - пример: 3 2 1 - Здесь решение простое, для сортировки
** в этом алгоритме мы меняем местами первые два числа - 2 3 1 - чтобы потом
** поверните их в обратном направлении - 1 2 3.
*/

void	sort2(t_stack **s_a)
{
	int	max;
	int	min;

	max = ft_lstmax(*s_a);
	min = ft_lstmin(*s_a);
	while (!ft_lstissort(*s_a))
	{
		if ((*s_a)->data != min && (*s_a)->next->data == max)
			ft_rotaterev(s_a, 0, "rra\n");
		else if ((*s_a)->data == max
			&& (*s_a)->next->data == min)
			ft_rotate(s_a, 0, "ra\n");
		else
			swap_stack(*s_a, 0, "sa\n");
	}
}

/*
** Эта функция выбирает тип алгоритма сортировки на основе размера
** 'stack_a'.
** если размер стека:
** - меньше 3: вызывается функция sort_stack_small().
** - равно 4 или 5: вызывается функция sort_stack_medium().
** - ** - больше 5: вызывается функция short_stack_big().
*/

void	sort(t_stack **s_a, t_stack **s_b)
{
	t_stack	*limits;
	int		max;
	int		min;

	max = ft_lstmax(*s_a);
	min = ft_lstmin(*s_a);
	if (ft_lstlen(*s_a) <= 3)
		sort2(s_a);
	else if (ft_lstlen(*s_a) <= 5)
		sort3(s_a, s_b);
	else
	{
		limits = ft_lstnew(min);
		ft_lstback(&limits, ft_lstnew(max));
		sort4(s_a, s_b, &limits, 0);
	}
}