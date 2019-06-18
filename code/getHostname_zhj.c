/***** Info *****/
/* Author: zhj */
/* Function: 得到主机名*/
/***** Info *****/
#include <stdio.h>
void getHostname_zhj(){
        /* Note： max_name_len是主机名最大的长度*/
        /*这里定义为40*/
        const max_name_len=40;
	char hostname[max_name_len];
	gethostname(hostname,max_name_len);
	printf("%s\n",hostname);
}

int main()
{
    	getHostname_zhj();
    	return 0;
}
