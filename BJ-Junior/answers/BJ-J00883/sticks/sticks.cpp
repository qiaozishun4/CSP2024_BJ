#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,a[100001],k;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        if(a[i]==1){
            cout<<-1;
        }
        if(a[i]==2){
            cout<<1;
        }
        if(a[i]==3) cout<<7;
        if(a[i]==4) cout<<4;
        if(a[i]==5) cout<<2;
        if(a[i]==6) cout<<6;
        if(a[i]==7) cout<<8;
        if(a[i]==9) cout<<18;
        if(a[i]==10) cout<<22;
        if(a[i]==11) cout<<20;
        if(a[i]==12) cout<<28;
        if(a[i]==13) cout<<68;
        if(a[i]==14) cout<<88;
        if(a[i]==15) cout<<108;
        if(a[i]==16) cout<<188;
        if(a[i]==17) cout<<200;
        if(a[i]==18) cout<<208;
        if(a[i]==19) cout<<288;
        if(a[i]==20) cout<<688;
        if(a[i]%7==0&&a[i]>20){
            for(int i=0;i<a[i]/7;i++){
                cout<<8;
            }
        }
        if(a[i]%7==1&&a[i]>=100){
            cout<<10;
            for(int i=0;i<a[i]/7-1;i++) cout<<8;
        }
        cout<<endl;
    }

    //fclose("sticks.in");
    //fclose("sticks.out");
    return 0;
}
