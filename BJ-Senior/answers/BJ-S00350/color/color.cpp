#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int xs=1;xs<=t;xs++){
        int n;
        cin>>n;
        int s[30]={},t[30]={},ans=0,num=0;
        for(int xs2=1;xs2<=n;xs2++){
            cin>>s[xs2];
        }
        int w=1;
        while(w){
            t[w]++;
            if(t[w]>2){
                t[w]=0;
                w--;
                continue;
            }
            if(w<n)w++;
            else{
                int num=0;
                for(int xs2=1;xs2<=n;xs2++){
                    int xs3=xs2;
                    while(xs3){
                        xs3--;
                        if(t[xs3]==t[xs2])break;
                    }
                    if(s[xs3]==s[xs2])num+=s[xs2];
                }
                ans=max(ans,num);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
