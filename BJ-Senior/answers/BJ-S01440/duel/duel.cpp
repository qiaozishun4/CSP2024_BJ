#include<bits/stdc++.h>
using namespace std;
long long n,a[100001]={},num=0,g=0;
int main(){
	cin>>n;
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		if(a[i]<=a[i-1]&&a[i-1]!=0){
			num+=0;
			g++;
		}else{
			num++;
			a[i-1]=0;
			g++;
		}
	}
	if(num==0&&g==n){
		cout<<0;
	}else if(g>=n-num){
		cout<<n-num;
	}
	return 0;
}
