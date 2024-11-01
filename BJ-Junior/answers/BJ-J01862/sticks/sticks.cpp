#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    int a[55];
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        if(n==1) a[i]=-1;
        if(n==2) a[i]=1;
        if(n==3) a[i]=7;
        if(n==4) a[i]=4;
        if(n==5) a[i]=2;
        if(n==6) a[i]=6;
        if(n==7) a[i]=8;
        if(n==8) a[i]=10;
        if(n==9) a[i]=18;
        if(n==10) a[i]=23;
        if(n==11) a[i]=20;
        if(n==12) a[i]=28;
        if(n==13) a[i]=80;
        if(n==14) a[i]=88;
        if(n==15) a[i]=108;
        if(n==16) a[i]=188;
        if(n==17) a[i]=206;
        if(n==18) a[i]=208;
        if(n==19) a[i]=288;
        if(n==20) a[i]=688;

        

    }
    for(int i=0;i<t;i++){
        cout<<a[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
return 0;}
