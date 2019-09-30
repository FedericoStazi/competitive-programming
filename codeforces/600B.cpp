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
 
int N,M;
int A[200005],B[200005];
 
int main()
{
	
	cin>>N>>M;
	
	for(int i=0;i<N;i++)
		cin>>A[i];
	for(int i=0;i<M;i++)	
		cin>>B[i];
		
		sort(A,A+N);
	
	for(int i=0;i<M;i++)
	cout<<upper_bound(A,A+N,B[i])-A<<" ";
	
}