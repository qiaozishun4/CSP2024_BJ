#include<bits/stdc++.h>
using namespace std;
int L,T,V,a,c,d,m,n,v;
int main(){
    freopen("detect.in","r",stdin),freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        c=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d>>v>>a;
            if(v>V)c++;
        }
        for(int i=1;i<=m;i++)cin>>a;
        cout<<c<<" "<<m-1<<endl;
    }
    return 0;
}
