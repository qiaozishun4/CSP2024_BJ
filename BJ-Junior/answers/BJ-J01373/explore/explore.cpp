#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m,k,x,y,d,sum=0;
        cin>>n>>m>>k;
        char s[m];
        cin>>x>>y>>d;
        cin>>s;
        for(int i=1;i<=k;i++){
            if(d==2){
                if(y<n&&s[x+1]){
                    y++;
                    sum++;
                }
            }
            if(d==0){
                if(y>1&&s[y-1]!='x'){
                    y--;
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
