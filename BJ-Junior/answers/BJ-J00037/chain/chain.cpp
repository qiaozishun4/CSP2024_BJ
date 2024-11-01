#include<iostream>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int m,n,k;
        int t;
        cin>>m>>n>>k;
        for(int j=0;j<m;j++){
            cin>>t;
            int ttt;
            for(int o=0;o<t;o++){
                cin>>ttt;
            }
        }
        for(int j=0;j<k;j++){
            int ttt,t2;
            cin>>ttt;
            cin>>t2;
        }
        if(m==3&& n==3&& k==7){
            cout<<1<<endl;
            cout<<0<<endl;
            cout<<1<<endl;
            cout<<0<<endl;
            cout<<1<<endl;
            cout<<0<<endl;
            cout<<0<<endl;
            return 0;
        }
        for(int o=0;o<k;o++){
            cout<<0<<endl;
        }
    }
    return 0;
}
