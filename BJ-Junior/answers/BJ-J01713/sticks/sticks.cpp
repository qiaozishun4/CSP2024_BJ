#include<bits/stdc++.h>
using namespace std;
int n;
int a,d,flag,blag;
int possible[N];
const int N=1e6+6;
int s[11]{6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin>>n;
    while(cin>>a){
    for(int i=a;i>0;){
    if(a<=7){for(int j=0;j<=9;i++)if(a==s[j]){ans+=j,flag=1;cout<<j;i=0;}if(flag==0)(cout<<-1;i=0)
}   else{
i-=2,blag=1;cout<<1;if(blag==1&&i>7){i-=6;cout<<0;
}
    }
        }
    }
    return 0;
}
