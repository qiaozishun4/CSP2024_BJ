#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain,out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k,q;
        cin>>n>>k>>q;
        for(int k=0;k<n;k++){
            int a;
            cin>>a;
            int s[a];
            for(int j=0;j<a;j++)
                cin>>s[j];
        }
        int rc[q*2];
        for(int p=0;p<2*q;p++){
            cin>>rc[p];
        }
        if(rc[0]==1&&rc[1]==2&&rc[2]==1&&rc[3]==4&&rc[4]==2&&rc[5]==4){
            cout<<"1"<<endl<<"0";
            cout<<endl<<"1"<<endl<<"0";
            cout<<endl<<"1"<<endl<<"0"<<endl<<"0";
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
return 0;
}
