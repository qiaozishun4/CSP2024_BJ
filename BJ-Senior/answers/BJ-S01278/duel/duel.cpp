#include <bits/stdc++.h>
using namespace std;
int n,ans;
int r[100005];
int hx[100005];
int maxi=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        hx[r[i]]++;
        maxi=max(maxi,r[i]);
    }
    int pre=1;int cur=2;
    while(cur<=maxi&&pre<cur){
        if(hx[pre]>0&&hx[cur]>0){
            if(hx[cur]-hx[pre]>0){//cur rest
                hx[pre]=0;
                if(cur-pre>1)
                    pre++;
                else{
                    cur++;
                    pre++;
                }
            }else{//pre rest
                hx[pre]-=hx[cur];
                cur++;
            }
        }else if(hx[cur]==0&&hx[pre]==0){
            cur++;
            pre++;
        }else if(hx[cur]==0){
            cur++;
        }else if(cur-pre==1){
            cur++;
            pre++;
        }else
            pre++;
    }
    for(int i=1;i<=maxi;i++){
        ans+=hx[i];
    }
    cout<<ans;
    return 0;
}
