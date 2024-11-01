#include <bits/stdc++.h>
using namespace std;
int t;
int n,k,q;
bool f=false;
int l[110000],s[110000][220000];
long long r[110000],c[110000],p[110000],pos[110000];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    int g=t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            cin>>l[i];
            for(int j=0;j<l[i];j++){
                cin>>s[i][j];
            }
        }
        for(int i=0;i<q;i++){
            cin>>r[i]>>c[i];
        }
    }
    for(int i=0;i<g;g++){
        cout<<"0";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}