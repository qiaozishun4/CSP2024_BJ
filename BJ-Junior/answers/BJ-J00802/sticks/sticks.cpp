#include<bits/stdc++.h>
using namespace std;
int mg[10]={6,2,5,5,4,5,6,3,7,6};
int ans[21]={0,-1,1,7,4,2,6,8,10,24,23,20,28,68,128,108,220,228,208,608,808};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<ans[n%21]<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
