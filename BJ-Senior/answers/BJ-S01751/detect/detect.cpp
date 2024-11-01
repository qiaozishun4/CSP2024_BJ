#include<bits/stdc++.h>
using namespace std;
int b[1000001];
struct x{
    int d,y,z;
}a[100001];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    int n,m,l,v,cnt=0,ccnt=INT_MAX;
    while(t--){
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>a[i].d>>a[i].y>>a[i].z;
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
        for(int i=1;i<=n;i++){
            if(a[i].y>v){
                cnt++;
                int x=0;
                for(int j=1;b[j]<=m;j++){
                    if(b[j]<a[i].d) x++;
                }
                if(x<ccnt) ccnt=x;
            }

        }
        cout<<cnt<<" "<<ccnt<<endl;
    }
    return 0;
}
