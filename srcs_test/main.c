#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
size_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

void	strlen_test(char *s)
{
	int my, ori;

	printf("str: %s\n", s);
	my = ft_strlen(s);
	ori = strlen(s);
	printf("home made rtv: %d\n", my);
	printf("original rtv : %d\n", ori);
	printf("\t\t%s\n", my == ori ? "\x1b[32mOK" : "\x1b[31mKO");
	printf("\x1b[39m");
}

void	strcpy_test(char *s)
{
	char	ori_buf[1024];
	char	my_buf[1024];
	char	*ori, *my;

	printf("str: %s\n", s);
	my = ft_strcpy(my_buf, s);
	ori = strcpy(ori_buf, s);
	printf("home made rtv: %s\n", my);
	printf("original rtv : %s\n", ori);
	printf("\t\t%s\n", (!strcmp(ori_buf, my_buf) && !strcmp(ori, my)) ? "\x1b[32mOK" : "\x1b[31mKO");
	printf("\x1b[39m");
}

void	strcmp_test(char *s1, char *s2)
{
	int ori, my;

	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	my = ft_strcmp(s1, s2);
	ori = strcmp(s1, s2);
	printf("home made rtv: %d\n", my);
	printf("original rtv : %d\n", ori);
	printf("\t\t%s\n", (ori == my ? "\x1b[32mOK" : "\x1b[31mKO"));
	printf("\x1b[39m");
}

void	write_test(char *filename, char *s, int len)
{
	int my, ori;
	int my_errno, ori_errno;
	int fd;

	printf("str: %s\n", s);
	printf("len: %d\n", len);
	write(1, "home made output: ", 18);
	if (filename != NULL)
		fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);
	else
		fd = 1;
	my = ft_write(fd, s, len);
	if (filename != NULL)
		close(fd);
	my_errno = errno;
	printf("\n");
	if (filename != NULL)
		fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);
	else
		fd = 1;
	write(1, "original output : ", 18);
	ori = write(fd, s, len);
	if (filename != NULL)
		close(fd);
	ori_errno = errno;
	printf("\n");
	printf("home made rtv & errno: %d %d\n", my, my_errno);
	printf("original rtv & errno : %d %d\n", ori, ori_errno);
	printf("\t\t%s\n", (ori == my && ori_errno == my_errno ? "\x1b[32mOK" : "\x1b[31mKO"));
	printf("\x1b[39m");
}

void	write_errno_test(int fd, char *s, int len)
{
	int my_errno, ori_errno;
	int my, ori;

	my = ft_write(fd, s, len);
	my_errno = errno;
	ori = write(fd, s, len);
	ori_errno = errno;
	printf("home made rtv & errno: %d %d\n", my, my_errno);
	printf("original rtv & errno : %d %d\n", ori, ori_errno);
	printf("\t\t%s\n", (ori == my && ori_errno == my_errno ? "\x1b[32mOK" : "\x1b[31mKO"));
	printf("\x1b[39m");
}

void	read_test(char *filename, int len)
{
	int my, ori;
	int my_errno, ori_errno;
	char my_buf[1024], ori_buf[1024];
	int fd;

	printf("len: %d\n", len);
	if (filename != NULL)
		fd = open(filename, O_RDONLY);
	else
		fd = 0;
	my = ft_read(fd, my_buf, len);
	my_errno = errno;
	if (filename != NULL)
		close(fd);
	my_buf[my] = 0;
	if (filename != NULL)
		fd = open(filename, O_RDONLY);
	else
		fd = 0;
	ori = read(fd, ori_buf, len);
	ori_errno = errno;
	if (filename != NULL)
		close(fd);
	ori_buf[ori] = 0;
	printf("home made rtv & buf & errno: %d %s %d\n", my, my_buf, my_errno);
	printf("original rtv & buf & errno : %d %s %d\n", ori, ori_buf, ori_errno);
	printf("\t\t%s\n", (ori == my && ori_errno == my_errno ? "\x1b[32mOK" : "\x1b[31mKO"));
	printf("\x1b[39m");
}

void	read_errno_test(int fd, char *s, int len)
{
	int ori, my;
	int ori_errno, my_errno;

	ori = read(fd, s, len);
	ori_errno = errno;
	my = ft_read(fd, s, len);
	my_errno = errno;
	printf("home made rtv & errno: %d %d\n", my, my_errno);
	printf("original rtv & errno : %d %d\n", ori, ori_errno);
	printf("\t\t%s\n", (ori == my && ori_errno == my_errno ? "\x1b[32mOK" : "\x1b[31mKO"));
	printf("\x1b[39m");
}

void	strdup_test(char *s)
{
	char *my_buf, *ori_buf;
	printf("str: %s\n", s);

	my_buf = ft_strdup(s);
	ori_buf = strdup(s);
	printf("home made rtv: %s\n", my_buf);
	printf("original rtv : %s\n", ori_buf);
	printf("\t\t%s\n", (!strcmp(my_buf, ori_buf) ? "\x1b[32mOK" : "\x1b[31mKO"));
	printf("\x1b[39m");
	free(ori_buf);
	free(my_buf);
}

int main()
{
	char *str1 = "";
	char *str2 = "hello";
	char *str3 = "123456789012345678901234567890123456789012";
	char buf1[1024];
	char buf2[1024];
	char buf3[1024];

	printf("==========> ft_strlen <==========\n");

	strlen_test(str1);
	strlen_test(str2);
	strlen_test(str3);

	printf("==========> ft_strcpy <==========\n");

	strcpy_test(str1);
	strcpy_test(str2);
	strcpy_test(str3);

	printf("==========> ft_strcmp <==========\n");

	strcmp_test(str1, str1);
	strcmp_test(str1, str2);
	strcmp_test(str1, str3);
	strcmp_test(str2, str1);
	strcmp_test(str2, str2);
	strcmp_test(str2, str3);
	strcmp_test(str3, str1);
	strcmp_test(str3, str2);
	strcmp_test(str3, str3);

	printf("==========> write <==========\n");

	write_test(NULL, str1, ft_strlen(str1));
	write_test(NULL, str2, ft_strlen(str2));
	write_test(NULL, str3, ft_strlen(str3));

	int fd = open("write_test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE);
	write_test("write_test.txt", str3, ft_strlen(str3));
	close(fd);

	ft_write(-1, "test", 5);

	write_errno_test(-1, str1, ft_strlen(str1));
	write_errno_test(1, str1, -2);
	write_errno_test(1, NULL, 1);

	printf("==========> read <==========\n");

	size_t n;

	read_test("srcs_test/a.txt", 0);
	read_test("srcs_test/b.txt", 5);
	read_test("srcs_test/c.txt", 42);

	// read_test(NULL, 1024);

	fd = open("srcs_test/c.txt", O_RDONLY);
	read_errno_test(42, buf1, ft_strlen(str3));
	read_errno_test(fd, buf1, -2);
	read_errno_test(fd, (char *)42, 1);
	close(fd);

	printf("==========> ft_strdup <==========\n");

	strdup_test(str1);
	strdup_test(str2);
	strdup_test(str3);
}
