/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:03:46 by yraiss            #+#    #+#             */
/*   Updated: 2022/12/06 12:10:11 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*readline(int fd, char *line, char *rest);
char	*return_next_line(char *line, char *rest);

int		check_nl(char *s);
char	*joinstr(char *line, char *buffer, int read_size, int index);
char	*fill(char *new_line, char *line, int *i);

#endif