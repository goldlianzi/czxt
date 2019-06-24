/**************这一部分放到全局变量****************/
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
/***********结束***************/

/**********************************************************************************	
在commandJudgeControl函数中分别调用alias_zhj()和unalias_zhj()即可
在getInputCommand函数的命令字符分割和链接重分割中间调用judge_alias()即可
/**********************************************************************************

/***** Info *****/
/* Author: ZHJ */
/* Function: 实现alias*/
void alias_insert(){
        struct Node* p=currentRecord;
        struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
        //p = (struct Node*)malloc(sizeof(struct Node));
        char str[MAX_CMD_LEN / 2];
	 strcpy(str,commandCompose[1]);

        char *tmp;
        tmp=strtok(str,"=");
        strcpy((temp->data).word,tmp);
        tmp=strtok(NULL,"'");
        //printf("tmp:%s\n",tmp);
        strcpy((temp->data).mean,tmp);
        p->next=temp;
        p=p->next;
        p->next=NULL;
	currentRecord=p;
}

void printAlia_zhj()
{
	struct Node* p = head;
	p = p->next;
	while(p!=NULL){
		printf("alias:%s='%s'\n",(p->data).word,(p->data).mean);
		//printf("'%s'\n",(p->data).mean);
		p = p->next;
	}
 }

void if_alias(char *findstr){
        struct Node* p=head;
        p=p->next;
        //printf("word is:%s\n",(p->data).word);
        char exam[MAX_CMD_LEN/2+1];
	strcpy(exam,findstr);
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

char * judge_alias(char *p){
	flag=0;
	static char resultStr[MAX_CMD_LEN];
	strcpy(resultStr,"");
	//strcpy(contentStr,p);
	char *target;
	char *tmp;
	//char *result = malloc(strlen(s1)+strlen(s2)+1);
	target=strtok_r(p," ",&tmp);
	//printf("%s\n",target);
	if_alias(target);
	//printf("%d\n",flag);
	if(flag==1){
                //printf("substitute:%s\n",substitute_result);
		strcpy(resultStr,substitute_result); 
                /*在这里将替换的指令copy给cmd_array[]再进行分析*/
	}
	strcat(resultStr,tmp);
	printf("%s",resultStr);
	return resultStr;
	
	//cut the command
	//flag=0;
	//printf("%d\n",flag);
}
void alias_zhj(){
	//currentRecord=head;
	//printf("%d\n",commandCompose[1]);
	//printf("%d\n",strlen(commandCompose[1]));
	if(!strcmp(commandCompose[1]," ")){
		printAlia_zhj();//print all the relations
	}
	else{
		alias_insert(currentRecord);//insert the relation
	}
}

/***** Info *****/
/* Author: ZHJ */
/* Function: 实现unalias*/
void unalias_zhj(){
        if_alias(commandCompose[1]);
        if(flag==0){
                printf("%s:not found",commandCompose[1]);
                return;
        }
	char deletestr[MAX_CMD_LEN/2+1];
	strcpy(deletestr,commandCompose[1]);
        //char deletestr[50]="ls";
        struct Node *p=head;
        //struct Node *tmp=(struct Node*)malloc(sizeof(struct Node));
        //tmp=p->next;
        //p=p->next;
        while((p->next)!=NULL){
                if(!strcmp(deletestr,((p->next)->data).word)){
                        p->next=(p->next)->next;
                        //printf("success");
                        //free(p->next);
                        break;
                }
                p=p->next;
        }
}
