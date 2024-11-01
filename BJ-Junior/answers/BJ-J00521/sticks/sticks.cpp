#include<bits/stdc++.h>
using namespace std;
const int solution[]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};
int n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        if(n<=21)cout<<solution[n]<<'\n';
        else{
            int k=n/7;
            k-=2;
            cout<<solution[14+n%7];
            for(int i=1;i<=k;i++)cout<<'8';
            cout<<'\n';
        }
    }
    return 0;
}
