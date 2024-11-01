#include<iostream>
#include<algorithm>
using namespace std;
const int N=100100;
inline int read(){
    int i=getchar(),r=0;
    while(i<'0'||i>'9')i=getchar();
    while(i>='0'&&i<='9')r=(r<<1)+(r<<3)+(i^48),i=getchar();
    return r;
}
int n,a[N],cnt[N];
void init(){
    cin>>n;
    for(int i=1;i<=n;i++)cnt[read()]++;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    init();
    int ans=0;
    int now=0;
    for(int i=1;i<N;i++){
        int x=min(now,cnt[i]);
        ans+=x;
        now-=x;
        now+=cnt[i];
    }
    cout<<n-ans;
    fflush(stdout);
    fflush(stdin);
    fclose(stdin);
    fclose(stdout);
    return 0;
}