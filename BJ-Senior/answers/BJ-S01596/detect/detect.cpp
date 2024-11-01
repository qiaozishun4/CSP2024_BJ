#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
struct c{
	int d,v,a;
	}r[N];
int bg[N],ed[N],ok[N]={0};
int jg[N]={0};
int p[N];
int check(c x,int s,int m){
	if(m*m>=(s-x.d)*x.a*2+x.v*x.v)
	{
		return 1;
		}
	return 0;
	}
int main(){
freopen("detect.in","r",stdin);
freopen("detect.out","w",stdout);
int t;
cin>>t;
while(t--){
	int n,m,l,v;
	int ans=0;
	cin>>n>>m>>l>>v;
	for(int i=0;i<n;i++){
		cin>>r[i].d>>r[i].v>>r[i].a;
		}
	for(int i=0;i<m;i++){
		cin>>p[i];
	}
	int cnt1=0,cnt2=0;
	int mmm=0;
	for(int i=0;i<n;i++){
		if(r[i].a>=0){
			if(!check(r[i],p[m-1],v)){
				if(r[i].a!=0){
					cnt1++;
					double sll=(v*v-r[i].v*r[i].v)/r[i].a;
					sll*=0.5;
					sll+=r[i].d;
					int ljj=lower_bound(p,p+m,sll)-p;
					mmm=max(ljj,mmm);
				}
				ans++;
			}
		}
		else{
			int sy=lower_bound(p,p+m,r[i].d)-p;
			if(!check(r[i],p[sy],v)){
				double sl=(v*v-r[i].v*r[i].v)/r[i].a;
				sl*=0.5;
				sl+=r[i].d;
				int lj=upper_bound(p,p+m,sl)-p-1;
				bg[cnt2]=sy;
				ed[cnt2]=lj;
				cnt2++;
				ans++;
			}
		}
	}
	for(int i=0;i<cnt2;i++){
		ok[i]=0;
		}
	if(cnt2==0){
		if(cnt1==0) cout<<ans<<' '<<m<<"\n";
		else cout<<ans<<' '<<m-1<<"\n";
	}
	else{
		int nnn=0,mx=0;
		while(1){
		int del=0,mm=0;
		for(int i=0;i<m;i++){
			jg[i]=0;
			for(int j=0;j<cnt2;j++){
				if(bg[j]<=i&&ed[j]>=i&&!ok[j]){
					jg[i]++;
				}
			}
			if(jg[i]>mm){
				mm=jg[i];
				del=i;
				mx=max(del,mx);
			}
		}
		if(mm<=1){
			for(int i=0;i<cnt2;i++){
				if(ok[i]==0){
					nnn++;
					mx=max(ed[i],mx);
				}
			}
			if(cnt1>0&&mx<mmm){
				cout<<ans<<' '<<m-nnn-1<<"\n";
			}
			else{
			cout<<ans<<' '<<m-nnn<<"\n";}
			break;
		}
		else{
			for(int j=0;j<cnt2;j++){
				if(bg[j]<=del&&ed[j]>=del&&!ok[j]){
					ok[j]=1;
				}
			}
			nnn++;
		}
		}
	}
}

fclose(stdin);
fclose(stdout);
return 0;
}
