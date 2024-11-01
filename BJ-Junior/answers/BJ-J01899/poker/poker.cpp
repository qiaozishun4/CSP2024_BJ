#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,a=52,b[128][128]={};
    cin>>n;
    for(int i=1;i<=n;i++){
        char s,s1;
        cin>>s>>s1;
        if(b[s][s1]==0) a--;
        b[s][s1]++;
    }
    cout<<a;
    return 0;
}
