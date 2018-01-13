#include <stdio.h>
#include <unistd.h>

int main() {
	printf("Main before fork()\n");
	int pid = fork();
	if (pid == 0) {
	int pid1 = fork();
		if (pid1 == 0){
			char *args[]= { "/bin/ps", "-ef" , NULL};
			execvp("/bin/ps", args);
		}	
		else {
			char*args[]= { "/bin/free", "-h" ,NULL};
			execvp("/bin/free", args);
		}
	}
	return 0;
}


	
