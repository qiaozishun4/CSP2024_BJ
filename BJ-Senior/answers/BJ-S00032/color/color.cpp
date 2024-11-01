#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e5+5;
int n;
int buc[1000005];
int a[N];
int premax[N],f[N];
int lst[N];
int S[N];
int Qsame(int l,int r){
	if(r-1<=l+1) return 0;
    return S[r-1]-S[l+1];
}
void init(){
	for(int i=0;i<=n;i++) a[i]=premax[i]=f[i]=lst[i]=S[i]=0;
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int T; cin>>T;
    for(int z=1;z<=T;z++){
        cin>>n;
		init();
        for(int i=1;i<=n;i++){
            cin>>a[i]; lst[i]=buc[a[i]]; buc[a[i]]=i;
            if(a[i]==a[i-1]) S[i]=S[i-1]+a[i];
            else S[i]=S[i-1];
		}
		for(int i=1;i<=n;i++){
			if(lst[i]!=0) f[i]=max(premax[lst[i]+1],premax[lst[i]])+a[i]+Qsame(lst[i],i);
			premax[i]=max(premax[i-1],f[i]);
		}
		cout<<premax[n]<<'\n';
        for(int i=1;i<=n;i++) buc[a[i]]=0;
    }
}