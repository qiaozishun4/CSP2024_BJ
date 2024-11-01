#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long r[100010],b[100010];
bool f[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n ;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        b[r[i]]++;
    }
    sort(r+1,r+n+1);
    long long cnt=0;
    for(int i=1;i<=n;i++){
        if(f[r[i]])continue;
        f[r[i]]=1;
        if(i==1){
            cnt=b[r[i]];
            continue;
        }
        if(b[r[i]]>cnt)cnt=0;
        else cnt-=b[r[i]];
        cnt+=b[r[i]];
    }
    cout<<cnt;
    return 0;
}
