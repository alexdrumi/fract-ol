/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                              :+:    :+:                  */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	create_new_str_fd(const int fd, char *str[9999], int is_n_in_s)
{
	char	*new_str_fd;
	char	*to_free;
	int		str_fd_len;

	str_fd_len = ft_strlen(str[fd]);
	new_str_fd = (char *)ft_calloc((str_fd_len - is_n_in_s + 1), sizeof(char));
	to_free = str[fd];
	if (new_str_fd == NULL)
	{
		if (str[fd] != NULL)
			free(to_free);
		str[fd] = NULL;
	}
	else
	{
		ft_strncpy(new_str_fd, &str[fd][is_n_in_s], (str_fd_len - is_n_in_s));
		if (str[fd] != NULL)
			free(to_free);
		if (str_fd_len - is_n_in_s <= 0)
		{
			free(new_str_fd);
			new_str_fd = NULL;
		}
		str[fd] = new_str_fd;
	}
}

char	*join_with_buffer(char *buff, char *str[9999], int ret, const int fd)
{
	char	*tmp;
	char	*to_free;
	int		str_fd_len;

	str_fd_len = ft_strlen(str[fd]);
	tmp = (char *)ft_calloc(str_fd_len + ret + 1, sizeof(char));
	to_free = str[fd];
	if (tmp == NULL)
	{
		if (str[fd] != NULL)
			free(to_free);
		str[fd] = NULL;
	}
	else
	{
		ft_strncpy(tmp, str[fd], str_fd_len);
		ft_strncpy(tmp + str_fd_len, buff, ret);
		if (str[fd] != NULL)
			free(to_free);
	}
	return (tmp);
}

char	*line_without_n(char *str[9999], const int fd)
{
	int		is_n_in_s;
	char	*new_line;

	is_n_in_s = is_n_in_str(str[fd]);
	new_line = (char *)ft_calloc((is_n_in_s), sizeof(char));
	if (new_line == NULL)
		return (NULL);
	ft_strncpy(new_line, str[fd], is_n_in_s - 1);
	create_new_str_fd(fd, str, is_n_in_s);
	return (new_line);
}

void	search_for_newline(char *buff, const int fd, char *str[9999], int *ret)
{
	while (is_n_in_str(str[fd]) < 0)
	{
		*ret = read(fd, buff, BUFFER_SIZE);
		if (*ret == 0 || *ret == -1)
			break ;
		str[fd] = join_with_buffer(buff, str, *ret, fd);
	}
	return ;
}

int	get_next_line(const int fd, char **line)
{
	static char		*str[9999];
	char			buff[BUFFER_SIZE];
	int				ret;

	if (BUFFER_SIZE < 1 || fd < 0 || line == NULL)
		return (AN_ERROR_OCCURED);
	ret = -2;
	search_for_newline(buff, fd, str, &ret);
	if (ret == -1)
		return (AN_ERROR_OCCURED);
	if (is_n_in_str(str[fd]) != -1)
		*line = line_without_n(str, fd);
	else
	{
		*line = join_with_buffer(buff, str, ret, fd);
		str[fd] = NULL;
		return (EOF_HAS_BEEN_REACHED);
	}
	return (LINE_HAS_BEEN_READ);
}
