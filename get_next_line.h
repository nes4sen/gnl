/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:07:52 by nosahimi          #+#    #+#             */
/*   Updated: 2024/12/14 11:15:27 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9
# endif

int		is_new_line(char *str);
size_t	ft_strlen(char *str);

char	*get_next_line(int fd);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, size_t start, size_t len);
char	*ft_strjoin(char *str1, char *str2);

#endif