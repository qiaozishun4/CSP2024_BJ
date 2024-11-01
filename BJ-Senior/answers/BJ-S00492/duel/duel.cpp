#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    int num,ans=0;
    int r[100010];
    bool f[100010];

    cin>>num;
    ans=num;
    for(int i=0; i<num; i++){
        cin>>r[i];
    }
    for(int i=0; i<num; i++){
        f[i]=false;
    }
    for(int i=0; i<num; i++){
        if(r[i]<r[i+1]&&f[i]==false&&f[i+1]==false){
            f[i]=true;
            r[i]=-1;
        }
    }
    for(int i=0; i<num; i++){
        if(r[i]==-1){
            ans--;
        }
    }

    cout<<ans<<endl;

    return 0;
}
