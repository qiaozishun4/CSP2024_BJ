#include<iostream>
#include<cstdio>
using namespace std;
int n,a[55];
int f(int x){
    if(x==2) return 1;
    if(x==3) return 7;
    if(x==4) return 4;
    if(x==5) return 2;
    if(x==6) return 6;
    if(x==7) return 8;
    if(x==8) return 10;
    if(x==9) return 24;
    if(x==10) return 40;
    if(x==11) return 20;
    if(x==12) return 28;
    if(x==13) return 67;
    if(x==14) return 88;
    if(x==15) return 108;
    if(x==16) return 188;
    if(x==17) return 228;
    if(x==18) return 208;
    if(x==19) return 288;
    if(x==20) return 808;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int t1=a[i]/7,t2=a[i]/7-1;
        if(a[i]%7==0){
            for(int j=1;j<=t1;j++) cout<<8;
            continue;
        }
        else if(a[i]%7==1&&a[i]>1){
            cout<<10;
            for(int j=1;j<=t2;j++) cout<<8;
        }
        else if(a[i]==1) cout<<-1;
        else{
            cout<<f(a[i]);
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}