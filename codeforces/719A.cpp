#include <stdio.h>
 
//using namespace std;
 
int main()
{
	
	int N,a,b;
	
	scanf("%d",&N);
	
	if(N==1)
	{
		
		scanf("%d",&a);
		
		if(a==0)printf("UP");
		else if(a==15)printf("DOWN");
		else printf("-1");
		
	}
	else 
	{
		
		for(int i=0;i<N-2;i++)
		{
		
			scanf("%d",&a);	
		
		}
	
		scanf("%d",&a);
		scanf("%d",&b);
		
		if(b==15)printf("DOWN");
		else if(b==0)printf("UP");
		else
		{
			
			if(b>a)printf("UP");
			else if(b<a)printf("DOWN");			
			
		}
		
		
	}
	
}