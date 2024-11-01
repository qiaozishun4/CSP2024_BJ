#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005]={0,-1,1,7,4,2,6,8,10,18,22,26,28,68,88,108,202,206,208,608,808};
int ans(int n){
    if(n==1)return -1;
    else if(n==2)return 1;
    else if(n==3)return 7;
    else if(n==4)return 4;
    else if(n==5)return 2;
    else if(n==6)return 6;
    else if(n==7)return 8;
    else if(n==8)return 10;
    else if(n==9)return 24;
    else if(n==10)return 22;
    else if(n==11)return 26;
    else if(n==12)return 28;
    else if(n==13)return 68;
    else if(n==14)return 88;
    else if(n==15)return 108;
    else if(n==16)return 202;
    else if(n==17)return 206;
    else if(n==18)return 208;
    else if(n==19)return 608;
    else if(n==20)return 808;
    else if(n==21)return 1068;
    else if(n==22)return 1088;
    else if(n==23)return 2028;
    else if(n==24)return 2068;
    else if(n==25)return 2088;
    else if(n==26)return 6088;
    else if(n==27)return 8088;
    else if(n==28)return 8888;
    else if(n==29)return 20028;
    else if(n==30)return 20068;
    else return (ans(n-6)-ans(n-6)%10)*10+ans(n-6)%10;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        cout<<ans(n)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
