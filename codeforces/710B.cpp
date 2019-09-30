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
 
int N,A[1000000];
 
int main()
{
 
 
	cin>>N;
	
	for(int i=0;i<N;i++)
		cin>>A[i];
		
	sort(A,A+N);
	
	if(N%2==0)
		cout<<A[N/2-1];
	else
		cout<<A[(N-1)/2];
	
}