#include <bits/stdc++.h>
using namespace std;
int c[10] = {6,2,5,5,4,5,6,3,7,6};
struct node{
	short g[10005],size;
}f[100001];
node operator+(node a,int b){
	a.g[a.size] = b;
	a.size++;
	return a;
}
node compare(node a,node b){
	stable_sort(b.g,b.g+b.size);
	int i = 0;
	while(b.g[i] ==0 &&i<b.size)i++;
	swap(b.g[i],b.g[0]);
	if(a.size==0)return b;
	if(a.g[0] == 0)return b;
	if(b.g[0] == 0)return a;
	if(a.size<b.size)return a;
	if(a.size>b.size)return b;
	for(int i=0;i<a.size;i++){
		if(a.g[i]<b.g[i])return a;
		if(a.g[i]>b.g[i])return b;
	}
	return a;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	//cout<<1e5/7<<endl;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0;i<=n;i++)f[i].size=0;
		for(int i = 2;i<=n;i++){
			for(int j=0;j<10;j++){
				if(i>=c[j]&&(f[i-c[j]].g[0]>0 || i==c[j])){
//					cout<<"i is : "<<i<<"   j is : "<<j<<endl;
					f[i] = compare(f[i],f[i-c[j]]+j);
				}
			}
		}
		if(f[n].g[0] == 0)cout<<-1<<endl;
		else{
			for(int i=0;i<f[n].size;i++)cout<<f[n].g[i];
			cout<<endl;
		}
	}
	return 0;
}
