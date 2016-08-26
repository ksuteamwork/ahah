
#include <stdio.h>
#include <string.h>



void bsort(int *src, int len)
{
 int i,  j, tem;
 for(i=0;i<len;i++)
	{
	 for(j=0;j<len-1-i;j++)
	 {
	  if(src[j] > src[j+1])
	  {
	   tem = src[j];
	   src[j] = src[j+1];
	   src[j+1] = tem;
	  }}}
}

void ssort(int *src, int len)
{
 int i,  j, tem;
 for(i=0;i<len;i++)
	{
	 for(j=0;j<len-1-i;j++)
	 {
	  if(src[j] < src[j+1])
	  {
	   tem = src[j];
	   src[j] = src[j+1];
	   src[j+1] = tem;
	  }}}
}

int main()
{
 
 int x[5] = {31, 25, 75, 33, 42};
	printf("How many numbers in the case? = %d\n",sizeof(x)/4);
	int c;
	scanf ("%d",&c);
	if(c==1)
	{
	 ssort(x, 5);
	 for(int i = 0; i < 5;i++)
	 printf("%d\n", x[i]);
	}
	if(c==2)
	{
	 bsort(x, 5);
	 for(int i = 0; i < 5;i++)
	 printf("%d\n",x[i]);
	}
  return 0;
}

