/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 09:37:23 by mayilmaz          #+#    #+#             */
/*   Updated: 2024/12/24 09:42:30 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putnbr(int pid)
{
	if (9 < pid)
	{
		ft_putnbr(pid / 10);
		ft_putnbr(pid % 10);
	}
	if (pid <= 9)
	{
		pid += 48;
		write(1, &pid, 1);
	}
}

void	ft_handle(int sig)
{
	static int	num = 1;
	static int	number = 0;

	if (sig == SIGUSR1)
		number += num;
	num += num;
	if (num == 256)
	{
		write(1, &number, 1);
		num = 1;
		number = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr(pid);
	signal(SIGUSR1, ft_handle);
	signal(SIGUSR2, ft_handle);
	while (1)
	{
		pause();
	}
	return (0);
}
