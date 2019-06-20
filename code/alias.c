#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_CMD_LEN 100

struct Record
{
        char word[MAX_CMD_LEN];
        char mean[MAX_CMD_LEN];
};

struct Node
{
        struct Record data;
        struct Node *next;
};

static struct Node dictionary;
static struct Node* head = &dictionary;
static struct Node* currentRecord;
int flag=0;
char substitute_result[MAX_CMD_LEN];

struct Node* alias(struct Node* currentRecord){
        struct Node* p=currentRecord;
        struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
        //p = (struct Node*)malloc(sizeof(struct Node));
        char str[50]="zhj='ls -l'";

        char *tmp;
        tmp=strtok(str,"=");
        strcpy((temp->data).word,tmp);
        tmp=strtok(NULL,"'");
        //printf("tmp:%s\n",tmp);
        strcpy((temp->data).mean,tmp);
        p->next=temp;
        p=p->next;
        p->next=NULL;
}

void printAlia_zhj(struct Node* head)
{
	struct Node* p = head;
	p = p->next;
	while(p!=NULL){
		printf("alias:%s=%s\n",(p->data).word,(p->data).mean);
		//printf("'%s'\n",(p->data).mean);
		p = p->next;
	}
 }

void if_alias(struct Node* head){
        struct Node* p=head;
        p=p->next;
        //printf("word is:%s\n",(p->data).word);
        char exam[50]="zhj";
        //char result[MAX_CMD_LEN];
        while(p!=NULL){
               if(strcmp(exam,(p->data).word)==0){
                        //printf("找到啦！");
                        strcpy(substitute_result,(p->data).mean);
                        flag=1;
                        break;
               }
               else
                p=p->next;
        }
        //printf("read_me");
}
int main(){
        currentRecord=head;
        currentRecord=alias(currentRecord);
        //currentRecord=alias2(currentRecord);
        printAlia_zhj(head);//打印链表数据
        if_alias(head);
        //printf("%d",flag);
        if(flag==1){
                //printf("substitute:%s\n",substitute_result);
                /*在这里将替换的指令copy给cmd_array[]再进行分析*/
        }
        return 0;
}
