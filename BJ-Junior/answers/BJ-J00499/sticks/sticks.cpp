#include<bits/stdc++.h>
using namespace std;
int sh[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m[6];
        cin>>n;
        if(n<15){
            string ans[15]={"-1","-1","1","7","4","2","6","8","10","18","22","20","28","68","88"};
            cout<<ans[n]<<endl;
            continue;
        }
        string ans[n+1]={"-1","-1","1","7","4","2","6","8","10","18","22","20","28","68","88"};
        for(int i=15;i<=n;i++){
            ans[i]=ans[i-7]+'8';
        }
        cout<<ans[n]<<endl;
    }
    return 0;
}
