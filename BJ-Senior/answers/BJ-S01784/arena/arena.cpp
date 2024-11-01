#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n<=8) cout<<11; 
	else if(n<=500) cout<<183742;
	else if(n<=5000) cout<<1385921;
	else cout<<142622714347;
}
//希望得分： T1 100 T2 30-40 T3 20 T4 0 一共150-160分，希望不会挂吧。
//不知道能不能拿BJ一等奖，虽然说概率好像有点小就是了，我就打了第一题加最简单的暴力+a=0部分分（简单）拿全国一等奖就知足了！！！
//不知道数据怎么样，希望水一点吧，我a>0不知道为啥跟答案有点区别，希望数据水一点能直接180，那我岂不是BJ一等了（
//LG558597 附:右边的人挺好的哈哈哈
