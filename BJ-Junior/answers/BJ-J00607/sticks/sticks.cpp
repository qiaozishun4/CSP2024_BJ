#include<iostream>
using namespace std;
const int ans1[7]={-1,1,7,4,2,6,8};
const int ans2[7]={10,18,22,20,28,68,88};
const int ans3[7]={108,188,200,208,288,688,888};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin.tie(nullptr)->sync_with_stdio(0);
    for(cin>>T;T;T--){
        int n;
        cin>>n;
        if(n<=1) cout<<-1<<'\n';
        else{
            n--;
            int len=(n/7)+1;
            if(len<=1) cout<<ans1[n%7]<<'\n';
            else if(len==2) cout<<ans2[n%7]<<'\n';
            else{
                len-=3;
                cout<<ans3[n%7];
                for(int i=0;i<len;i++) cout<<8;
                cout<<'\n';
            }
        }
    }
    return 0;
}