#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],r[100005],maxn=-1,sum;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		r[a[i]]++;
	}
	int flg=0;
	for(int i=1;i<=maxn;i++){
		if(r[i]){
			if(flg){
				if(sum>r[i])sum-=r[i];
				else sum=0;
			}
			sum+=r[i];
			flg=1;
		}
	}
	cout<<sum;
}
