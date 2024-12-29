/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 09:37:28 by mayilmaz          #+#    #+#             */
/*   Updated: 2024/12/24 09:38:47 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int			i;
	long int	number;

	number = 0;
	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number *= 10;
		number += str[i] - 48;
		i++;
	}
	return (number);
}

void	ft_binary(unsigned char c, int pid)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (c % 2 == 1)
			kill(pid, SIGUSR1);
		if (c % 2 == 0)
			kill(pid, SIGUSR2);
		c /= 2;
		j++;
		usleep(700);
	}
}

int	main(int ar, char **av)
{
	int	i;
	int	pid;

	i = 0;
	pid = 0;
	if (ar != 3)
		return (-1);
	pid = ft_atoi(av[1]);
	while (av[2][i] != '\0')
	{
		ft_binary(av[2][i], pid);
		i++;
	}
	return (0);
}
