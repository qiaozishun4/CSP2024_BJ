#include<bits/stdc++.h>
using namespace std;

const long long maxn = 100000000;
int num[10] = {6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n == 1){
            cout<<"-1"<<endl;
            continue;
        }
        bool flag = 0;
        for(int i = 1; i <= maxn; i++){
            int k = i,st = n;
            while(k){
                int s = k%10;
                k /= 10;
                st -= num[s];
                if(st < 0){
                    break;
                }
            }
            if(st == 0){
                flag = 1;
                cout<<i<<endl;
                break;
            }
        }
        if(!flag){
            cout<<"-1"<<endl;
        }
    }

    return 0;
}