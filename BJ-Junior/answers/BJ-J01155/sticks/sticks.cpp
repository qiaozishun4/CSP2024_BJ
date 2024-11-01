#include<bits/stdc++.h>
using namespace std;
int t,n;

int stick(int x){
    if(x==1) return 2;
    if(x==7) return 3;
    if(x==4) return 4;
    if(x==2 || x==3 || x==5) return 5;
    if(x==0 || x==6 || x==9) return 6;
    if(x==8) return 7;
}

int sumstick(int x){
    int ans=0;
    while(x){
        ans+=stick(x%10);
        x/=10;
    }
    return ans;
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1) cout<<-1<<endl;
        else{
            for(long long i=1;;i++){
                if(sumstick(i)==n){
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}