#include<bits/stdc++.h>
using namespace std;
int a=1,b,ans=52,n;
string mem[60],r;
int main(){
    freopen("pocker.in","r",stdin);
    freopen("pocker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r;
        b=1;
        for(int i=1;i<=a;i++){
            if(r==mem[i]){
                b=0;
                break;
            }
        }
        if(b==1){
            ans--;
            mem[a]=r;
            a++;
        }
    }
    cout<<ans;
    return 0;
}