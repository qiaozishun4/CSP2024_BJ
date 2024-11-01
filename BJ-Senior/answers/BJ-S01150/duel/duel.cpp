#include<bits/stdc++.h>
using namespace std;
int a[200002];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int i,j,n,k;
    cin>>n;
    memset(a,0,sizeof(a));
    for(i=0;i<n;i++){
        cin>>k;
        a[k]++;
    }int s=a[0];
    for(i=1;i<200000;i++){
        if(s>a[i]){
            n-=a[i];
        }else{
            n-=s;
            s=a[i];
        }
    }cout<<n;
}
