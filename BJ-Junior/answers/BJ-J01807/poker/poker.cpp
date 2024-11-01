#include<bits/stdc++.h>
using namespace std;
int n,sum=52;
bool f[1000010];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        int s=a*131+b;
        if(!f[s]){
            f[s]=true;
            sum--;
        }
    }
    cout<<sum<<'\n';
    return 0;
}
