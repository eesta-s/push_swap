/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teams2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:53:43 by eesta            #+#    #+#             */
/*   Updated: 2021/10/12 17:28:40 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Эта функция выполняет итерацию stack_a сверху и находит первое число с
** значения между первым и вторым числом в "кусках".
**
** @param t_stack *stack_a - Этот стек будет повторен, чтобы найти
** положение первого числа между
** "куски".
** @param t_stack *куски - этот стек будет служить ограничениями для поиска
** номер в "стеке_а".
**
** ** Эта функция возвращает расчетное количество или инструкции "ra", необходимые для
** номер, найденный в stack_a, должен быть сверху.
*/

int	ft_between(t_stack *s_a, t_stack *lim)
{
	int	first;
	int	max;
	int	min;

	min = lim->data;
	max = lim->next->data;
	first = 0;
	while (s_a)
	{
		if (s_a->data >= min && s_a->data <= max)
			return (first);
		first++;
		s_a = s_a->next;
	}
	return (first);
}

/*
** Эта функция берет стек - 'stack_a' и подсчитывает его номера между
** первые два элемента стека "ограничения".
** @param t_stack *stack_a - стек для подсчета чисел.
** @param t_stack **ограничения - вспомогательный стек, позволяющий узнать пределы stack_a.
** - Функция count_in_between() возвращает количество элементов в
** между первыми двумя элементами "пределов", которые существуют в stack_a.
*/

int	ft_counter(t_stack *s_a, t_stack *lim)
{
	t_stack	*dubble;
	int		max;
	int		min;

	dubble = ft_lstdubble2(s_a);
	ft_lstsort(&dubble);
	min = ft_lstsearche(dubble, lim->data);
	max = ft_lstsearche(dubble, lim->next->data);
	ft_lstclear(&dubble);
	return (max - min + 1);
}

/*
** Эта функция будет захватывать медиану 'stack_a' между первыми двумя ограничениями
** из стека "лимиты" и добавьте его в "лимиты".
**
** @строка 72-73 Функция get_new_limit() начинается с создания дублированного
** стек "stack_a" - "дубликат"; и сортировка этого стека -
** "дубликат" будет отсортированной версией "stack_a".
**
** @строка 74-75 затем функция попытается найти индекс в дубликате
** первый элемент "пределов" - min_idx; то же самое происходит с
** 'max_idx' - индекс второго элемента "лимитов" в
** "дубликат".
**
** @строка 76 после этого можно найти индекс медианы
** элемент max_idx и min_idx. Расчеты таковы:
** (max_idx - min_idx) / 2 + min_idx
**
** @строка 76 в этом случае новым будет элемент, индекс которого в двух экземплярах равен
** число между max_idx и min_idx.
**
** @строка 77-78 new добавляется в ограничения, и ограничения сортируются таким образом, чтобы они содержали
** все разделы stack_a в порядке.
*/

void	ft_newlim(t_stack **lim, t_stack *stack, int s)
{
	t_stack	*dubble;
	int		min;
	int		max;
	int		new;

	dubble = ft_lstdubble2(stack);
	ft_lstsort(&dubble);
	if (s)
	{
		min = ft_lstsearche(dubble, (*lim)->data);
		max = ft_lstsearche(dubble, (*lim)->next->data);
		new = ft_lstget(dubble, ((max - min) / 2 + min + 3));
	}
	else
		new = ft_lstget(dubble, ft_lstlen(dubble) / 2);
	ft_lstfront(lim, ft_lstnew(new));
	ft_lstsort(lim);
	ft_lstclear(&dubble);
}
