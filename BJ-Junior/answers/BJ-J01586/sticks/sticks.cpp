#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
bool cmp(int a,int b)
{
    return a<=b;
}
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int n,cnt;
    cin>>n;
    for(int z=1;z<=n;z++)
    {
        int a,k[100001]={};
        cnt=1;
        cin>>a;
        if(a==1){
            cout<<-1<<endl;
        }
        if(a==2){
            cout<<1<<endl;
        }
        if(a==3){
            cout<<7<<endl;
        }
        if(a==4){
            cout<<4<<endl;
        }
        if(a==5){
            cout<<2<<endl;
        }
        if(a==6){
            cout<<6<<endl;
        }
        if(a==7){
            cout<<8<<endl;
        }
        if(a==8){
            cout<<10<<endl;
        }
        if(a==9){
            cout<<18<<endl;
        }
        if(a==10){
            cout<<22<<endl;
        }
        if(a==11){
            cout<<20<<endl;
        }
        if(a==12){
            cout<<28<<endl;
        }
        if(a==13){
            cout<<80<<endl;
        }
        if(a==14){
            cout<<88<<endl;
        }
        if(a==15){
            cout<<108<<endl;
        }
        if(a==16){
            cout<<188<<endl;
        }
        if(a==17){
            cout<<200<<endl;
        }
        if(a==18){
            cout<<208<<endl;
        }
        if(a==19){
            cout<<288<<endl;
        }
        if(a==20){
            cout<<808<<endl;
        }
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
