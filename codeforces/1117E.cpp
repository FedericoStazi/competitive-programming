#include <iostream>
#include <algorithm>
using namespace std;
 
int N;
string T,S;
int V[10005];
 
int main(){
 
	cin>>T;
	N=T.size();
	string Q(N,'a');
 
	for(int i=0;i<N;i++)
		Q[i]=i%26+'a';
	cout<<"? "<<Q<<"\n";
	fflush(stdout);
	cin>>S;
	for(int i=0;i<N;i++)
		V[i]+=(S[i]-'a')%26;
 
	for(int i=0;i<N;i++)
		Q[i]=(i/26)%26+'a';
	cout<<"? "<<Q<<"\n";
	fflush(stdout);
	cin>>S;
	for(int i=0;i<N;i++)
		V[i]+=26*((S[i]-'a')%26);
 
	for(int i=0;i<N;i++)
		Q[i]=((i/26)/26)%26+'a';
	cout<<"? "<<Q<<"\n";
	fflush(stdout);
	cin>>S;
	for(int i=0;i<N;i++)
		V[i]+=26*26*((S[i]-'a')%26);	
	
	//for(int i=0;i<N;i++)cout<<V[i]<<" ";
 
	for(int i=0;i<N;i++)
		Q[V[i]]=T[i];
	cout<<"! "<<Q<<"\n";
	fflush(stdout);
	
}