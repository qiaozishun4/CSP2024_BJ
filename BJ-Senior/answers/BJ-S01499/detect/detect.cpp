#include<bits/stdc++.h>
using namespace std;
struct car{
	int d,v,a;
};
car l[10005];
int c[10005];
int ans1=0,ans2=3;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	for(int ti=0;ti<T;ti++){
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++){
			cin>>l[i].d>>l[i].v>>l[i].a;
		}
		for(int i=0;i<m;i++){
			cin>>c[i];
		}
		for(int i=0;i<n;i++){
			int d=l[i].d,v=l[i].v,a=l[i].a;
			if(a==0){
				if(v>V)ans1++;
			}else{
				int b=(V*V-v*v)/(2*a);
				if(b>0){
					b+=d;
					if(b>L)continue;
					ans1++;
					
				}
			}
		}
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
