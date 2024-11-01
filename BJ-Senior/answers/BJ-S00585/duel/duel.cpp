#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,a[N],b[N],v[N],e[N];
long long ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.ans","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int cnt=unique(b+1,b+n+1)-b-1;
	for (int i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+cnt+1,a[i])-b;
	//for (int i=1;i<=n;i++)
		//cout<<a[i]<<" ";
	//cout<<'\n';
	for (int i=1;i<=n;i++)
		v[a[i]]++,e[a[i]]=v[a[i]];
	//cout<<"----------------";
	//for (int i=n-1;i>=1;i--)
		//v[i]=v[i]+v[i+1];
	for (int i=1;i<=n;i++){
		int k=min(v[i+1],v[i]);
		v[i]-=k;
		v[i+1]+=v[i];
	}
	for (int i=1;i<=n;i++)
		ans+=v[i];
	cout<<v[cnt];
	return 0;
}
