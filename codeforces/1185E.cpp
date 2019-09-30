#include <iostream>
using namespace std;
 
int T;
int N,M;
int xma[1005],xmi[1005],yma[1005],ymi[1005];
char A[2005][2005];
int K;
bool flag;
 
int main(){
	cin>>T;
	while(T--){
 
		cin>>N>>M;
 
		K=0;
		flag=true;
		for(char c='a';c<='z';c++){
			xma[c]=yma[c]=-1;
			xmi[c]=N;
			ymi[c]=M;
		}
 
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++){
				cin>>A[i][j];
				xmi[A[i][j]]=min(xmi[A[i][j]],i);
				xma[A[i][j]]=max(xma[A[i][j]],i);
				ymi[A[i][j]]=min(ymi[A[i][j]],j);
				yma[A[i][j]]=max(yma[A[i][j]],j);
			}
 
		for(char c='z';c>='a';c--){
 
			if(xma[c]==-1 and !K)
				continue;
			K=max(K,c-'a'+1);
 
			if(xmi[c]==xma[c])
				for(int i=xmi[c],j=ymi[c];j<=yma[c];j++){
					if(A[i][j]!=c and A[i][j]!='$')
						flag=false;
					A[i][j]='$';
				}
			else if(ymi[c]==yma[c])
				for(int i=xmi[c],j=ymi[c];i<=xma[c];i++){
					if(A[i][j]!=c and A[i][j]!='$')
						flag=false;
					A[i][j]='$';
				}
			else if (xma[c]==-1){
				xmi[c]=xmi[c+1];
				xma[c]=xma[c+1];
				ymi[c]=ymi[c+1];
				yma[c]=yma[c+1];
			}
			else
				flag=false;
 
		}
 
		if(!flag)
			cout<<"NO\n";
		else{
			cout<<"YES\n"<<K<<"\n";
			for(int i=0;i<K;i++)
				cout<<xmi['a'+i]+1<<" "<<ymi['a'+i]+1<<" "<<xma['a'+i]+1<<" "<<yma['a'+i]+1<<"\n";
		}
	}
}