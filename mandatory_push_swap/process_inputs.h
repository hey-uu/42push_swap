/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:17:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 21:52:57 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_INPUTS_H
# define PROCESS_INPUTS_H

# include "../data_structure/dequeue/dequeue.h"

# ifndef FT_INT_MAX
#  define FT_INT_MAX 2147483647
# endif

enum e_is_error
{
	SUCCESS = 0,
	FAIL = 1
};

t_dequeue	*process_input(int argc, char **argv);

#endif