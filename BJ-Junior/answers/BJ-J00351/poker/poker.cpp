//poker
#include <bits/stdc++.h>
using namespace std;
char fp[60],np[60],r;
int n,cnt=52;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char fpx,npx;
        cin>>fpx>>npx;
        int f=0;
        for(int j=1;j<i;j++){
            if(fp[j]==fpx && np[j]==npx) f=1;
        }
        if(f==0){
            fp[i]=fpx;
            np[i]=npx;
            cnt--;
        }

    }
    cout<<cnt;

    return 0;
}
