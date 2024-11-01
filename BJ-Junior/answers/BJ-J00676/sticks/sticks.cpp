#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
int main(){
   // freopen("sticks1.in","r",stdin);
    //freopen("sticks1.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        if(a==1){
            cout<<-1<<"\n";
            continue;
        }
        if(a<=7){
            if(a==2) cout<<1;
            if(a==3) cout<<7;
            if(a==4) cout<<4;
            if(a==5) cout<<2;
            if(a==6) cout<<6;
            if(a==7) cout<<8;
            cout<<"\n";
            continue;
        }
        int f=a/7,p=a%7;
        if(p==0||p==2||p==5){
            if(p==2) cout<<1;
            if(p==5) cout<<2;
            for(int i=1;i<=f;i++) cout<<8;
            cout<<"\n";
            continue;
        }
        if(p==1){
            cout<<10;
            for(int i=1;i<f;i++) cout<<8;
            cout<<"\n";
            continue;
        }
        if(p==3){
            if(f==1){
                cout<<22<<"\n";
                continue;
            }
            cout<<200;
            for(int i=3;i<=f;i++) cout<<8;
            cout<<"\n";
            continue;
        }
        if(p==4){
            cout<<20;
            for(int i=2;i<=f;i++) cout<<8;
            cout<<"\n";
            continue;
        }
        if(p==6){
            cout<<6;
            for(int i=1;i<=f;i++) cout<<8;
            cout<<"\n";
            continue;
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
