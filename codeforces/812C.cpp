#define INF 1000000
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
//ifstream in("input.txt");
//ofstream out("output.txt");
 
long long N,S;
long long top,bot,mid,tot;
long long A[100005],B[100005];
long long tot1,tot2;
 
int main()
{
	
	cin>>N>>S;
	
	for(int i=0;i<N;i++)
		cin>>A[i];
		
	bot=0;
	top=N;
	
	while(top>1+bot)
	{
		
		mid=(int)((bot+top)/2);
		
		//cout<<bot<<" "<<mid<<" "<<top<<"\n";
		
		for(int i=0;i<N;i++)
			B[i]=A[i]+(i+1)*mid;
 
		sort(B,B+N);
		
		tot=0;
		
		for(int i=0;i<mid;i++)
			tot+=B[i];
			
		if(tot<S)
			bot=mid;
		else if (tot>S)
			top=mid-1;
		else
			bot=mid;
		
		
	}
	
		
	mid=bot;
		
	for(int i=0;i<N;i++)
		B[i]=A[i]+(i+1)*mid;
		
	sort(B,B+N);
		
	tot1=0;
		
	for(int i=0;i<mid;i++)
		tot1+=B[i];
		
	//************************************
		
	mid=top;
		
	for(int i=0;i<N;i++)
		B[i]=A[i]+(i+1)*mid;
		
	sort(B,B+N);
		
	tot2=0;
		
	for(int i=0;i<mid;i++)
		tot2+=B[i];
 
	
	if(top>bot and tot2<=S)
		cout<<top<<" "<<tot2;
	else 
		cout<<bot<<" "<<tot1;
 
}
 