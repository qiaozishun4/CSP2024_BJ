#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,r[100010],t[100010],v[100010];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    for(int i=1;i<=n;i++){
        t[i] = 0;
    }
    for(int i=1;i<=n;i++){
        v[i] = 0;
    }
    int o = 0,s = 0;
    for(int i=1;i<=n;i++){
        int m = 1;
        o+=1;
        if(n == s){
            break;
        }
        if(o!=1){
            for(int i=1;i<=n;i++){
                if(v[i]!=1 && r[m]>r[i]){
                    m = i;
                }
            }
        }else{
            for(int j=1;j<=n;j++){
                if(r[m]>r[j]){
                    m = j;
                }
            }
        }
        for(int z=1;z<=n;z++){
            if(r[m]==r[z]){
                v[z] = 1;
                t[o]+=1;
            }
        }
        s+=t[o];
    }
    for(int i=1;i<=n-1;i++){
        if(t[i+1]>=t[i]){
            t[i] = 0;
        }else if(t[i+1]<t[i]){
            t[i] = t[i]-t[i+1];
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans+=t[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
