#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,m,L,V,count=0;
		cin>>n>>m>>L>>V;
		int d[n],v,a[n];
		for(int i=0;i<n;i++){
			cin>>d[i]>>v>>a[i];
			if(v>3) count++;
		}
		cout<<count<<" "<<m-1<<endl;
	}
	return 0;	
}
