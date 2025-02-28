#include <stdio.h>
#include<sys/types.h>  //fork, sleep, getpid, getppid
#include<sys/wait.h>    //system call - wait
#include<stdlib.h>
#include<unistd.h>


int main()
{	
	pid_t cpid;			//Declaring a variable cpid with the pid_t data type
	int  *status=NULL;	//Intilizating a pointer var status to NULL
	
	cpid = fork();			//The process fork_wait creates a new process --clone

	if( cpid == 0 ) { //CHILD PROCESS as it is not creating any new process
		printf("\n*************** This is child process ***************\n "); //write sys call

		printf("\n\t Process id is : %d", getpid());
		printf("\n\t Parent's process id is : %d", getppid());
		sleep(15);
			
		printf("\n*************Child process terminates ***************\n");			
	}
	else { /*Parent process waiting for child process, to complete the task*/
	
		printf("\n\t My process id is : %d", getpid());
		printf("\n\t My Parent process id is : %d", getppid());
		cpid = wait(status); //Forceful wait; that collects the exit status of child process with cpid		

		printf("\n\n\t Parent process collected the exit status of child process with PID %d\n\n", cpid);
	}//end of if-else

	return 0;	
}//end of main
