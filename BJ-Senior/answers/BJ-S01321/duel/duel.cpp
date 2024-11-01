#include<bits/stdc++.h>
using namespace std;
map<int,map<int,int> > f;
int r[100001];
int cnt1,cnt2;
int n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	memset(nxt1,0x7f,sizeof nxt1);
	memset(pre1,0x7f,sizeof pre1);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>r[i];
		if(r[i]==0)cnt1++;
		if(r[i]==1)cnt2++;
	}
    if(r[n]==1)cout<<n;
    else cout<<n-min(cnt1,cnt2);
    return 0;
}
