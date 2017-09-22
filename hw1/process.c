#include "process.h"
#include "shell.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <termios.h>
#include "parse.h"
#include <string.h>

/**
 *  Executes the process p.
 *  If the shell is in interactive mode and the process is a foreground process,
 *  then p should take control of the terminal.
 *
 */
void launch_process(process *p) {
    /** TODO **/
	
   if(execv(p->argv[0],p->argv) == -1){
	char path_way[1024] = "";
	strcat(path_way,getenv("PATH"));
	tok_t *direc = getToks(path_way);
	int u = 0;
		while(direc[u] !=NULL){
			char filepath[1024] = "";
			strcat(filepath,direc[u]);
			 strcat(filepath,"/");
			  strcat(filepath,p->argv[0]);
		if(execv(filepath, p->argv) != -1){
		continue;
		}
	u++;
	}

	printf("Could not execute '%s' : No such file or directory\n",p->argv[0]);
	exit(1);		
	}
}

/**
 *  Put a process in the foreground. This function assumes that the shell
 *  is in interactive mode. If the cont argument is true, send the process
 *  group a SIGCONT signal to wake it up.
 *
 */
void put_process_in_foreground (process *p, int cont) {
    /** TODO **/
}

/**
 *  Put a process in the background. If the cont argument is true, send
 *  the process group a SIGCONT signal to wake it up. 
 *
 */
void put_process_in_background (process *p, int cont) {
    /** TODO **/
}

/**
 *  Prints the list of processes.
 *
 */
void print_process_list(void) {
    process* current = first_process;
    while(current) {
        if(!current->completed) {
            printf("\n");
            printf("PID: %d\n",current->pid);
            printf("Name: %s\n",current->argv[0]);
            printf("Status: %d\n",current->status);
            printf("Completed: %s\n",(current->completed)?"true":"false");
            printf("Stopped: %s\n",(current->stopped)?"true":"false");
            printf("Background: %s\n",(current->background)?"true":"false");
            printf("Prev: %lx\n",(unsigned long)current->prev);
            printf("Next: %lx\n",(unsigned long)current->next);
        }
        current=current->next;
    }
}






















