#include <sys/syscall.h>
#define SYSCALL_NUMBER 332

int main(void)
{

	syscall(SYSCALL_NUMBER);
	return 0;
}
