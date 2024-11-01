#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int r[maxn];
int cnt[maxn],sum[maxn];
int n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		cnt[r[i]]++;
	}
	for(int i=1;i<=1e5;i++){
		sum[i]=sum[i-1]+cnt[i];
	}
	sort(r+1,r+n+1);
	int die=0;
	for(int i=2;i<=n;i++){
		if(sum[r[i]-1]-die){
		//	printf("id:%d,pow:%d,die:%d\n",i,r[i],die);
			die++;
		}
	}
//	cout<<die<<endl;
	cout<<(n-die)<<endl;
	return 0;
}
