#include<bits/stdc++.h>
using namespace std;
int n;
int a[100009];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int f[100009];
	for(int i=1;i<=100001;i++)f[i]=0;
	for(int i=1;i<=n;i++){
		f[a[i]]++;
	}
	int mx=0;
	for(int i=1;i<=100001;i++){
		if(f[i]>mx)mx=f[i];
	}
	cout<<mx;
	return 0;	
}