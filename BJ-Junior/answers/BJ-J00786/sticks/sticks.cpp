#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,a,dp[100005]={-1,-1,1,1,1,1,1,1};
    int num[100005]={0},ans1[7]={-1,-1,1,7,4,2,6},ans2[7]={8,16,18,22,20,28,68};
    cin>>n;
    for(int qwerty=0;qwerty<n;qwerty++){
        cin>>a;
        if(a<7) cout<<ans1[a];
        else{
            cout<<ans2[a%7];
            int s=(a-8)/8;
            for(int i=0;i<s;i++){
                cout<<8;
            }
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
