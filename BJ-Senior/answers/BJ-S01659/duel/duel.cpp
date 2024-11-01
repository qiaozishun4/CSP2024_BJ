#include<bits/stdc++.h>

using namespace std;
template<class T>void read(T &x){
    x=0;
    int f=0;
    char c=getchar();
    while(!isdigit(c)){
        f|=(c=='-');
        c=getchar();
    }
    while(isdigit(c)){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    if(f)x=-x;
    return;
}
const int N=1e5+5;
int a[N];
queue<int>q;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    read(n);
    for(int i=1;i<=n;i++){
        read(a[i]);
    }
    sort(a+1,a+1+n);
    q.push(a[1]);
    int ans=n;
    for(int i=2;i<=n;i++){
        if(q.front()<a[i])q.pop(),ans--;
        q.push(a[i]);
    }
    printf("%d",ans);
    return 0;
}
