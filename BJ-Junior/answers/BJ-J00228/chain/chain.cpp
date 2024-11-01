#include<bits/stdc++.h>
using namespace std;
void f(){
    int n,k,q,r,c;
    string a[100005];
    cin>>n>>k>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<q;i++){
        int sprt=0,cnt=0,cntn=0;
        cin>>q>>c;
        int x=q%n;
        if(q%n==0){
            x=q;
        }
        for(int i=0;i<x;i++){
            for(int j=0;j<k;j++){
                if(a[i][j]==c){
                    sqrt=1;
                    cnt=j;
                    break;
                }
            }
        }
        if(x==1){
            for(int i=cnt-k;i<cnt;i++){
                if(a[0][i]=='1'){
                    cout<<1<<endl;
                    return;
                }
            }
            cout<<0<<endl;
            return;
        }
        cout<<sqrt<<endl;
    }
}
int main(){

    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    int t;
    cin>>t;
    for(int i=0;i<t;i++)f();

    return 0;
}
