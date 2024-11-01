#include <iostream>
#include <cstdlib>
using namespace std;

const int single[10]={-1,-1,1,7,4,2,6,8};
const int multi[10]={8,16,18,22,20,28,68};

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<=7){
            cout<<single[n]<<'\n';
        }else{
            cout<<multi[n%7];
            for(int i=1;i<=(n-7)/7;++i){
                cout<<'8';
            }cout<<'\n';
        }
    }return 0;
}
