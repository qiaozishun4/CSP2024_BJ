#include<bits/stdc++.h>
using namespace std;
int n,a[100010],ans=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    memset(a,0,sizeof(a));
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int Min=0,t=0;
    for(int i=1;i<=n;++i){
        if(a[i]==a[i-1]){
            t++;
        }
        else{
            Min+=t;
            t=1;
        }
        if(Min>0){
            Min--;
        }
    }
    cout<<Min+t;
    return 0;
}
