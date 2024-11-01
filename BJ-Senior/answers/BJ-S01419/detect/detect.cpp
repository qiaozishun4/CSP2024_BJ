#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
#define int double
const signed N=1e5+5;
bool specialA=1;
bool specialB=1;
bool specialC=1;
struct Car {
    int d,v,a;
} c[N];
int getSpeed(Car car,int time) {
	return car.v+car.a*time;
}
int getMile(Car car,int time) {
	return car.v*time+car.a*time*time;
}
int getDetectedMile(Car C,int V) {
	return (V*V-C.v*C.v)/2/C.a;
}
int detector[N];
struct Segment {
	int l,r;
} seg[N];
bool cmp(Segment a,Segment b) {
	if(a.l!=b.l) return a.l<b.l;
	return a.r>b.r;
}
bool visited[N];
bool visited2[N];
vector<int> vec[N];
set<int> st;
void Solve() {
    signed n,m;
    int L,V;
    scanf("%d%d%lf%lf",&n,&m,&L,&V);
    for(signed i=1;i<=n;i++) vec[i].clear();
    st.clear();
    memset(visited,0,sizeof(visited));
    memset(visited2,0,sizeof(visited2));
    for(signed i=1;i<=n;i++) {
        int d_,v_,a_;
        scanf("%lf%lf%lf",&d_,&v_,&a_);
        if(a_!=0) specialA=0;
        c[i]=Car{d_,v_,a_};
    }
    for(signed i=1;i<=m;i++) {
        scanf("%lf",&detector[i]);
    }
    if(specialA) {
        int maxDe=-1e9;
        for(signed i=1;i<=m;i++) {
            maxDe=max(maxDe,detector[i]);
        }
        int ans=0;
        for(signed i=1;i<=n;i++) {
            if(c[i].d<=maxDe&&c[i].v>V) ans++;
        }
        if(ans==0) printf("%.0lf %d\n",ans,m);
        else printf("%.0lf %d\n",ans,m-1);
        return ;
    }
	for(signed i=1;i<=n;i++) {
		if(c[i].a==0) {
			if(c[i].v>V) seg[i]=Segment{c[i].d,L};
			else seg[i]={-114514,-1919810};
			continue;
		}
		if(c[i].v>V) seg[i]=Segment{c[i].d,getDetectedMile(c[i],V)+c[i].d-0.001};
		else seg[i]=Segment{getDetectedMile(c[i],V)+c[i].d,L};
		//printf("Segment[%d]={%.3lf, %.3lf}\n",i,seg[i].l,seg[i].r);
	}
	sort(seg+1,seg+n+1,cmp);
	sort(detector+1,detector+n+1);
	signed cur=1,ans=0;
	for(signed j=1;j<=n;j++) {
        bool flag=0;
		for(signed i=1;i<=m;i++) {
			if(seg[j].l<=detector[i]&&seg[j].r>=detector[i]) {
                visited2[j]=1;
                st.insert(i);
				if(!flag) ans++;
                flag=1;
			}
		}
	}
	signed ans2=0;
	for(signed i=1;i<=n;i++) {
		if(seg[i].l==-114514&&seg[i].r==-1919810) continue;
		if(visited[i]) continue;
		if(!visited2[i]) continue;
		cur=1;
		while(cur<=n&&detector[cur]<seg[i].l) cur++;
		while(cur<=n&&detector[cur]<=seg[i].r) cur++;
		cur--;
		for(signed j=1;j<=n;j++) {
			if(seg[j].l<=detector[cur]&&seg[j].r>=detector[cur]) visited[j]=1;
		}
		ans2++;
		//printf("%d %d\n",i,cur);
		//printf("Segment[%d]={%.3lf, %.3lf}\n",i,seg[i].l,seg[i].r);
	}
	printf("%d %d\n",ans,m-ans2);
}
signed main() {
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    signed T;
    scanf("%d",&T);
    while(T--) {
        Solve();
    }
    return 0;
}
