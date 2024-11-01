#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
ll n,a[100005],t1,t2;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){
            t1=t1+t2;
            t2=0;
            if(t1>=1){
                t1=t1-1;
            }
            t2++;
        }else{
            if(t1>=1){
                t1=t1-1;
            }
            t2++;
        }
    }
    cout<<t1+t2<<endl;
    return 0;
}
