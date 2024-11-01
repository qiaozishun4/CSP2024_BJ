#include<bits/stdc++.h>
using namespace std;
int d[]={6,2,5,5,4,5,6,3,7,6};
int fi(int n){
    int ans=0;
    while(n){
        ans+=d[n%10];
        n/=10;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<2){
            cout<<-1<<endl;
            continue;
        }
        bool f=0;
        int i=1;
        while(!f){
            if(fi(i)==n){
                f=1;
                cout<<i<<endl;
                break;
            }
            i++;
        }
    }
    return 0;
}
