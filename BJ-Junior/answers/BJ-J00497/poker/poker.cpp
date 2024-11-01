#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
string p;
bool f[150][150];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    memset(f,true,sizeof(f));
    for(int i=1;i<=n;i++){
        cin>>p;
        int a=p[0],b=p[1];
        if(f[a][b]==true){
            sum++;
            f[a][b]=false;
        }
    }
    cout<<52-sum;
    return 0;
}
