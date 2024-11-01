#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#define ll long long
#define MAXN 1e9+9;
using namespace std;

unsigned long long n,a[300010],ans=0,sum=0;

struct{
    long long name;
    long long numbe;
}b[400010];

bool cmp(long long a,long long b){
    return a<b;
}

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);

    for(long long i=1;i<=n;i++){
        if(i==1){
            b[++ans].name=a[i];
            b[ans].numbe++;
        }
        else if(b[ans].name==a[i]){
            b[ans].numbe++;
        }
        else if(b[ans].name!=a[i]){
            b[++ans].name=a[i];
            b[ans].numbe++;
        }
    }

    for(long long i=1;i<ans;i++){
        b[i].numbe-=b[i+1].numbe;
        sum+=b[i].numbe;
    }
    if(sum<0){
        cout<<b[ans].numbe;
    }
    else{
        cout<<sum+b[ans].numbe;
    }

    return 0;
}
