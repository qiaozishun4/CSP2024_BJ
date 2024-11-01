#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100005],book[100005],ans,maxn=-1e9;
ll sum[100005],last;

int main(){	
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin>>n;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
	}
	
	if(maxn<=2){				//5~10
		ll sum1=0,sum2=0;
		for(ll i=1;i<=n;i++){
			if(a[i]==1){
				sum1++;
			}else{
				sum2++;
			}
		}
		if(sum1<=sum2){
			ans=sum2;
		}else{
			ans=sum1;
		}
		cout<<ans;
		return 0;
	}
	
	sort(a+1,a+n+1);	
	for(ll i=1;i<=n;i++){
		if(a[i]!=last){
			sum[a[i]]=i;
			last=a[i];
		}
	}
	
	for(ll i=1;i<=n;i++){
		ll num=sum[a[i]]-1;//找到最后一个比a[i]小的位置
		
		if(num>=1){
			if(book[num]!=-1){
				book[num]=-1;
				ans++;
			}else{
				while(book[num]==-1){
					num--;
					if(num<1) break;
				}
				if(num>=1&&book[num]!=-1){
					book[num]=-1;
					ans++;
				}
			}							
		}
	}		
	cout<<n-ans;	
	return 0;
}
