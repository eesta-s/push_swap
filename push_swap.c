/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:26:01 by eesta            #+#    #+#             */
/*   Updated: 2021/10/12 15:59:15 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Эта функция завершает программу либо в случае успеха, либо в случае ошибки.
t_stack *stack_a - "stack_a" программы на случай, если ее потребуется освободить.
t_stack *stack_b - "stack_b" программы на случай, если ее потребуется освободить.
int статус - статус программы
** 0 - В случае сбоя - завершение программы с "ошибкой\n"
** вызвано сбоем malloc; или в случае, если он недействителен -
** ** завершение программы с "ошибками", вызванными командой
** аргументы строки - "argv" недопустимы.
** Необходимо освободить только stack_a.
** 1 - В случае успеха - завершение программы без каких-либо
** проблемы. Все должно быть освобождено соответствующим образом.*/

void	ft_exit(t_stack *s_a, t_stack *s_b)
{
	if (s_a)
		ft_lstclear(&s_a);
	if (s_b)
		ft_lstclear(&s_b);
	ft_putstr("Error\n");
	exit(0);
}

void	ft_processing(char **argv, t_stack **s_a)
{
	int			i;
	long int	num;
	t_stack		*new_node;

	i = 0;
	while (argv[i])
	{
		if (!ft_isnumbers(argv[i]))
			ft_exit(*s_a, 0);
		num = ft_atoi(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			ft_exit(*s_a, 0);
		new_node = ft_lstnew(num);
		if (!new_node)
			ft_exit(*s_a, 0);
		ft_lstback(s_a, new_node);
		i++;
	}
	if (ft_lstdubble(*s_a))
		ft_exit(*s_a, 0);
}

int	main(int argc, char **argv)
{
	t_stack	*s_a;
	t_stack	*s_b;

	if (argc == 1)
		exit(1);
	s_a = 0;
	s_b = 0;
	ft_processing(&argv[1], &s_a);
	if (!ft_lstissort(s_a))
		sort(&s_a, &s_b);
	if (s_a)
		ft_lstclear(&s_a);
	if (s_b)
		ft_lstclear(&s_b);
	exit(0);
	return (0);
}
