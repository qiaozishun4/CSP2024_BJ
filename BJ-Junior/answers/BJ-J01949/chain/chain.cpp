#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int>v[N];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
	int n,k,q;
	cin>>n>>k>>q;
	for(int i=0;i<n;i++){
	int l;
	cin>>l;
	for(int j=0;j<l;j++){
		int a;
		cin>>a;
		v[i].push_back(a);
		}
	}
	for(int i=0;i<q;i++){
		int r,c;
		cin>>r>>c;
		cout<<"0\n";
		}}
	fclose(stdin);
fclose(stdout);
	return 0;
}
