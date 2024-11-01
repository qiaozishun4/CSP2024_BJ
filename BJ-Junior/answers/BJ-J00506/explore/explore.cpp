#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for (int i=1;i<=t;i++){
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        string s;
        cin>>s;
        if(m==1){
            cout<<"0"<<"\n";
        }
        else if(d==0){
            if(y!=m){
                if(s[m-1]=='x'){
                    cout<<0<<"\n";
                }
                else{
                    cout<<1<<"\n";
                }
            }
            else{
                cout<<"0"<<"\n";
            }
        }
        else if(d==2){
            if(y==m){
                if(s[0]=='x'){
                    cout<<"0"<<"\n";
                }
                else{
                    cout<<1<<"\n";
                }
            }
            else{
                cout<<"0"<<"\n";
            }
        }
    }
}