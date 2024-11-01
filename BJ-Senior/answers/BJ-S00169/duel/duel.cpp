#include<bits/stdc++.h>
using namespace std;
int x[100010],t[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        t[x[i]]++;
    }
    sort(x+1,x+n+1);
    int ans=0,fl=0;
    for(int i=1;i<=x[n];i++){
        if(t[i]){
            if(fl==0)fl=i;
            for(int j=1;j<=t[i];j++){
                if(i>fl){
                    t[fl]--;
                }
                if(t[fl]==0){
                    for(int k=fl+1;k<=x[n];k++)if(t[k]){fl=k;break;}
                }
            }
        }
    }
    for(int i=1;i<=x[n];i++)ans+=t[i];
    cout<<ans;
    return 0;
}
