#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
int n,m,L,V;
int cd[100005],ca[100005],cv[100005],pp[100005];

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		int rrpp=0;
		short flag;
		int ans1=0;
		for(int i=0;i<n;i++){
			cin>>cd[i]>>cv[i]>>ca[i];
			if(i==0){
				if(ca[i]<0)flag=1;
				else if(ca[i]>0)flag=2;
				else if(ca[i]==0)flag=0;
			}
		}
		for(int i=0;i<m;i++){
			cin>>pp[i];
			if(pp[i]>rrpp)rrpp=pp[i];
		}
		if(flag==0){
			for(int i=0;i<n;i++){
				if(cd[i]<=rrpp && cv[i]>V)ans1++;
			}
			if(ans1==0)cout<<0<<' '<<m<<endl;
			else cout<<ans1<<' '<<m-1<<endl;
		}
		else if(flag==2){
			for(int i=0;i<n;i++){
				if(cd[i]<=rrpp &&(cv[i]>V || (long long)((rrpp-cd[i])*ca[i]*2)+(long long)(cv[i]*cv[i])>(long long)(V*V)))ans1++;
			}
			if(ans1==0)cout<<0<<' '<<m<<endl;
			else cout<<ans1<<' '<<m-1<<endl;
		}
	}
	return 0;
}
			
		
		
	
