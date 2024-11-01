#include<bits/stdc++.h>
using namespace std;
long long h[]={6,2,5,5,4,5,6,3,7,6};
long long f(long long x){
	long long res=0;
	while(x){
		res+=h[x%10];
		x/=10;
	}
	return res;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	long long t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		if(n==1){
			cout<<-1;
			continue;
		}
		long long cnt=1e9;
		for(long long i=0;i<=1e5;i++){
			if(f(i)==n){
				cnt=min(cnt,i);
			}
		}
		if(cnt!=1e9)cout<<cnt<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
