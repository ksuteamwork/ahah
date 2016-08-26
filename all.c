#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<strings.h>

#define PORT 1234
#define MAXSOCKFD 10

/*void sort(int *src, int len)
{
 int i, j,tem;
 for(i=0;i<len;i++){
  for(j=0;j<len-1-i;j++){
   if(src[j] > src[j+1]){
   tem = src[j];
   src[j+1] = tem;
}}}
}*/

int main(){

int sockfd,newsockfd,is_connected[MAXSOCKFD],fd;
struct sockaddr_in addr;
int addr_len = sizeof(struct sockaddr_in);
//fd_set readfds;
char buffer[256];
char msg[]="Which function do you need?(1)sorting (2)!";

int len;

//if((sockfd = socket(AF_INET,SOCK_STREAM,0))<0){
if((sockfd = socket(AF_INET,SOCK_DGRAM,0))<0){
 perror("socket");
 exit(1);
}
bzero(&addr,sizeof(addr));
addr.sin_family= AF_INET;
addr.sin_port=htons(PORT);
addr.sin_addr.s_addr=htonl(INADDR_ANY);
//if(bind(sockfd, (struct sockaddr*)&addr,sizeof(addr))<0){
if(bind(sockfd,&addr,sizeof(addr))<0){
perror("connect");
exit(1);
}
/*if(listen(sockfd,3)<0){
 perror("listen");
 exit;
}*/

while(1){
 bzero(buffer,sizeof(buffer));
 len = recvfrom(sockfd,buffer,sizeof(buffer),0,&addr,&addr_len);
 printf("receive from %s\n",inet_ntoa(addr.sin_addr));
 sendto(sockfd,buffer,len,0,&addr,addr_len);
}

/*if((s=socket(AF_INET,SOCK_STREAM,0))<0){
recv(s,buffer,sizeof(buffer),0);
printf("%s\n",buffer);
}*/


/*for(fd=0;fd<MAXSOCKFD;fd++)
 is_connected[fd]=0;
while(1){
FD_ZERO(&readfds);
FD_SET(sockfd,&readfds);
for(fd=0;fd<MAXSOCKFD;fd++)
 if(is_connected[fd]) FD_SET(fd,&readfds);

if(!select(MAXSOCKFD,&readfds,NULL,NULL,NULL))continue;

for(fd=0;fd<MAXSOCKFD;fd++)
if(FD_ISSET(fd,&readfds)){
*/

/*
 if(sockfd == fd){

 if((newsockfd=accept(sockfd,(struct sockaddr*)&addr,&addr_len))<0)
 perror("accept");
 write(newsockfd,msg,sizeof(msg));
 is_connected[newsockfd]=1;
 printf("Connect from %s\n",inet_ntoa(addr.sin_addr));
}
else{
bzero(buffer,sizeof(buffer));*/

//if(sizeof(buffer) == 2){



if(read(fd,buffer,sizeof(buffer))<=0){
 printf("Connection closed\n");
 is_connected[fd]=0;
 close(fd);
}
else
printf("%s",buffer);



}


