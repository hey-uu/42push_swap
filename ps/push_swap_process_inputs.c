/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_process_inputs.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:06:18 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/29 11:42:01 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/ft_libft_mandatory/libft.h"
#include "../ds/ds_dequeue/ft_dequeue.h"
#include "push_swap_merge_sort/merge_sort.h"
#ifndef FT_INT_MAX
# define FT_INT_MAX 2147483647
#endif

static int	push_input_data(t_dequeue *input, char *str_data);
static void	*process_input_errors(t_dequeue *input, char **splited);
static int	check_duplication(t_dequeue *input, int data);

t_dequeue	*process_input(int argc, char **argv)
{
	t_dequeue	*input;
	char		**splited;
	int			i;
	int			j;

	input = dq_create_dequeue(10);
	if (!input)
		return (FT_NULL);
	i = 0;
	while (++i < argc)
	{
		splited = ft_split(argv[i], ' ');
		if (!splited || (splited && !*splited))
			return (process_input_errors(input, splited));
		j = -1;
		while (splited[++j])
		{
			if (!push_input_data(input, splited[j]))
				return (process_input_errors(input, splited));
			free(splited[j]);
		}
		free(splited);
	}
	return (input);
}

static int	push_input_data(t_dequeue *input, char *str_data)
{
	int	data;

	data = ft_push_swap_atol(str_data);
	if ((data == 0 && ft_memcmp(str_data, "0", ft_strlen(str_data)) != 0) || \
		(data > FT_INT_MAX || data < -FT_INT_MAX - 1) || \
		!(check_duplication(input, data)))
	{
		dq_destroy_dequeue(input);
		return (0);
	}
	dq_push_rear(input, data);
	return (1);
}

static void	*process_input_errors(t_dequeue *input, char **splited)
{
	int	i;

	if (input)
		dq_destroy_dequeue(input);
	if (splited)
	{
		i = 0;
		while (splited[i++])
		{
			free(splited[i]);
		}
		free(splited);
	}
	return (FT_NULL);
}

int	check_duplication(t_dequeue *input, int data)
{
	int	i;

	i = -1;
	while (++i < input->used_size)
	{
		if (cmp2(data, dq_get_value(input, FRONT, i), UP) == AA)
			return (0);
	}
	return (1);
}
