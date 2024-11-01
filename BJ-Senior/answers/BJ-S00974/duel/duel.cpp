#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
long long pd[200005];
long long cnt,mx=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
		pd[a[i]]++;
	}
	cnt=1;
    for(int i = 0;i<=mx+5;i++){
        cnt=max(cnt,pd[i]);
    }
    cout<<cnt;
	return 0;
}
