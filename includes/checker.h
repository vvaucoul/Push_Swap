/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 22:04:39 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/19 15:03:44 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "core.h"

# include <unistd.h>
# include <stdlib.h>

# define DEFAULT_CHECKER_READ_INPUT 0

# define SUCCESS "\e[1m"
# define FAILURE "\e[1m"

int		read_input(t_val *val);

#endif
