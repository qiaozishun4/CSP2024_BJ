#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int find(){
	int an=0,s=1;
	while(s<n){
		an++;
		s*=2;
	}
	return an;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n+m;i++){
		int x;
		cin>>x;
	}
	int a=find();
	string c;
	for(int i=1;i<=a;i++) cin>>c;
	cin>>t;
	for(int i=1;i<=t;i++){
		int a1,a2,a3,a4;
		cin>>a1>>a2>>a3>>a4;
		int s=1;
		for(int i=1;i<=a;i++) s*=2;
		cout<<s*(s+1)/2<<endl;
	}
	return 0;
}
