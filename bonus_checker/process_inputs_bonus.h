/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputs_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:38:48 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 17:40:56 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_INPUTS_BONUS_H
# define PROCESS_INPUTS_BONUS_H

# ifndef FT_INT_MAX
#  define FT_INT_MAX 2147483647
# endif

enum e_is_error
{
	SUCCESS = 0,
	FAIL = 1
};

enum e_two_comb
{
	AB = 0,
	BA = 1,
	AA = 2
};

t_dequeue	*process_input(int argc, char **argv);

#endif