/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 20:07:03 by edavid            #+#    #+#             */
/*   Updated: 2021/08/15 20:10:59 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void)
{
	pid_t	pid;

	pid = getpid();
	if (pid == -1)
		return (1);
	if (!pid)
	{
		while (1)
		{
			printf("Hello\n");
			usleep(50000);
		}
	}
	else
	{
		sleep(1);
		kill(pid, SIGKILL);
	}
	return (0);
}
