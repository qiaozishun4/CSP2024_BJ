#include<bits/stdc++.h>
using namespace std;

int T;
const int st[]={6,2,5,5,4,5,6,3,7,6};
const int ans[]={-1,-1,1,7,4,2,6,8};

void mian(){
    int n;
    cin>>n;
    if(n<=7){
        cout<<ans[n]<<"\n";
        return;
    }
    int k=(n-1)/7+1;
    int m=n%7;
    for(int i=1;i<=9;++i){
        if(m==st[i]){
            putchar(i|48);
            for(int i=1;i<k;++i)putchar('8');
            putchar('\n');
            return;
        }
        if(m<st[i]){
            putchar(i|48);
            int l=7-st[i]+m;
            for(int j=0;i<=9;++i){
                if(st[j]==l){
                    putchar(j|48);
                    break;
                }
            }
            for(int i=1;i<k-1;++i)putchar('8');
            putchar('\n');
            return;
        }
    }
    cout<<-1;
    return;
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("skicks.out","w",stdout);
    cin>>T;
    while(T--){
        mian();
    }
    return 0;
}
