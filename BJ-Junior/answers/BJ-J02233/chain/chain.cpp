#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,r,c,s[100020][200020],cnt,cnta,a[100002],p[100002],ans[100020],frt;
void tas(int t){
	if(t==0){
		if(a[cnt]%10==c) ans[cnta]=1;
		return;
	}
	for(int pi=1;pi<=n;pi++){
		if(pi==p[cnt]) continue;
		cnt++;
		p[cnt]=pi;
		for(int i=1;i<=s[pi][0]-2;i++){
			if(s[pi][i]!=frt) continue;
			for(int j=i+2;j<=s[pi][0];j++){
				if(j-i>k) continue;
				for(int d=i;d<=j;d++){
					a[cnt]=a[cnt]*10+s[pi][d];
				}
				tas(t-1);
				a[cnt]=0;
			}
		}
		p[cnt]=0;
		cnt--;
	}
	return;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int ta_sk=1;ta_sk<=T;ta_sk++){
		cin>>n>>k>>q;
		memset(s,0,sizeof(s));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++){
			cin>>s[i][0];
			for(int j=1;j<=s[i][0];j++) cin>>s[i][j];
		}
		for(int i=1;i<=q;i++){
			memset(p,0,sizeof(p));
			memset(a,0,sizeof(a));
			cnta=i;
			cin>>r>>c;
			frt=a[cnt]%10;
			if(i==1) frt=1;
			cnt=0;
			tas(r);
		}
		for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
	}
	return 0;
}