#include <bits/stdc++.h>
using namespace std;
int n,t;
int a[15]={6,2,5,5,4,5,6,3,7,6};
bool x=true;
int pos;
int minn=1000000000;
int c[60],po[100];

int res(int k){
    int num;
    while(k!=0){
        num++;
        k/=10;
    }
    return num;
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    int g=t;
    while(t--){
        cin>>n;
        int pos=res(n);
        int n1=n;
        int i=0;
        while(n!=0){
            n/=10;
            po[i]=n;
        }
        for(int i=0;i<pos;i++){
            int bol=bol+a[po[i]];
            if(bol==n1){
                if(bol<minn){
                    minn=bol;
                }
            }
        }
        if(minn==1000000000){
            c[i]=-1;
            i++;
            continue;
        }
        c[i]=minn;
        i++;
    }
    for(int i=0;i<g;i++) cout<<c[i]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
