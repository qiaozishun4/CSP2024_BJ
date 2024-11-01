#include<bits/stdc++.h>
using namespace std;
const int E = 1e6;
int d[E],v[E],a[E],p[E];
int main(){
	freopen("detect.in","r",stdin)
	freopen("detect.out","w",stdout)
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		for(int j=0;j<n;j++){
			cin>>d[j]>>v[j]>>a[j];
		}
		for(int j=0;j<m;j++){
			cin>>p[i];
		}
		for(int j=0;j<n;j++){
			int qj = d[j]+((2*a[j])/(9-v[j]));
			
		}
		cout<<qj<<" "<<qj;
	}
	fclose(stdin);
	fclose(stdout);
}
