#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],zq,id,zg[100005],d,qz[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		if(zq!=a[i]){
			zq=a[i];
			zg[++id]++;
		}else{
			zg[id]++;
		}
	}
	qz[1]=zg[1];
	for(long long i=2;i<=id;i++){
		if(qz[i-1]>=zg[i]){
			qz[i-1]-=zg[i];
		}else{
			qz[i-1]=0;
		}
		qz[i]=qz[i-1]+zg[i];
	}
	cout << qz[id];
	return 0;
}
