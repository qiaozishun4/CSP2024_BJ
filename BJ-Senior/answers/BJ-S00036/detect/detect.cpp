#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int tt,n,m,l,v,p[N],t[N*10],ans,maxx,ss,ans2;
bool b[N];
struct edge{
	int d=0,ve=0,a=0,xx=0;
}e[N],er[N];
int gett(int x){
	if(x<p[1]) return 0;
	if(x>p[m]) return m;
	int L=1,R=m;
	while(L<=R){
		int mid=(L+R)>>1;
		if(p[mid]==x) return mid;
		if(p[mid]<x&&p[mid+1]>x) return mid;
		if(p[mid]>x) R=mid;
		else if(p[mid]<x) L=mid+1;
	}
}
bool cmp(edge e1,edge e2){
	if(e1.d==e2.d) return e1.xx<e2.xx;
	return e1.d<e2.d;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>tt;
	while(tt--){
		memset(b,false,sizeof(b));
		memset(t,0,sizeof(t));
		maxx=0;
		ans=0;
		ss=0;
		ans2=0;
		scanf("%d%d%d%d",&n,&m,&l,&v);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&e[i].d,&e[i].ve,&e[i].a);
		for(int i=1;i<=m;i++) scanf("%d",&p[i]),maxx=max(maxx,p[i]);
		for(int i=1;i<=m;i++) t[p[i]]++;
		int s=0;
		for(int i=0;i<=maxx;i++)
			for(int j=1;j<=t[i];j++) p[++s]=i;
		for(int i=1;i<=n;i++){
			if(e[i].a==0){
				if(e[i].ve<=v) continue;
				if(e[i].d<=p[m]){
					b[i]=true;
					ans++;
				}
			}
			if(e[i].a<0){
				if(e[i].ve<=v) continue;
				float x=-(float(e[i].ve*e[i].ve)-float(v*v))/float(2*e[i].a);
				int y=min(l,int(x)+e[i].d);
				//cout<<y<<" ";
				//cout<<gett(e[i].d)<<" "<<gett(y);
				int ge=gett(e[i].d),gy=gett(y);
				if(ge!=gy||y==p[gy]||e[i].d==p[ge]){
					b[i]=true;
					ans++;
				}
			}
			if(e[i].a>0){
				if(e[i].ve>=v){
					if(e[i].ve==v&&p[m]==e[i].d) continue;
					if(p[m]>=e[i].d){
						b[i]=true;
						ans++;
					}
					continue;
				}
				float x=(float(v*v)-float(e[i].ve*e[i].ve))/float(2*e[i].a);
				int y=e[i].d+int(x)+1;
				if(y>l) continue;
				if(p[m]>=y){
					b[i]=true;
					ans++;
				}
			}
		}
		printf("%d ",ans);
		if(ans==0){
			printf("%d\n",m);
			continue;
		}
		for(int i=1;i<=n;i++){
			if(b[i]==false) continue;
			ss++;
			if(e[i].a<0){
				float x=-(float(e[i].ve*e[i].ve)-float(v*v))/float(2*e[i].a);
				int y=int(x)+e[i].d;
				if(int(x)==x) y--;
				er[ss].xx=min(l,y);
				er[ss].a=e[i].a;er[ss].ve=e[i].ve;er[ss].d=e[i].d;
			}
			if(e[i].a==0){
				er[ss].d=e[i].d;
				er[ss].a=e[i].a;
				er[ss].ve=e[i].ve;
				er[ss].xx=l;
			}
			if(e[i].a>0){
				float x=(double(v*v)-double(e[i].ve*e[i].ve))/double(2*e[i].a);
				int y=int(x)+e[i].d+1;
				er[ss].a=e[i].a;
				er[ss].xx=l;
				er[ss].ve=e[i].ve;
				er[ss].d=y;
			}
		}
		//cout<<ss<<" ";
		for(int i=1;i<=ss;i++){
			int oo=er[i].d;
			//cout<<er[i].d<<" "<<er[i].xx<<endl;
			er[i].d=gett(er[i].d);
			er[i].xx=gett(er[i].xx);
			if(p[er[i].d]!=oo) er[i].d++;
			//cout<<i<<" ";
		}
		sort(er+1,er+ss+1,cmp);
		//cout<<endl;
		//for(int i=1;i<=ss;i++) cout<<er[i].d<<" "<<er[i].xx<<endl;
		int L=er[1].d,R=er[1].xx;
		for(int i=2;i<=ss;i++){
			if(er[i].d>R){
				ans2++;
				L=er[i].d;
				R=er[i].xx;
				continue;
			}
			L=max(L,er[i].d);
			R=min(R,er[i].xx);
		}
		ans2++;
		//for(int i=1;i<=m;i++) cout<<p[i]<<" ";
		printf("%d\n",m-ans2);
	}
	return 0;
}
