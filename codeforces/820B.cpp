#define INF 1000000
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
using namespace std;
//ifstream in("input.txt");
//ofstream out("output.txt");
 
double N,A,C,sol;
 
int main()
{
 
	
	cin>>N>>A;
	
	C=180/N;
	sol=1;
	
	for(double i=2;i<N-1;i++)
		if(abs(A-C*i)<abs(A-C*sol))
			sol=i;
	
	cout<<1<<" "<<N<<" "<<1+sol;
	
	
}