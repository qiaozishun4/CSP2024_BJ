#include<bits/stdc++.h>
using namespace std;
int t,n,ans[114514];
struct node{
    int g;
}a[20];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    a[0].g=6;
    a[1].g=2;
    a[2].g=5;
    a[3].g=5;
    a[4].g=4;
    a[5].g=5;
    a[6].g=6;
    a[7].g=3;
    a[8].g=7;
    a[9].g=6;
    while(t--){
        cin>>n;
        if(n==1){
            cout<<"-1"<<endl;
            continue;
        }
        memset(ans,0,sizeof(ans));
        int w=(n/7)+1;
        int k=w;
        while(w!=0){
            for(int i=0;i<=9;i++){
                if(n-a[i].g<=(w-1)*7&&w!=1){
                    if(w==k&&i==0) continue;
                    ans[w]=i;
                    n-=a[i].g;
                    break;
                }
                if(w==1){
                    if(a[i].g==n){
                        if(k==1&&i==0) continue;
                        ans[w]=i;
                        break;
                    }
                }
            }
            w--;
            //cout<<w<<" "<<k<<" "<<ans[w+1]<<endl;
        }
        for(int i=k;i>=1;i--){
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
