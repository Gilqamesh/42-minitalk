#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

int	main(void)
{
	uint16_t	c;
	int			d;
	char		first;
	char		second;

	c = 51637;
	d = 681;
	write(STDOUT_FILENO, &c, 2);
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, &d, 4);
	write(STDOUT_FILENO, "\n", 1);

	first = 202;
	second = 169;
	write(STDOUT_FILENO, &first, 1);
	write(STDOUT_FILENO, &second, 1);

	write(STDOUT_FILENO, "\n", 1);
	struct {
		char	first : 8;
		char	second : 8;
	} s_omega;
	s_omega.first = 206;
	s_omega.second = 152;
	write(STDOUT_FILENO, &s_omega, sizeof(s_omega));

	write(STDOUT_FILENO, "\n", 1);
	struct {
		int16_t	a;
	} s_omega2;
	s_omega2.a = 52888;
	write(STDOUT_FILENO, &s_omega2, sizeof(s_omega2));
	return (0);
}
