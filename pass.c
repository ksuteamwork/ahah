#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
int i,j,a[2048],N=500;
memset(a,0,sizeof(a));
a[0]=1;
for(i=1;i<=N;i++){
  for(j=0;j<sizeof(a)/sizeof(a[0]);j++){
a[j]*=i;
}
for(j=0;j<sizeof(a)/sizeof(a[0])-1;j++){
  a[j+1]+=a[j]/10;
a[j]%=10;
 }
}
for(i=sizeof(a)/sizeof(a[0])-1;i>=0;i--){
if(a[i]!=0) break;
}
for(i;i>=0;i--){
printf("%d",a[i]);

 }
printf("\n");
}
