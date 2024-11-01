#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int t,n,m,l,v,d,r,a;
    string z;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m>>l>>v;
        for(int j=0;j<n;j++){
            cin>>d>>r>>a;
        }
        getline(cin,z);
    }
    for(int i=0;i<t;i++){
    cout<<n+m%2<<endl;
    cout<<n%2+m/2<<endl;}
    fclose (stdin);
    fclose(stdout);
return 0;}
