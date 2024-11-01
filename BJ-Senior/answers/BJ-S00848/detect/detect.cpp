#include<bits/stdc++.h>
#define ll long long 
#define Leth 1000010
using namespace std;
ll lt,n,m,Le,Vc;
ll cd,cv,ca;
struct Aclt{
	ll bg;
	ll end;
	bool wd=0;
	bool OTspd=1;
};
Aclt acc[Leth];
ll spdT[Leth];
bool bdt[Leth];

ll sbg=1000005,send=1000005;
int main(){
	freopen("detect2.in","r",stdin);
	freopen("detect2.out","w",stdout);
	scanf("%lld",&lt);
	for(ll rnd=1;rnd<=lt;rnd++)
	{
		for(ll i=1;i<=m;i++) bdt[i]=0;
		ll ccnt=0,tcnt=0;
		scanf("%lld%lld%lld%lld",&n,&m,&Le,&Vc);
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&cd,&cv,&ca);
			if(cv>=Vc){
				if(ca>=0){
					acc[i].bg=cd;
					acc[i].end=Le;
				}
				else{
					ll tmp=(Vc*Vc-cv*cv)/(2*ca);
					acc[i].bg=cd;
					acc[i].end=cd+tmp-1;
				}
			}
			else{
				if(ca>0){
					ll tmp=(Vc*Vc-cv*cv)/(2*ca);
					acc[i].bg=cd+tmp;
					acc[i].bg=Le;
				}
				else acc[i].OTspd=0;
			}
		}
		for(ll i=1;i<=m;i++)
			scanf("%lld",&spdT[i]);
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				if(acc[i].OTspd){
					if(acc[i].bg<=spdT[j]&&acc[i].end>=spdT[j]){
						ccnt++;acc[i].wd=1;break;
					}
				}
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(acc[i].wd&&acc[j].wd){
					ll lt,rt;
					if(acc[i].bg>=acc[j].end||acc[j].bg>=acc[i].end) continue;
					lt=max(acc[i].bg,acc[j].bg);
					rt=min(acc[i].end,acc[j].end);
					for(ll k=1;k<=m;k++){
						if(bdt[k]) continue;
						if(lt<=spdT[k]&&rt>=spdT[k]) bdt[k]=1;
					}
				}
			}
		}
		for(ll i=1;i<=m;i++){
			if(bdt[i]) tcnt++;
		}
		printf("%lld %lld\n",ccnt,tcnt);
	}
	return 0;
}