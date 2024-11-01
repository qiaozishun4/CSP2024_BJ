#include<bits/stdc++.h>
using namespace std;
int t,N,M,L,ans1,ans2;
double V,d[100100],v[100100],a[100100],imptime[100100],p[100100];
bool is_a=true,is_b=true;
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--) {
		ans1=0;
		ans2=0;
		cin>>N>>M>>L>>V;
		for(int i=1;i<=N;i++) {
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]!=0) {
				is_a=false;
			}
			if(a[i]<=0) {
				is_b=false;
			}
		}
		for(int i=1;i<=M;i++) {
			cin>>p[i];
		}
		if(is_a) {
			for(int i=1;i<=N;i++) {
				if(v[i]>V&&p[M]>=d[i]) {
					ans1++;
				}
			}
			if(ans1==0) {
				ans2=M;
			}
			else {
				ans2=M-1;
			}
			cout<<ans1<<" "<<ans2<<endl;
		}
		if(is_b) {
			for(int i=1;i<=N;i++) {
				double sx=double(double(double(double(V)*double(V))-double(double(v[i])*double(v[i])))*double(0.5)/double(a[i]));
				if(ceil(double(double(sx)+d[i]))<p[M]) {
					ans1++;
				}
			}
			ans2=M-1;
			cout<<ans1<<" "<<ans2<<endl;
		}
	}
	return 0;
}