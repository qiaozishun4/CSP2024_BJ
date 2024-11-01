#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int Maxn=1e5+5;
int n,k,a[Maxn],x[Maxn];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        x[a[i]]++;
    }

    for(int i=0;i<=100000;i++){
        if(k==0&&x[i])k=x[i];
        else if(k&&x[i]){
            if(k>=x[i]){
                x[i]=0;
                k-=x[i];
            }
            else if(k<x[i]){
                //x[i]-=k;
                k=x[i];
            }
        }
        //cout<<k<<endl;
    }
    cout<<k<<endl;
    return 0;
}
