#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,V=1e6+5;
ll n,a[N],dp[N];
ll pre[V];
struct Line{
	ll l,r,v;
}p[N];ll cnt=0;
struct K_1{
	ll tmp[2];
	bool check(){return n<=15;}
	void work(){ll genshin=0;
		for(ll st=0;st<(1ll<<n);st++){
			tmp[1]=tmp[0]=0;
			ll sum=0;bool flag=1;
			for(int i=1;i<=n;i++){
				if((st>>i-1)&1){
					if(a[tmp[1]]==a[i])sum+=a[i];
					tmp[1]=i;
				}else{
					if(a[tmp[0]]==a[i])sum+=a[i];
					tmp[0]=i;
				}
			}genshin=max(genshin,sum);
		}
		cout<<genshin<<endl;
	}
}T_1;
struct K_2{
	ll dp[2005][2005];//最近的蓝色和红色
	inline bool check(){return n<=2000;}
	inline void work(){
		for(int i=0;i<=n;i++){
			for(int j=0;j<i;j++){
				dp[i][j]=0;
			}
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<i;j++){//j+1~i之间都是i的颜色
				if(a[i+1]==a[i]){
					dp[i+1][j]=max(dp[i+1][j],dp[i][j]+a[i]);
				}
				else{
					dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
				}
				if(a[i+1]==a[j]){
					dp[i+1][i]=max(dp[i+1][i],dp[i][j]+a[j]);
				}
				else{
					dp[i+1][i]=max(dp[i+1][i],dp[i][j]);
				}
			}
		}
		ll genshin=0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<i;j++){
				genshin=max(genshin,dp[i][j]);
			}
		}cout<<genshin<<endl;
	}
}T_2;
struct K_3{
	ll tmp[N];
	bool check(){return cnt<=20;}
	void work(){ll genshin=0;
		for(ll st=0;st<(1ll<<cnt);st++){
			for(int i=1;i<=n;i++)tmp[i]=0;
			ll sum=0;bool flag=1;
			for(int i=1;i<=cnt;i++){
				if((st>>i-1)&1){sum+=p[i].v;
					for(int k=p[i].l;k<=p[i].r;k++){
						if((++tmp[k])>2){flag=0;break;}
					}
				}
			}if(flag)genshin=max(genshin,sum);
		}
		cout<<genshin<<endl;
	}
}T_3;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;cin>>T;while(T--){
		cin>>n;
		for(int i=0;i<V;i++)pre[i]=0;cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(pre[a[i]]){p[++cnt]=(Line){pre[a[i]],i-1,a[i]};}
			pre[a[i]]=i;
		}
		if(T_1.check()){T_1.work();continue;}
		if(T_2.check()){T_2.work();continue;}
		if(T_3.check()){T_3.work();continue;}
		//如果只有一个数轴，那么我们直接考虑sort右端点，
		
		//是不是返回贪心
		
		//解决这个简化版问题
		//if(T_1.check()){T_1.work();continue;}
		
	}
	return 0;
}
/*
1
8
3 5 2 5 1 2 1 4

算了，来分析性质。
容易发现是一个数字往左最近的那个。
所以第一点转移发生在相同数字之间，中间没有蓝色
红蓝可以颠倒
用vector搞出来，转移的时候希望内部米有其他颜色
返回贪心？no
应该就是dp
哦对了，只用一维，转移的时候保证只有i和上一个与i同数值的是红色，不对
我们一个一个证明
这东西主要就看能不能找出足够多的性质。
贡献的只有可能是相邻且同色的？
假设不是，例如i,j,k
i<j<k，a[i]=a[j]=a[k]，但是i和k颜色与j不同
很明显如果只贡献一次比两次差只能说明如果中间的颜色会影响另一对，比如说p,t
如果p,t不一样颜色那么没必要，所以同色。
如果红色那么i,k也贡献不了，所以蓝色，但此时j又不影响。
所以贡献的只有可能是相邻且同色的

woc
线段覆盖！！！！！！！！！！！！！！！！！！！！！！
*/
//题目直接转化为，有若干的线段，有权，问覆盖于两个数轴且不重复最大值。顶点可交
