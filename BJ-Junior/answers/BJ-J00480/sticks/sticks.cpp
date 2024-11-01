#include<bits/stdc++.h>//long long
using namespace std;
int tp[100]={-1,-1,1,7,4,2,6,8};
int ans[100]={8,10,18,22,20,28,68,88};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    char c;
    cin>>T;
    for(int t=1;t<=T;t++){
        int n;
        cin>>n;
        if(n<=7){
            cout<<tp[n]<<endl;
            continue;
        }
        int tmp=n/7-1;
        int tmp2=n%7;
        cout<<ans[tmp2];
        while(tmp--)cout<<8;
        cout<<endl;
    }
    return 0;
}
