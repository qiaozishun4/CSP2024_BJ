#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int c=0,ch=getchar();

    while(ch<'0'||ch>'9'){
        ch=getchar();
    }

    while(ch>='0'&&ch<='9'){
        c=c*10+ch-'0';
        ch=getchar();
    }

    return c;
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int T=read();

    while(T--){
        int n;
        cin>>n;

        if(n<=6){
            if(n<=1){
                puts("-1");
                continue;
            }else if(n==2){
                puts("1");
                continue;
            }else if(n==3){
                puts("7");
                continue;
            }else if(n==4){
                puts("4");
                continue;
            }else if(n==5){
                puts("2");
                continue;
            }else if(n==6){
                puts("6");
                continue;
            }
        }

        int s=n/7,ys=n%7;

        if(ys==0){
            for(int i=1;i<=s;i++){
                cout<<8;
            }
        }else if(ys==1){
            cout<<10;
            for(int i=1;i<=s-1;i++){
                cout<<8;
            }
        }else if(ys==2){
            cout<<18;
            for(int i=1;i<=s-1;i++){
                cout<<8;
            }
        }else if(ys==3){
            cout<<22;
            for(int i=1;i<=s-1;i++){
                cout<<8;
            }
        }else if(ys==4){
            cout<<20;
            for(int i=1;i<=s-1;i++){
                cout<<8;
            }
        }else if(ys==5){
            cout<<28;
            for(int i=1;i<=s-1;i++){
                cout<<8;
            }
        }else if(ys==6){
            cout<<68;
            for(int i=1;i<=s-1;i++){
                cout<<8;
            }
        }

        puts("");
    }

    return 0;
}
