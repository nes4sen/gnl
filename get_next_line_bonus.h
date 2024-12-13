/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:55:52 by nosahimi          #+#    #+#             */
/*   Updated: 2024/12/13 10:15:11 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define MAX_FD 1024

int		is_new_line(char *str);
size_t	ft_strlen(char *str);

char	*get_next_line(int fd);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, size_t start, size_t len);
char	*ft_strjoin(char *str1, char *str2);

#endif