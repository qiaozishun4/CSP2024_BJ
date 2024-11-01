#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][1000],s,n[N],c[N][1000];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			int f;
			cin>>f;
			a[f][i]++;
			c[f][i]=f;
		}
	}
	for(int i=1;i<=t;i++){
		s=0;
		for(int j=1;j<=N;j++){
			if(a[j][i]>=2){
				s+=c[j][i];
				a[j][i]=0;
			}
		}
		cout<<s<<"\n";
	}
	return 0;
}
