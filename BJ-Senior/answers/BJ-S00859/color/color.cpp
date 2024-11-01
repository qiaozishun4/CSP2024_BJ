#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,n,a[N],cnt[N],blue[N],red[N],bcnt,rcnt;

long long dfs(int a[],int op,int bcnt,int rcnt,int x){
	long long summ=0;
	if (op==0)
	{
		//cout<<0<<"   ";
		blue[bcnt]=a[x];
		//cout<<blue[bcnt]<<"\n";
		if (bcnt>0){
			if (blue[bcnt]==blue[bcnt-1]){
				summ+=blue[bcnt];
				//cout<<summ<<" ";
			}
		}
		return summ+max(dfs(a,0,bcnt+1,rcnt,x+1),dfs(a,1,bcnt+1,rcnt,x+1));
	}
	else
	{
		//cout<<1<<"   ";
		red[rcnt++]=a[x];
		//cout<<red[rcnt]<<"\n";
		if (rcnt>0){
			if (red[rcnt]==red[rcnt-1]){
				summ+=blue[bcnt];
				//cout<<summ<<" ";
			}
		}
		return summ+max(dfs(a,0,bcnt,rcnt+1,x+1),dfs(a,1,bcnt,rcnt+1,x+1));
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for (int o=0;o<t;o++){
		cin>>n;
		bool flag=false;
		memset(cnt,0,sizeof(cnt));
		for (int i=0;i<n;i++){
			cin>>a[i];
			cnt[a[i]]++;
			if (cnt[a[i]]>1)
				flag=true;
		}
		if (flag==false){
			cout<<0<<"\n";
			continue;
		}
		memset(blue,0,sizeof(blue));
		memset(red,0,sizeof(red));
		int max1=dfs(a,0,0,0,0),max2=dfs(a,1,0,0,0);
		cout<<max(max1,max2)<<"\n";
		
	}
	return 0;	
}
