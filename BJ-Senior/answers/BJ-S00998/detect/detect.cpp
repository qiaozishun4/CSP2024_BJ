// #define debug
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+3 , L = 1e6+3 ;

struct edge{
	bool end;
	int plc1,plc2,plc;
	bool operator < (edge x){
		return plc==x.plc?x.end:plc<x.plc;
	}
}pt[N+N];

int t,n,m,e,v,p[N],prv[L],nxt[L],res1,res2,l[N],r[N];
vector<int> line;
set<int> dlt;

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		dlt.clear();
		line.clear();
		memset(prv,0,sizeof(prv));
		memset(nxt,0,sizeof(nxt));
		memset(p,0,sizeof(p));
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		memset(pt,0,sizeof(pt));
		cin>>n>>m>>e>>v;
		for(int i=1;i<=n;i++){
			int d,s,a;
			cin>>d>>s>>a;
			if(a>0){
				if(s>v){
					l[i]=d;
					r[i]=e;
				}else if(s==v){
					l[i]=r[i]=e+1;
				}else{
					if(ceil((v*v-s*s)/2.0/a)==(v*v-s*s)/2.0/a){
						l[i]=d+(v*v-s*s)/2.0/a+1;
					}else{
						l[i]=d+ceil((v*v-s*s)/2.0/a);
					}
					r[i]=e;
					if(l[i]>e){
						l[i]=r[i]=e+1;
					}
				}
			}else if(!a){
				if(s>v){
					l[i]=d;
					r[i]=e;
				}else{
					l[i]=r[i]=e+1;
				}
			}else{
				if(s>v){
					l[i]=d;
					if(floor((v*v-s*s)/2.0/a)==(v*v-s*s)/2.0/a){
						r[i]=d+(v*v-s*s)/2.0/a-1;
					}else{
						r[i]=d+floor((v*v-s*s)/2.0/a);
					}
					r[i]=min(r[i],e);
				}else{
					l[i]=r[i]=e+1;
				}
			}
			#ifdef debug
			cout<<l[i]<<" "<<r[i]<<endl;
			#endif
		}
		for(int j=1;j<=m;j++){
			cin>>p[j];
		}
		int pp=1;
		if(!p[1]){
			prv[0]=1;
			pp++;
		}
		for(int i=1;i<=e;i++){
			prv[i]=prv[i-1];
			if(i==p[pp]){
				pp++;
				prv[i]++;
			}
		}
		int np=m;
		for(int i=e;i>=0;i--){
			nxt[i]=nxt[i+1];
			if(i==p[np]){
				np--;
				nxt[i]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(nxt[l[i]]+prv[r[i]]>m){
				res1++;
			}
		}
		cout<<res1<<" ";
		#ifdef debug
		cout<<endl;
		#endif
		for(int i=1;i<=n;i++){
			pt[i].end=false;
			pt[i].plc1=l[i];
			pt[i].plc=l[i];
			pt[i].plc2=r[i];
			pt[n+i].end=true;
            pt[n+i].plc1=l[i];
			pt[n+i].plc2=r[i];
			pt[n+i].plc=r[i];
		}
		sort(pt+1,pt+n+n+1);
		#ifdef debug
		for(int i=1;i<=n+n;i++){
			cout<<"pt["<<i<<"]= "<<pt[i].end<<"+"<<pt[i].plc<<endl;
		}
		#endif
		int ptp=1;
		for(int i=1;i<=e;i++){
			if(i==pt[ptp].plc){
				while(pt[ptp+1].plc==i && !pt[ptp].end){
					line.push_back(ptp);
					ptp++;
				}
				if(pt[ptp].end){
					#ifdef debug
					cout<<i<<" end "<<ptp<<endl;
					#endif
					bool flag=dlt.find(pt[ptp].plc)==dlt.end();
					while(pt[ptp+1].plc==i){
						ptp++;
						flag=(flag || dlt.find(pt[ptp].plc1)==dlt.end());
						#ifdef debug
						cout<<(dlt.find(pt[ptp].plc1)==dlt.end()?"true":"false")<<" ";
						#endif
					}
					#ifdef debug
					cout<<endl;
					#endif
					if(flag){
						#ifdef debug
						cout<<"ok"<<endl;
						for(int j:dlt){
							cout<<j<<" ";
						}
						cout<<endl;
						#endif
						res2++;
						for(int j:line){
							dlt.insert(j);
						}
						line.clear();
					}
				}
				ptp++;
			}
		}
		cout<<m-res2<<endl;
	}
	return 0;
}
