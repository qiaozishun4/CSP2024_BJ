#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int s(int x,int y,int s,int a){
    if(a==0) return s;
    else{
        return sqrt(s*s+2*a*(y-x));
    }
}
int c[N][5],va[100005];
int t;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        int n,m,v,l,cnt=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>c[i][1]>>c[i][2]>>c[i][3];
        }
        for(int k=1;k<=m;k++) cin>>va[k];
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(c[j][0]==0&&s(c[j][1],va[i],c[j][2],c[j][3])>v){
                    cout<<j<<" "<<i<<endl;
                    cnt++;
                    c[j][0]=1;
                }
            }
        }
        cout<<cnt<<" "<<m-1<<endl;
    }

    return 0;
}