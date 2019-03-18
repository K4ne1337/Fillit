/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:38:52 by abelkhay          #+#    #+#             */
/*   Updated: 2019/03/18 15:40:52 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _READ_FILE_H_
# define _READ_FILE_H_

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "verify_block.h"
# include "../libft/libft.h"

int		read_file(char *filename, char **str_tetri, int *tetri_counter);

#endif
