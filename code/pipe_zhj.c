/***** Info *****/

/* Author: zhj */

/* Function: 实现管道*/

/***** Info *****/

#include<stdio.h>

#include<unistd.h>

void pipe_zhj(){

        /*测试用例*/

        char *cmd[10];
	char * param1[]={"",0};
	char * param2[]={"-l",".c",0};

        cmd[0]="ls";

        cmd[1]="grep";

/*1.创建管道*/

        int pid;

        int fd[2];//fd[0]读端，fd[1]写端

        pipe(fd);
	int flag;

//2.创建子进程

        if((pid=fork())==0){

        //子进程，默认为pipe后的指令

                dup2(fd[0],0);//把标准输入流重定向到管道读端

                close(fd[0]);//关闭管道的文件描述符

                close(fd[1]);

                if((flag=execvp(cmd[0],param1))<0){

                        printf("son:no such command %d",flag);

                }

		exit(0);

        }

        else{

        //父进程，默认为pipe前的指令
		printf("/*******father*******/\n");



                //close(fd[0]);

                //close(fd[1]);

                waitpid(pid,NULL,0);
		dup2(fd[1],1);
                close(fd[0]);
		close(fd[1]);
                if((flag=execvp(cmd[1],param2))<0){

                        printf("father:no such command %d",flag);

                }

		exit(0);

        }

}



int main(){

        pipe_zhj();

        return 0;

}
