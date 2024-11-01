#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,r[MAXN];
    int status[MAXN];
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>r[i];
    }
    memset(status, 0,sizeof(status));

    sort(r,r+n);
    int lt=0,rt = 1;
    while(lt<rt){

        if(r[rt] > r[lt]){
            status[lt] = 2;
            status[rt] = 1;
            while(status[++rt]!=0) if(rt >= n) break;
            while(status[++lt]==2);
        }
        else{
            rt++;
        }
        if(rt >= n) break;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(status[i] != 2) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
