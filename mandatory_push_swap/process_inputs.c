/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:18:26 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/31 22:07:35 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/ft_libft_mandatory/libft.h"
#include "../data_structure/dequeue/ft_dequeue.h"
#include "merge_sort/merge_sort.h"
#include "process_inputs.h"

static void	push_input_data(t_dequeue *input, char *str_data);
static int	check_duplication(t_dequeue *input, int data);

t_dequeue	*process_input(int argc, char **argv)
{
	t_dequeue	*input;
	char		**splited;
	int			i;
	int			j;

	input = dq_create_dequeue(10);
	if (!input)
		ft_exit("Error\n", FAIL);
	i = 0;
	while (++i < argc)
	{
		splited = ft_split(argv[i], ' ');
		if (!splited || (splited && !*splited))
			ft_exit("Error\n", FAIL);
		j = -1;
		while (splited[++j])
		{
			push_input_data(input, splited[j]);
			free(splited[j]);
		}
		free(splited);
	}
	return (input);
}

static void	push_input_data(t_dequeue *input, char *str_data)
{
	int	data;

	data = ft_push_swap_atol(str_data);
	if ((data == 0 && ft_memcmp(str_data, "0", ft_strlen(str_data)) != 0) || \
		(data > FT_INT_MAX || data < -FT_INT_MAX - 1) || \
		!(check_duplication(input, data)))
		ft_exit("Error\n", FAIL);
	dq_push_rear(input, data);
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
