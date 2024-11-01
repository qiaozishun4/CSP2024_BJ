#include<bits/stdc++.h>
using namespace std;
int t;
int n,k,q;
struct chain{
    int l;
    vector<int > s[200005];
};
int r,c;

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int lll=0;lll<t;lll++){
        cin>>n>>k>>q;
        vector<chain > a(n+5);
        for(int i=1;i<=n;i++){
            cin>>a[i].l;
            for(int j=1;j<=a[i].l;j++){
                cin>>(a[i]).s[j];
            }
        }
        for(int kkk=0;kkk<q;kkk++){
            cin>>r>>c;
            if(r==1){
                cout<<0<<endl;
                continue;
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=a[i].l;j++){
                    if(a[i].s[j]==c){
                        flg=1;
                        break;
                    }
                }
            }
            if(flg==0){
                cout<<0<<endl;
                continue;
            }
            cout<<1<<endl;
        }
    }
    return 0;
}
