/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:07:02 by nosahimi          #+#    #+#             */
/*   Updated: 2024/12/13 11:22:06 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	char buff[11];

	ssize_t k = read(0 , buff, 10);
	buff[10] = '\0';
	printf("%s%ld",buff, k);
	
}