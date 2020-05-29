#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LEN 100 /* The maximum length command */

int main(void) {
	char *args[MAX_LEN / 2 + 1]; /* command line arguments */
	int should_run = 1;
	int background = 0;
	pid_t pid;
	int status;
	char *cmd[MAX_LEN];
	char *p;
	int i;

	while(should_run) {
redo:
		printf("my_shell> ");
		fflush(stdout);

		fgets(*args, MAX_LEN, stdin);

		if(strcmp(*args,"\n") == 0) goto redo;
		else p = strtok(*args, " \n");

		if(p == NULL) goto redo;

		i = 0;
		while(p) {
			if(strcmp(p, "&") == 0) {
				background = 1;
				goto jump;
			}
			cmd[i] = p;
			i++;
jump:
			p = strtok(NULL, " \n");
		}
		cmd[i] = NULL;
		if(strcmp(cmd[0],"exit") == 0) goto end;
		/**
		 * 표준입출력으로부터 문자열을 입력 받은 후:
		 * (1) fork()를 통해 자식 프로세스를 생성
		 * (2) 자식 프로세스가 execvp()를 호출하도록 할 것
		 * (3) 만약 입력받은 문자에 &가 포함되어 있으면,
		 *     부모 프로세스는 wait() 호출하지 않음
		 */
		pid = fork();
		if (pid < 0) {
			fprintf(stderr, "Fork failed\n");
			return 1;
		}
		else if(pid == 0) {
			execvp(cmd[0], cmd);
			printf("/'execlp/' call was unsuccessfull\n");
		}
		else {/*부모 프로세스*/
			if(background == 1) {
				printf("waiting for child, background progress\n");
				background = 0;
				waitpid(pid, &status, 0);
			}
			else {
				printf("not a background progress\n");
			}
		}
	}
end:
	return 0;
}
