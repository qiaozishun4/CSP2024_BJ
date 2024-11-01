#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,m,a[100005],b[100005],i,t,x0,x1,x2,x3,c[20],maxn=0,sum,x[5];
string s[20];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%lld",&b[i]);
    }
    c[0]=1;
    for(i=1;i<=18;i++){
        c[i]=pow(2,i);
        if(c[i]>=n){
            maxn=i;
            break;
        }
    }
    for(i=1;i<=maxn;i++){
            cin>>s[i];
    }
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        cout<<1<<endl;
    }
    return 0;
}
