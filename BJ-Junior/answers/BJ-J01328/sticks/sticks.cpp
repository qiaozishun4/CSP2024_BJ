#include<bits/stdc++.h>
using namespace std;
const int stick[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=0;i<10;i++){
            if(stick[i]==n) cout<<i<<endl;
        }
        if(n<2) cout<<-1<<endl; continue;
    }
    return 0;
}
