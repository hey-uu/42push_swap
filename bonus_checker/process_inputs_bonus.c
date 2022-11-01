/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputs_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:38:37 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 21:55:37 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/ft_libft_mandatory/libft.h"
#include "dequeue_bonus.h"
#include "process_inputs_bonus.h"

static void	push_input_data(t_dequeue *input, char *str_data);
static int	check_duplication(t_dequeue *input, int data);
static int	cmp2(int a, int b, int mold);

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
		if (cmp2(data, dq_get_value(input, FRONT, i), 1) == AA)
			return (0);
	}
	return (1);
}

int	cmp2(int a, int b, int mold)
{
	if (a - b == 0)
		return (AA);
	if (mold == 1)
	{
		if (a - b > 0)
			return (AB);
		else
			return (BA);
	}
	else
	{
		if (b - a > 0)
			return (AB);
		else
			return (BA);
	}
}
