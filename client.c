#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc , char*argv[])
{
	int sock;
	struct sockaddr_in server;
	char message[1000] , server_reply[2000];

	sock = socket(AF_INET, SOCK_STREAM , 0);
	if(sock == -1)
	{
		printf("Could no create socket");
	}
	puts("Socket created");

	server.sin_addr.s_addr = inet_addr("192.168.174.129");
	server.sin_family = AF_INET;
	server.sin_port = htons(22000);
	if(connect(sock , (struct sockaddr *)&server , sizeof(server))<0)
	{
		perror("connect failed. error");
		return 1;
	}
	puts("connected\n");

	while(1)
	{
		printf("enter message : ");
		scanf("%s" , message);

		if(send(sock , message , strlen(message) , 0) < 0)
		{
			puts("send failed");
			return 1;
		}
		if(recv(sock , server_reply , 2000 , 0) < 0)
		{
			puts("recv failed");
			break;
		}
		puts("Server reply : ");
		puts(server_reply);
	}
	close(sock);
	return 0;
}
