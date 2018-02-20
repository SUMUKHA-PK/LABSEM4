#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORT 8080
int main(int argc,char const *argv[])
{
	int sockdes,new_sock,val;
	struct sockaddr_in address;
	int opt=1;
	int addrlen=sizeof(address);
	char buf[1024]={0};
	char* mess="This is a message from the server!";
	//Creation of a socket
	if((sockdes=socket(AF_INET,SOCK_STREAM,0))==0) //AF_INET for IPV4 protocol, AF_INET6 for IPV6//SOCK_STREAM for TCP(connection based and reliable)//protocol value for internetprotocol(IP) is 0.
		{
			perror("Socket failed to create\n");
			exit(EXIT_FAILURE);
		}
	//This and bind is where the socket is attached to the port 8080
	if(setsockopt(sockdes,SOL_SOCKET,SO_REUSEADDR|SO_REUSEPORT,&opt,sizeof(opt))) //int setsockopt(int sockfd, int level, int optname,const void *optval, socklen_t optlen);
		{ //SOL_SOCKET is the socket layer
			perror("Setsockopt: "); //not necessary but helps in reuse of address and port, prevetns errors such as "address is already in use"
			exit(EXIT_FAILURE);
		}
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=INADDR_ANY; // binds the socket to all other interfaces
	address.sin_port=htons(PORT); //  htons converts values between host and network(to maintain uniformity of littel-endian and big-enndian format etc)
	if(bind(sockdes,(struct sockaddr*)&address,sizeof(address))<0) //int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
		{	
			perror("Bind failed: ");
			exit(EXIT_FAILURE);
		}
	if(listen(sockdes,3)<0) // int listen(int sockfd, int backlog); // Puts the server in the passive mode,waits for client connection. //The backlog describes the largest length to which the queue for  pending connections for the socket descriptor can grow.
		{
			perror("Listening error: ");
			exit(EXIT_FAILURE);
		}
	if(new_sock=accept(sockdes,(struct sockaddr*)&address,(socklen_t*)&addrlen)<0) //int new_socket= accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
		{   //Extracts first pending connection from listening socket, creates new socket and return the file descriptor of the new socket.This is the point where  connection is established between the server and the client and ready to exchange data
			perror("Accept: ");
			exit(EXIT_FAILURE);
		}
	val=read(new_sock,buf,1024);
	printf("%s\n",buf);
	send(new_sock,mess,strlen(mess),0);
	printf("Message sent from server\n");
	return 0;
}