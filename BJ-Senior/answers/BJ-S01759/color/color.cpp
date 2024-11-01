//code by:757326
//time 17:29
#include<bits/stdc++.h>
using namespace std;
long long t,n,a[1000005],tt[1000005];
long long ans;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			tt[a[i]]++;
		}
		
		for(int i=1;i<=n;i++){
			if(tt[i])ans+=(tt[i]-1)*i;
		}
		cout<<ans<<endl;
		ans=0;
		for(int i=1;i<=n;i++){
			tt[i]=0;
		}
	}
	
	return 0;
}
/*
3

3

1 2 1

4

1 2 3 4

8

3 5 2 5 1 2 1 4
 * 
 * 
 * 
 * 
 * */
