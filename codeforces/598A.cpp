#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
 
long long f(int y)
{
	
	long long k=1;
	while(k<=y)
		k=2*k;
	
	return k;	
 
}
 
int main()
{
	
	long long T,N;
	
	cin>>T;
	
	for(int h=0;h<T;h++)
	{
		
		cin>>N;
		//cout<<(N*(N+1))/2-2*f(N-1)-2;
		cout<<(N*(N+1))/2-2*f(N)+2<<"\n";
		
		
	}
	
}
 
 