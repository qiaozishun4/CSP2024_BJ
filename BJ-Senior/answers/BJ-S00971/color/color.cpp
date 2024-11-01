#include<bits/stdc++.h>
using namespace std;
int n,maxn=0;
int check[200005];
int a[200005];
int findn(int point,int ans){
    if(point==n+1){
        maxn=max(ans,maxn);
        return 0;
    }
    for(int p=0;p<=1;p++){
    check[point]=p;
    int g=0;
    for(int i=1;i<point;i++){
        if(check[i]==check[point]){
            g=i;
        }
    }
    if(g && a[g]==a[point]){
        findn(point+1,ans+a[point]);
    }else{
        findn(point+1,ans);
    }
    }
    return 0;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    check[1]=0;
    findn(2,0);
    cout<<maxn<<endl;
    maxn=0;
    }
    return 0;
}