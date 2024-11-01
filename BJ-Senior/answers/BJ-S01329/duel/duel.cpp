#include <bits/stdc++.h>
using namespace std;

const int MAXN=10005;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,a[MAXN],num=0;
    bool duelcraft1[MAXN],duelcraft2[MAXN],flag=true;

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        duelcraft1[i]=true;
        duelcraft2[i]=true;
    }

    for(int i=1;i<n;i++){
        if(duelcraft1[i]==false||duelcraft2[i]==false) continue;
        if(a[i]>a[i+1]){
            duelcraft1[i+1]=false;
            duelcraft2[i+1]=false;
            duelcraft2[i]=false;
        }else if(a[i+1]>a[i]){
            duelcraft1[i]=false;
            duelcraft2[i]=false;
            duelcraft2[i+1]=false;
        }
    }
    for(int i=1;i<=n;i++) if(duelcraft1[i]==true) num++;
    
    cout<<num<<endl;
    return 0;
}