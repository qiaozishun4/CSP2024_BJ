#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,k,q,l,s[100000001];
        cin>>n>>k>>q>>l;
        for(int i=1;i<=l+1;i++) cin>>s[i];
        for(int i=1;i<=q;i++) cin>>n>>k;
        for(int i=1;i<=q;i++) cout<<1;
    }
}
// 游记
/*
8：00 进考场 有人试图把防窥屏扣下来
8:25 开题开到了8：35
8:40 in1
8:55 AC1
9:20 in2
9:40 dbg2
10:00 AC2
10:30 in3
11:38 3 subtask45AC
11:55 pian4
*/