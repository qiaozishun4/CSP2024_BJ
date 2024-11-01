#include<bits/stdc++.h>
using namespace std;
int d;
int v;
int a;
int j;
int main(){
freopen("detect.in","r",stdin);
freopen("detect.out","w",stdout);

int t;
cin>>t;
while(t--){
    int n,m,l,V,ans=0;
    cin>>n>>m>>l>>V;
    for(int i=1;i<=n;i++){
        cin>>d>>v>>a;
        if(v>V) ans++;
    }
    for(int i=1;i<=m;i++){
        cin>>j;
    }
    cout<<ans<<" "<<m-1;
}

fclose(stdin);
fclose(stdout);
    return 0;
}
