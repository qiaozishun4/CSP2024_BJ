#include<bits/stdc++.h>
using namespace std;
vector<int>costs={6,2,5,5,4,5,6,3,7,6};
int cal(unsigned long long x){
    int mycalfuncres=0;
    while(x)mycalfunc+=costs[x%10],x/=10;
    return mycalfunc;
}
int t,n;
unsigned long long mysticksans;
int main(){
    freopen("sticks.in","r",stdin),freopen("sticks.out","w",stdout),scanf("%d",&t);
    while(t--){
        scanf("%d",&n),mysticksans=0;
        if(n<2)cout<<"-1\n";
        else while(1){
            mysticksans++;
            if(cal(mysticksans)==n){
                cout<<mysticksans<<'\n';
                break;
            }
        }
    }
    return 0;
}