#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("duel.in","r", stdin);
    freopen("duel.out","w", stdout);

    int n;
    cin>>n;
    int r[100009];
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+1+n);
    int p[100009];
    queue<int> nxt;
    memset(p,-1,sizeof(p));
    for(int i=1;i<=n;i++){
        if(p[r[i]]==-1){
            p[r[i]]=i;
            nxt.push(r[i]);
        }
    }
    int i;
    for (i=1;i<=n;i++){/*斗不过
  C++ */if (!nxt.empty() && nxt.front()<=r[i]){nxt.pop();}/*
  !!! */if (nxt.empty()){break;}/*
  ??? */int x=nxt.front();/*
LOL   *//*
Happy */int ijij=p[x];/*
 Love */++p[x];/*
114514*/if (r[p[x]]==-1) {break;}/*啥都没了
Hello *//*
World */if(r[p[x]]!=r[ijij]){/* 用完了
  123 */if (!nxt.empty()){nxt.pop();}/*除掉
  233 */}
    }
    cout<<n-i+1;
    return 0;
}
