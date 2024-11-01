#include<bits/stdc++.h>
//0-6,1-2,2-5,3-5,4-4,5-5,6-6,7-3,8-7,9-6
using namespace std;
int ans[10005]={-1,-1,1,-1,4,2,6,8,10,17,78};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        int k[10005]={},t=0;
        while(m>0){
            if(m>10&&m-7!=3){
                k[t++]=8;
                m-=7;
            }else{
                if(ans[m]/10==0)k[t++]=ans[m];
                else{
                    k[t++]=ans[m]/10;
                    k[t++]=ans[m]%10;
                }
            }
        }
        sort(k,k+t);
        for(int i=0;i<t;i++){
            cout<<k[i];
        }
        cout<<endl;
    }
    return 0;
}
