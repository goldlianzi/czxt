/***** Info *****/
/* Author: zhj */
/* Function: 得到用户名username*/
/***** Info *****/
#include <stdio.h>
#include <string.h>
#include <pwd.h>
void getUsername_zhj(){
        /* Note： max_name_len是用户名最大的长度*/
        /*这里定义为40*/
        const max_name_len=40;
        char username[max_name_len];
        struct passwd* pwd = getpwuid(getuid());
        strcpy(username, pwd->pw_name);
        printf("%s\n",username);
}

int main()
{
    	getUsername_zhj();
    	return 0;
}
