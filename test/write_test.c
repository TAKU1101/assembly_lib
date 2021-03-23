#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int main(void)
{
	write(1, (const void *)42, 12);
	printf("%d\n", errno);
}
