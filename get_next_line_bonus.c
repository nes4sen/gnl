/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:52:31 by nosahimi          #+#    #+#             */
/*   Updated: 2024/12/23 19:28:45 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*find_line(int fd, char *container, char *buff)
{
	char	*temp;
	ssize_t	r_size;

	r_size = 1;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	while (r_size > 0)
	{
		r_size = read(fd, buff, BUFFER_SIZE);
		if (r_size == -1)
			return (NULL);
		buff[r_size] = '\0';
		if (r_size == 0)
			break ;
		temp = ft_strjoin(container, buff);
		free(container);
		container = temp;
		if (is_new_line(buff))
			break ;
	}
	return (container);
}

static char	*get_line(char *str)
{
	size_t	len;
	char	*line;

	if (!*str)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	line = ft_substr(str, 0, len);
	return (line);
}

static char	*get_rest(char *str)
{
	size_t	len;
	char	*rest;

	if (!*str)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	rest = ft_substr(str, len, ft_strlen(str) - len);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*container[MAX_FD];
	char		*temp;
	char		*line;
	char		*buff;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	temp = find_line(fd, container[fd], buff);
	if (!temp)
	{
		free(container[fd]);
		free(buff);
		container[fd] = NULL;
		return (NULL);
	}
	line = get_line(temp);
	container[fd] = get_rest(temp);
	free(temp);
	free(buff);
	temp = NULL;
	buff = NULL;
	return (line);
}
// #include <fcntl.h>
// int main(void)
// {
//     int fd1, fd2, fd3;
//     char *line;

//     // Open multiple files for testing
//     fd1 = open("test.txt", O_RDONLY);
//     if (fd1 == -1)
//     {
//         perror("Error opening file1.txt");
//         return (1);
//     }

//     fd2 = open("test2.txt", O_RDONLY);
//     if (fd2 == -1)
//     {
//         perror("Error opening file2.txt");
//         close(fd1);
//         return (1);
//     }

//     fd3 = open("test3.txt", O_RDONLY);
//     if (fd3 == -1)
//     {
//         perror("Error opening file3.txt");
//         close(fd1);
//         close(fd2);
//         return (1);
//     }

//     // Read lines alternately from the files
//     for (int i = 0; i < 5; i++)
//     {
//         line = get_next_line(fd1);
//         if (line)
//         {
//             printf("FD1: %s", line);
//             free(line);
//         }
//         line = get_next_line(fd2);
//         if (line)
//         {
//             printf("FD2: %s", line);
//             free(line);
//         }
//         line = get_next_line(fd3);
//         if (line)
//         {
//             printf("FD3: %s", line);
//             free(line);
//         }
//     }
//     close(fd1);
//     close(fd2);
//     close(fd3);

//     return (0);
// }
