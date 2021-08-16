#include "minitalk.h"
#include <limits.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (-1);
	len = 0;
	while (*str++)
		len++;
	return (len);
}

static int	ft_isspace(const char c)
{
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v' || c == ' ')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int			is_negative;
	long int	result;

	if (ft_isspace(*nptr))
		return (ft_atoi(nptr + 1));
	is_negative = 0;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			is_negative = 1;
	result = 0;
	while (*nptr && ft_isdigit(*nptr))
	{
		if (result >= LONG_MAX / 10)
		{
			if (is_negative)
				result = LONG_MIN;
			else
				result = LONG_MAX;
			return (result);
		}
		result = result * 10 + (*nptr++ - '0');
	}
	if (is_negative)
		return (-result);
	return (result);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 10 && n > -10)
	{
		if (n < 0)
		{
			write(fd, &(char){'-'}, 1);
			n *= -1;
		}
		write(fd, &(char){n + '0'}, 1);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	if (n < 0)
		n *= -1;
	write(fd, &(char){n % 10 + '0'}, 1);
}
