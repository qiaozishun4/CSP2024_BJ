#include<bits/stdc++.h>
using namespace std;
int cost[10]={6,2,5,5,4,5,6,3,7,6};
int dfs(int ans,int num,int a){
	if(num==1||num<0) return 2147483647;
	if(num==0){
		ans=min(ans,a);
		return ans;
	}
	else{
		for(int i=0;i<=9;i++){
			if(a==0&&i==0) continue;
			int temp=a,temp1=num;
			num-=cost[i];
			a=a*10+i;
			int nans=dfs(ans,num,a);
			num=temp1,a=temp,ans=nans;
		}
	}
	return ans;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int n;
		scanf("%d",&n);
		if(n<2){printf("%d\n",-1);continue;}
		if(n==2){printf("%d\n",1);continue;}
		if(n==3){printf("%d\n",7);continue;}
		if(n==4){printf("%d\n",4);continue;}
		if(n==5){printf("%d\n",2);continue;}
		if(n==6){printf("%d\n",6);continue;}
		if(n==7){printf("%d\n",8);continue;}
		else{
			int ans=dfs(2147483647,n,0);
			if(ans==2147483647) printf("%d\n",-1);
			else printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
