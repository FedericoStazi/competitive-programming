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
#include <list>
#include <map>
using namespace std;
 
//ifstream in("input.txt");
//ofstream out("output.txt");
 
typedef long long ll;
ll N,A,B,P,Q;
 
ll GCD(ll a,ll b)
{
	
	if(b==0)
		return a;
	else
		return GCD(b,a%b);
	
}
 
int main()
{
	
	cin>>N>>A>>B>>P>>Q;
	
	cout<<((long long)(N/A)*P+(long long)(N/B)*Q-(long long)(N/((A*B)/GCD(A,B)))*min(P,Q));
	
}
 