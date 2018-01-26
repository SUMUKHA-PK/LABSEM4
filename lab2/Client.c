#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORT 8080
int main(int argc,char const *argv[])
{
	struct sockaddr_in address;
	int val,sock=0;
	struct sockaddr_in serv_addr;
	char *messn="This is a message from the Client";
	char buf[1024]={0};
	if((sock=socket(AF_INET,SOCK_STREAM,0))<0)
		{
			printf("Socket creation error!");
			return -1;
		}
	memset(&serv_addr,'0',sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(PORT);
	//Convert all the IPV4 and IPV6 addresses from text  to binary form
	if(inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr)<=0)
		{
			printf("\nInvalid address / Address not supported\n");
			return -1;
		}
	if(connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
	{
		printf("\nConnection failed\n");
		return -1;
	}
	send(sock,messn,strlen(messn),0);	
	printf("Message sent from the Client\n");
	val=read(sock,buf,1024);
	printf("%s\nprint something",buf);
	return 0;
}