#include<bits/stdc++.h>
using namespace std;
const int stick[]={6,2,5,5,4,5,6,3,7,6};
int n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        if(t<2){
            cout<<"-1\n";
            continue;
        }
        for(long long i=1;;i++){
            int a[20],len=0;
            long long x=i;
            while(x){
                a[len++]=x%10;
                x/=10;
            }
            int cnt=0;
            for(int j=0;j<len;j++)cnt+=stick[a[j]];
            if(cnt==t){
                cout<<i<<'\n';
                break;
            }
        }
    }
    return 0;
}
