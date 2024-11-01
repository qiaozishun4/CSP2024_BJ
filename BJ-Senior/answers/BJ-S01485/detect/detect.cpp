#include<bits/stdc++.h>
using namespace std;
struct a1{
	int d,v,a;
}a[1000000];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
int t,n,m,l,v;
cin>>t;
while(t--){
	cin>>n>>m>>l>>v;
	int p[1000000]={},m,s=0,s1=0;
	for(int i=0;i<n;i++){
		cin>>a[i].d>>a[i].v>>a[i].a;
	}
	for(int i=0;i<m;i++){
		cin>>m;
		p[m]=1;
	}
	for(int i=0;i<n;i++){
		double e=(v*v-a[i].v*a[i].v)/2.0/a[i].a;
		for(int i=a[i].d;i<e;i++){
			if(i>l)break;
			if(p[i]){
				p[i]++;
				s++;
				break;
			}
		}
	}
	for(int i=0;i<l;i++)if(p[i]==1)s1++;
	cout<<s<<' '<<s1<<endl;
}
return 0;
}