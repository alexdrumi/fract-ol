/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                              :+:    :+:                  */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define LINE_HAS_BEEN_READ 1
# define EOF_HAS_BEEN_REACHED 0
# define AN_ERROR_OCCURED -1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

int		is_n_in_str(char *s);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
void	ft_strncpy(char *dst, const char *src, size_t len);
char	*join_with_buffer(char *buff, char *str[9999], int ret, const int fd);
void	create_new_str_fd(const int fd, char *str[9999], int is_n_in_s);
char	*line_without_n(char *str[9999], const int fd);
void	search_for_newline(char *buff, const int fd, char *str[9999], int *ret);
int		get_next_line(const int fd, char **line);

#endif
