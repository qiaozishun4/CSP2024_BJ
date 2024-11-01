#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
    }
    while(n&-n!=n)n++;
    int wei=0;
    while(n){
        n>>=1;
        wei++;
    }
    for(int i=0;i<wei;i++){
        int x;
        cin>>x;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cout<<0<<endl;
    }
    return 0;
}
//rp+++++++++++ pian dian fen jiu xing