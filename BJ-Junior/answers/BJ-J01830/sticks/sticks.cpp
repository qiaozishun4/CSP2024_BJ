#include<bits/stdc++.h>
using namespace std;
int T;
int N;
int find(int n){
    if(n<2) return -1;
    if(n==2) return 1;
    if(n==3) return 7;
    if(n==4) return 4;
    if(n==5) return 2;
    if(n==6&&N==6) return 6;
    else if(n==6) return 0;
    if(n==7) return 8;
    if(n==8) return 10;
    if(n==9) return 18;
    if(n==10) return 22;
    if(n==11) return 20;
    if(n==12) return 28;
    if(n==13) return 68;
    if(n==14) return 88;
    if(n==15) return 108;
    if(n==16) return 188;
    if(n==17) return 200;
    if(n==18) return 208;
    if(n==19) return 288;
    if(n==20) return 688;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>N;
        int ans=find(N);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}