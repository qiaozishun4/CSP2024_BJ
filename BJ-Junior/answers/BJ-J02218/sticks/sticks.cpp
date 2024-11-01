#include<bits/stdc++.h>
#define Maxn 100004
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int ans[Maxn];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int n,i=0;
        cin>>n;
        for(int j=0;j<Maxn;j++) ans[j]=0;
        if(n<2){
            cout<<"-1"<<endl;
            continue;
        }
        while(7*i<n) i++;
        int ch=7*i-n;
        if(i==1){
            for(int j=1;j<10;j++){
                if(n==num[j]){
                    cout<<j<<endl;
                    break;
                }
            }
            continue;
        }
        for(int j=0;j<i;j++){
            for(int p=0;p<10;p++){
                if(j==0&&p==0) continue;
                if(ch>=7-num[p]){
                    ans[j]=p;
                    ch=ch-7+num[p];
                    break;
                }
            }
        }
        for(int j=0;j<i;j++) cout<<ans[j];
        cout<<endl;
    }
    return 0;
}
