#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=101000;
int n,r[maxn],zz1,zz2;
inline int cmp(int x,int y){return x>y;}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>r[i];
    sort(r+1,r+n+1,cmp);
    zz1=zz2=n;
    while(zz1){
        while(zz1&&r[zz1]<=r[zz2])zz1--;
        if(zz1&&r[zz1]>r[zz2])zz1--,zz2--;
    }
    cout<<zz2;
    return 0;
}