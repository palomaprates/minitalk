#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void	teste1()
{
	write(1, "1", 1);
}
int main()
{
	__pid_t server_pid = getpid();
	printf("%d\n", server_pid); //lembrar que nao posso usar o printf
				signal(SIGUSR1, teste1);
			while(1){
			}
}
