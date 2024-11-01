#include <bits/stdc++.h>
using namespace std;
long long int cnt1,flag[1000005][10000005],t,cnt,le[1000005],r[1000005],n,m,l,v,v1[100005],d[1000005],u[1000005],a[1000005];
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
	cin>>n>>m>>l>>v;
	for(int j=1;j<=n;j++){
	cin>>d[j]>>u[j]>>a[j];
	for(int k=1;k<=v;k++){
		cin>>v1[k];
	
	}
	}
}
	for(int i=1;i<=t;i++){
	for(int j=1;j<=n;j++){
	for(int k=1;k<=v;k++){
	if(v<u[j]){
		cnt++;
	for(int f=d[j];f<=v1[v];f++){
	flag[i][k]=1;
	}
	}else if((d[j]-l)*a[j]+u[j]>v){
		cnt++;
	for(int f=d[j];f<=v1[v];f++){
		if(f==v1[k]){
	flag[i][k]=1;
	}
	}
	}
	}
}
}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=v1[v];k++){
			if(flag[i][k]>=1){
				cnt1++;
				}
}
}
	for(int i=1;i<=n;i++){
		if(i!=1){
		cout<<endl<<cnt1<<" "<<cnt;
	}else{
		cout<<cnt1<<" "<<cnt;
	}
}
	return 0;
}

