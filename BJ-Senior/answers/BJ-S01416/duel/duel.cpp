#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <vector>
#include <ctime>
using namespace std;
long long read(){
    long long x=0,k=1;
    char c=getchar();
    for(;c!='-'&&(c<'0'||c>'9');c=getchar());
    if(c=='-') k=-1,c=getchar();
    for(;'0'<=c&&c<='9';x=(x<<1)+(x<<3)+c-'0',c=getchar());
    return x*k;
}
int n,a[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    int ans=0,lst=0;
    for(int i=1;i<=n;i++) {
        if(a[i]>a[i-1]) ans+=lst,lst=0;
        if(ans) ans--;
        lst++;
    }
    cout<<ans+lst<<endl;
    return 0;
}