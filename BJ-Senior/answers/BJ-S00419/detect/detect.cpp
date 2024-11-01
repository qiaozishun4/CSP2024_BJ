#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5,M=1e6+5;
int n,m,L,V,d[N],v[N],a[N],p[N],x[N][N],h[M],h2[M],cnt,ans;
int T;
bool s[N],vt[N];
void dg(int nw){
	if(nw>m){
		int sf=1;
		for(int i=1;i<=n;i++){
			if(s[i]){
				bool f=0;
				for(int j=1;j<=m;j++){
					if(vt[j]){
						for(int k=1;k<=x[j][0];k++){
							if(i==x[j][k]){
								f=1;
							}
						}
					}
				}
				if(!f){
					sf=0;
				}
			}
		}
		if(sf){
			sf=0;
			for(int i=1;i<=m;i++){
				if(!vt[i]){
					sf++;
				}
			}
			ans=max(ans,sf);
		}
		return;
	}
	vt[nw]=0;
	dg(nw+1);
	vt[nw]=1;
	dg(nw+1);
}
int main(){
	freopen("detect1.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cnt=0;
		ans=0;
		for(int i=0;i<N;i++){
			d[i]=0;
			v[i]=0;
			a[i]=0;
			p[i]=0;
			s[i]=0;
		}
		for(int i=0;i<M;i++){
			h[i]=100000000;
			h2[i]=0;
		}
		cin>>n>>m>>L>>V;
		L++;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			d[i]++;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
			p[i]++;
		}
		sort(p+1,p+m+1);
		for(int i=1;i<=m;i++){
			h[p[i]]=i;
			h2[p[i]]=i;
		}
		
		for(int i=L;i>=1;i--){
			h[i]=min(h[i+1],h[i]);
		}
		for(int i=1;i<=L;i++){
			h2[i]=max(h2[i-1],h2[i]);
		}
		//for(int i=1;i<=L;i++){
		//	cout<<h[i]<<" "<<h2[i]<<endl;
		//}
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>V){
					for(int j=h[d[i]];j<=m;j++){
						x[j][++x[j][0]]=i;
						s[i]=1;
					}
				}
			}else{
				if(a[i]>0){
					for(int j=h[d[i]+min(L+1,(V*V-v[i]*v[i])/(a[i]*2)+1)];j<=m;j++){
						x[j][++x[j][0]]=i;
						s[i]=1;
					}
				}else{
					if((V*V-v[i]*v[i]-1)/(a[i]*2)>=0){
						for(int j=h[d[i]];j<=h2[d[i]+min(L+1,(V*V-v[i]*v[i]-1)/(a[i]*2))];j++){
							x[j][++x[j][0]]=i;
						s[i]=1;
						}
					}
				}
			}
		}
		//for(int i=1;i<=m;i++){
		//	cout<<x[i][0]<<" ";
		//	for(int j=1;j<=x[i][0];j++){
		//		cout<<x[i][j]<<" ";
		//	}
		//	cout<<endl;
		//}
		for(int i=1;i<=n;i++){
			if(s[i]){
				cnt++;
			}
		}
		dg(1);
		cout<<cnt<<" "<<ans<<endl;
	}
	return 0;
}
/*
20
10 10 150307 247
62978 968 -5
51700 883 -3
40408 564 -1
60366 870 -41
35943 797 -7
47476 595 -11
59020 672 -10
81024 964 -11
80637 695 -5
66114 874 -1
46720 48066 57373 60882 68842 72773 82820 116695 122159 150307
10 7
*/
