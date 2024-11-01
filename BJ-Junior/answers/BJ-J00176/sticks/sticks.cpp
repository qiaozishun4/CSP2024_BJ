#include<bits/stdc++.h>
using namespace std;
int a[11]={6,2,5,5,4,5,6,3,7,6},z;
int b[30009];
int f,ans;
void dfs(int c,int d){
	if(d==0&&c==0){
		c=1;
		f=1;
		return;
	}
	if(f==1) return;
	if(d==0) return;
	for(int i=0;i<=9;i++){
		if(f==1) return;
		if(z==d&&i==0) continue;
		if(f==1) return;
		if(c-a[i]>(d-1)*7||c-a[i]<0) continue;
		b[ans++]=i;
		dfs(c-a[i],d-1);
		if(f==1) return;
		ans--;
		if(f==1) return;
	}
	return;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(b,0,sizeof(b));
		int x;
		cin>>x;
		if(x==1){
			cout<<-1<<endl;
			continue;
		}
		int y=x-1;
		z=y/7+1;
		ans=1;
		f=0;
		dfs(x,z);
		for(int i=1;i<=z;i++) cout<<b[i];
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
