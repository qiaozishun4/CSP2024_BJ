#include<iostream>
#include<cstdio>
using namespace std;
int s[1005][2005],l[1005],aft[2005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,k,q,pre1=-0x3f3f3f3f,k1=0;
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            cin>>l[i];
            pre1=-0x3f3f3f3f;
            for(int j=0;j<l[i];j++){
                cin>>s[i][j];
                if(j-pre1<k) aft[k1++]=s[i][j];
                if(s[i][j]==1) pre1=j;
            }
        }
        int r,c;
        for(int i=0;i<q;i++){
            cin>>r>>c;
            bool f=0;
            if(r==1){
                for(int i=0;i<k1;i++){
                    if(aft[i]==c){
                        f=1;
                        break;
                    }
                }
            }
            cout<<(int)f<<'\n';
        }
    }
    return 0;
}
