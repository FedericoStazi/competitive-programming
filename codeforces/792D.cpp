#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
 
long long N,x;
 
long long K(long long n)
{
	
	long long k=1;
	while(true)
	{
		
		if(n%k!=0)
			return k/2;
		else
			k=2*k;
		
	}
	
}
 
long long L(long long n)
{
	
	x=K(n);
	if(x==1)
		return n;
	else 
		return n-(x/2);
	
}
 
long long R(long long n)
{
	
	x=K(n);
	if(x==1)
		return n;
	else 
		return n+(x/2);
	
}
 
long long U(long long n)
{
	
	x=K(n);
	if(n==(N+1)/2)
		return n;
	else if((n/x)%4==1)
		return n+x;
	else 
		return n-x;
	
}
 
int main()
{
	
	long long Q,P;
	string str;
	
	cin>>N>>Q;
	
	for(int j=0;j<Q;j++)
	{
		
		cin>>P>>str;
		
		for(int i=0;i<str.size();i++)
		{
			
			if(str[i]=='U')
				P=U(P);
			else if(str[i]=='L')
				P=L(P);
			else 
				P=R(P);
			
		}
		
		cout<<P<<"\n";
		
	}
	
}
  