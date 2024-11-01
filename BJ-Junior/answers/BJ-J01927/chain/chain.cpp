#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
const int L = 2e5 + 9;
int n,t,k,q,l[N],s[L],c[N],r[N];

void Main(){

    cin>>n>>k>>q;

    if(k==2e5){
        cout<<0<<endl;
        return;
    }

    for(int i=1;i<=n;++i){
        cin>>l[i];
        for(int j=1;j<=l[i];++j){
            cin>>s[j];
        }

    }
    for(int i=1;i<=q;++i){
        cin>>r[i]>>c[i];
        if(k<=5){
            if(s[(int)(ceil(n*1.0/r[i]))]==c[i]){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
    }



}

int main(){

    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    cin>>t;
    for(int i=1;i<=t;++i){
        Main();
    }

    return 0;
}
