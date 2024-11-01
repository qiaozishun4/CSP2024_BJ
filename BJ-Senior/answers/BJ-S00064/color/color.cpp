#include<bits/stdc++.h>
using namespace std;
int a[100001];
int tong[1000001];
int zj[100001];
int rs[100001];
int n,t;
int sum=0;
void dfs(int step,int ans){
	if(step==n){
		 sum=max(sum,ans);
		 return ;
	}
	rs[step+1]=1;
	if(zj[step+1]!=0){
		 if(rs[step+1]==rs[zj[step+1]]) {
			 int flag=0;
			 for(int i=zj[step+1]+1;i<step+1;i++){
					if(rs[step+1]==rs[i]){
						flag=1;
						break;
					}
			}
			 if(flag==0) ans+=a[step+1];
		}
	}
	dfs(step+1,ans);
	rs[step+1]=2;
	if(zj[step+1]!=0){
		 if(rs[step+1]==rs[zj[step+1]]){
			 int flag=0;
			 for(int i=zj[step+1]+1;i<step+1;i++){
					if(rs[step+1]==rs[i]){
						flag=1;
						break;
					}
			}
			if(flag==0) ans+=a[step+1];
		}
	}
	dfs(step+1,ans);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		sum=0;
		memset(rs,0,sizeof(rs));
		memset(tong,0,sizeof(tong));
		memset(zj,0,sizeof(zj));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
				scanf("%d",&a[i]);
				if(tong[a[i]]!=0){	
					 zj[i]=tong[a[i]];
				}
				tong[a[i]]=i;
	}
//		dp1[1]=0,dp2[1]=0;
//		for(int i=2;i<=n;i++){
	//		if(zj[i]!=0){
//				for(int j=i;j>=zj[i];j--){
	//				if(at[j]==1) {
	//						
	//				}
	//		}
	
		
		dfs(0,0);
		printf("%d\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
}
