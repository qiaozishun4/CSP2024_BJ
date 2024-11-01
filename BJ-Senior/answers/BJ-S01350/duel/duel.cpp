#include<bits/stdc++.h>
using namespace std;
int a[100010],sum[100010],num[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,id=1,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)sum[a[i]]++;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		num[id]=a[i];
		i+=sum[a[i]]-1;
		id++;
	}
	for(int i=1;i<=id-1;i++){
		int j=i+1;
		while(sum[num[i]]>0){
			sum[num[i]]-=sum[num[j]];
			if(sum[num[i]]<0)sum[num[i]]=0;
			j++;
			if(j>id-1)break;
		}	
		ans+=sum[num[i]];
	}
	cout<<ans;
	return 0;
}
