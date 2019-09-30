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
 
int main()
{
 
	int N,K=2,i=1,j=1;
	cin>>N;
	
	while(K<=N)
	{
		
		//cout<<K<<"\n";
		
		if(i%9==0)
			j=10*j;
			
		K+=j;		
		i++;
		
	}
	
	cout<<K-N;
	
}