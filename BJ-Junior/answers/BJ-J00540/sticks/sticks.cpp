#include<bits/stdc++.h>
using namespace std;
int t,n,a[10000],cnt;
bool cmp(int i,int j){
    return i<j;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<2){
            cout<<-1<<'\n';
            continue;
        }
        if(n==10) a[++cnt]=2,a[++cnt]=2,n-=10;
        if(n==9) a[++cnt]=1,a[++cnt]=8,n-=9;
        if(n==6) a[++cnt]=6,n-=6;
        while(n){
            if(n==11){
                a[++cnt]=2;
                a[++cnt]=0;
                break;
            }
            if(n==10){
                a[++cnt]=0;
                a[++cnt]=4;
                break;
            }
            if(n==9){
                a[++cnt]=0;
                a[++cnt]=7;
                break;
            }
            if(n==8){
                a[++cnt]=7;
                a[++cnt]=2;
                break;
            }
            if(n==7||n>11){
                a[++cnt]=8;
                n-=7;
            }
            if(n==6){
                a[++cnt]=0;
                break;
            }
            if(n==5){
                a[++cnt]=2;
                break;
            }
            if(n==4){
                a[++cnt]=4;
                break;
            }
            if(n==3){
                a[++cnt]=7;
                break;
            }
            if(n==2){
                a[++cnt]=1;
                break;
            }
        }
        sort(a+1,a+1+cnt,cmp);
        for(int i=1;i<=cnt;i++){
            if(a[i]!=0){
                swap(a[1],a[i]);
                break;
            }
        }
        for(int i=1;i<=cnt;i++) cout<<a[i];
        cout<<'\n';
        cnt=0;
    }
    return 0;
}
