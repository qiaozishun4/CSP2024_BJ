#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int an[30]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cnt=n/7;
        cnt--;
        cnt=max(cnt,0);
        n-=cnt*7;
        cout<<an[n];
        for(int i=1;i<=cnt;i++){
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
