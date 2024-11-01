#include<bits/stdc++.h>
using namespace std;
int n,m;
#define ls p<<1
#define rs p<<1|1
#define mid (l+r>>1)
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
int main(){
	fre("arena");
	cin>>n>>m;
	cout<<"Hello world!"<<endl;
	return 0;
}
/*
$2^k$ 选手，$k$ 轮，每轮只保留上一轮胜者，相邻两位决斗。
每位选手有能力值 $a_i$。
每轮大概是编号从小到大进行决斗。
第 $R$ 轮，第 $G$ 场，抽签得到 $d_{R,G}=0/1$，$0$ 表示编号小的当擂主，$1$ 表示编号大的当擂主。
擂主获胜当且仅当他的能力值 $a\geq R$。
我们把选手补充到最近的 $2^k$ 次幂，补充选手能力值任选。
求可能是总冠军的所有人的编号和（包括补充选手）。
*/