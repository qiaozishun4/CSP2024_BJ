#include<bits/stdc++.h>
using namespace std;
int a[100001]={};
int b[100001]={};
bool vis[100001]={};
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,la=0;
	int m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		m=max(a[i],m);
	}
	for(int i=1;i<=m;i++){
		if(b[i]!=0){
			la-=min(b[i],la);
			la+=b[i];
		}
	}
	cout<<la;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
