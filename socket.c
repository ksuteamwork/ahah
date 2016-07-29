#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>

#define PORT	80
#define SERVER_IP	"192.168.128.65"


int main(){
int s;
struct sockaddr_in addr;
char buffer[1024];
int ret=0;

if((s=socket(AF_INET,SOCK_STREAM,0))<0){
perror("socket");
exit(1);
}
bzero(&addr,sizeof(addr));
addr.sin_family = AF_INET;
addr.sin_port = htons(PORT);
addr.sin_addr.s_addr = inet_addr(SERVER_IP);

if(connect(s,(struct sockaddr*)&addr,sizeof(addr))<0){
perror("connect");
exit(1);
}
//sprintf(buf ,	"GET/1.txt Http/1.1\r\n"
//		"Host:192.168.128.65\r\n"
//		"User-Agent: wget/1.17.1 (linux-gnu)\r\n"
//		"Accept:
//		"Accept-Encoding: identity\r\n"
//		"Connection: Keep-Alive\r\n\r\n",var);


ret+=sprintf(buffer+ret,"GET /1.txt Http/1.1\r\n");
ret+=sprintf(buffer+ret,"User-Agent: wget/1.17.1 (linux-gnu)\r\n");
ret+=sprintf(buffer+ret,"Host:192.168.128.65\r\n");
ret+=sprintf(buffer+ret,"Accept: */*\r\n");
ret+=sprintf(buffer+ret,"Accept-Encoding: identity\r\n");
ret+=sprintf(buffer+ret,"Connection: Keep-Alive\r\n\r\n");

write(s,buffer,sizeof(buffer));
bzero(buffer,sizeof(buffer));
recv(s,buffer,sizeof(buffer),0);
printf("%s\n",buffer);
//printf("hello world\n8787\n");
perror("send");
//while(1){
//if(send(s,buffer,sizeof(buffer),0)<0){
exit(1);

}

