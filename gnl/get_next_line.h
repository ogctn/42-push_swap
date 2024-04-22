/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:55:02 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/18 14:55:10 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t	strlen_plus(const char *buff, int rule);
char	*get_new_buffer(char *buffer);
char	*copy(char *s1, char *s2);
char	*linex(int fd, char *buffer);
char	*get_next_line(int fd);
char	*read_line(char	*str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*copy_next(char *dst, char *src);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
#endif
