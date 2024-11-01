#include<iostream>
using namespace std;
int s[100005][200005]={};
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,k,q;
        cin>>n>>k>>q;
        int m_s=0;
        for(int i=1;i<=n;i++){
            cin>>s[i][0];
            for(int j=1;j<=s[i][0];j++){
                cout<<s[i][j];
                m_s=max(m_s,s[i][j]);
            }
        }


        while(q--){
            int r,c;
            cin>>r>>c;
            if(r*2>c||m_s<c){
                cout<<0<<'\n';
                break;
            }
            cout<<1<<'\n';
        }
    }
    return 0;
}
