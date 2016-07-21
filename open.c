
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bots(int *arr,int len)
{
 int temp;
 for(int i=0;i<len;i++) {
    for(int j=0;j<len-1-i;j++) {
	if(arr[j]>arr[j+1]) {
	temp = arr[j];
	arr[j] = arr[j+1];
	arr[j+1] = temp;
} } } }
void sort(int *arr,int len)
{
 int temp;
 for(int i=0;i<len;i++) {
    for(int j=0;j<len-1-i;j++) {
	if(arr[j]<arr[j+1]) {
	temp = arr[j];
	arr[j] = arr[j+1];
	arr[j+1] = temp;
} } } }



int main()
{
 FILE *fPtr, *fp;
	int c,x,i=0;
	int a[5];
	char ary[1024];
	fPtr = fopen("test.txt","r");
	fp = fopen("num.txt","w");

	printf("How many numbers in the case? = %d\n",sizeof(a)/4);
	memset(a,0,sizeof(a));
	while(fgets(ary, 1024,fPtr) !=NULL)
	{
	x=atoi(ary);
	a[i] = x;
	i++;
	printf("%d\n",x);
	}
	scanf("%d",&c);
	//printf("%s\n",ary);
	if(c == 1)
	{
	 bots(a, 5);
	 for(int i=0;i<5;i++)
	  printf("%d\n",a[i]);
	}
	if(c == 2)
	{
	 sort(a, 5);
	 for(int i=0;i<5;i++)
	  printf("%d\n",a[i]);
	}
	 for(int i=0;i<5;i++){
	  fprintf(fp,"%d\n",a[i]);
	}

fclose(fp);
	/*if(NULL == fPtr)
	{
	 printf("open fail\n");
	 return 1;
	}else
	 {
	  fread(ary, 1024, 1,fPtr);
	  printf("%s", ary);
	 }*/

 fclose(fPtr);

 //printf("How many numbers in the case? = %d\n",sizeof(ary));

//return 0;
}
/*void btos(int *src, int len)
{
 int tem;
  for (int i = 0;i < len;i++)

int main()
{
 op();
 printf("How many numbers in the case? = %d\n",sizeof(data));


return 0;
}
*/
