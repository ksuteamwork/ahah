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
#define SERVER_IP	"192.168.128.95"

int main(int argc,char*argv[]){
int s,len;
int ch,ch1,ch2,ret=0,a,b,c;
struct sockaddr_in addr;
char buffer[1024];
//int re=0;
unsigned short ip,port,file;
//int addr_len = sizeof(struct sockaddr_in);
FILE *fp;

if((s=socket(AF_INET,SOCK_STREAM,0))<0){
perror("socket");
exit(1);
}
bzero(&addr,sizeof(addr));
addr.sin_family = AF_INET;

ch1 = getopt(argc, argv, "p:");
b = sscanf(optarg,"%hu",&port);
addr.sin_port = htons(atoi(optarg));

ch = getopt(argc, argv,"i:");
a = sscanf(optarg,"%hu",&ip);
addr.sin_addr.s_addr = inet_addr(optarg);

if(connect(s,(struct sockaddr*)&addr,sizeof(addr))<0){
perror("connect");
exit(1);
}
ch2 = getopt(argc, argv, "r:");
 c = sscanf(optarg,"%hu",&file);
sprintf(buffer,"GET /%s Http/1.1\r\n"
	       "User-Agent: wget/1.17.1 (linux-gnu)\r\n"
	       "Host:192.168.128.95\r\n"
	       "Accept: */*\r\n"
	       "Accept-Encoding: identity\r\n"
	       "Connection: Keep-Alive\r\n\r\n",optarg);

write(s,buffer,sizeof(buffer));
bzero(buffer,sizeof(buffer));
recv(s,buffer,sizeof(buffer),0);
printf("%s",buffer);

bzero(buffer,sizeof(buffer));
fp=fopen("2.txt","w");
//do{
  fprintf(fp,"%s",buffer);
  printf("%s\n",buffer);

bzero(buffer,sizeof(buffer));

 // }while((len = recv(s,buffer,sizeof(buffer),0)) > 0);

//system("Pause");
//perror("send");
exit(1);

}

  //read(s,buffer,sizeof(buffer));
//fp=fopen("2.txt","r");

  //re+=sprintf(buffer+re,"sizeof(buffer)");
// if(strlen(buffer) >= 3333058 )
//  break;
//bzero(buffer,sizeof(buffer));


//addr_len = recvfrom(s,buffer,sizeof(buffer),0,(struct sockaddr *)&addr,&addr_len);
//printf("%s\n",buffer);
//read(STDIN_FILENO,buffer,sizeof(buffer));
//read(STDIN_FILENO,buffer,sizeof(buffer));
//sendto(s,buffer,len,0,(struct sockaddr *)&addr,addr_len);
//printf("receive: %s",buffer);
//if(send(s,buffer,sizeof(buffer),0)<0){
