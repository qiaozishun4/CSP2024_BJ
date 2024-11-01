#include<bits/stdc++.h>
using namespace std;
long long n , a[100005] ,maxx = -9999999, f[100005] , sum[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		sum[a[i]]++;
		maxx = max(a[i],maxx);
	}
	memset(f,0,sizeof(f));	
	for(int i = 1;i<=maxx;i++){
		if(f[i - 1] -sum[i]>=0)
		  f[i] = sum[i] + (f[i - 1] -sum[i]);
		else{
			f[i] = sum[i] ;
	}  }		
	cout<<f[maxx]<<endl;

	return 0;
}
/*
10
136 136 136 2417 136 136 2417 136 136 136
*/
