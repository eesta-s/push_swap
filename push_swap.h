/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:22:55 by eesta            #+#    #+#             */
/*   Updated: 2021/10/12 16:33:39 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;

}t_stack;

int			ft_counter(t_stack *s_a, t_stack *lim);
void		ft_exit(t_stack *s_a, t_stack *s_b);
void		ft_newlim(t_stack **lim, t_stack *stack, int s);
void		sort(t_stack **stack_a, t_stack **stack_b);
int			ft_between(t_stack *s_a, t_stack *lim);
int			ft_nextnum(t_stack *s_a, t_stack **lim);
void		ft_halfa(t_stack **s_a, t_stack **s_b, t_stack *lim);
void		ft_sorta(t_stack **s_a, t_stack **s_b, t_stack *lim);
void		ft_processing(char **argv, t_stack **stack);
void		push_stack(t_stack **from, t_stack **to, char *str);
void		ft_pushminb(t_stack **s_a, t_stack **s_b);
void		ft_rotaterev(t_stack **one, t_stack **two, char *str);
void		ft_rotate(t_stack **one, t_stack **two, char *str);
void		ft_rotatemax(t_stack **stack_a, t_stack *lim);
void		sort2(t_stack **stack_a);
void		sort3(t_stack **s_a, t_stack **s_b);
void		sort4(t_stack **s_a, t_stack **s_b, t_stack **limits, int i);
void		ft_absplit(t_stack **s_a, t_stack **s_b, t_stack *lim);
int			ft_isnumbers(char *str);
void		swap_stack(t_stack *one, t_stack *two, char *str);

void		ft_lstback(t_stack **stack, t_stack *new);
void		ft_lstfront(t_stack **stack, t_stack *new);
void		ft_lstclear(t_stack **stack);
t_stack		*ft_lstdubble2(t_stack *stack);
int			ft_lstdubble(t_stack *stack);
int			ft_lstsearche(t_stack *stack, int value);
t_stack		*ft_lstfirst(t_stack *stack);
int			ft_lstget(t_stack *stack, int position);
int			ft_lstmore(t_stack *stack, int value);
t_stack		*ft_lstlast(t_stack *stack);
t_stack		*ft_lstnew(int data);
int			ft_lstmax(t_stack *stack_a);
int			ft_lstmin(t_stack *stack_a);
void		ft_lstfree(t_stack **stack);
void		ft_lstsort(t_stack **stack);
int			ft_lstissort(t_stack *stack);
t_stack		*ft_lstsplit(t_stack	*head);
t_stack		*ft_lstmerge(t_stack *first, t_stack *second);
int			ft_lstlen(t_stack *stack);

long long	ft_atoi(const char *str);
void		ft_putstr(char *s);
void		ft_swap(int *a, int *b);

#endif
