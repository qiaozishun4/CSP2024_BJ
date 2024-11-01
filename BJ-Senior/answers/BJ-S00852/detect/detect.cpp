#include<iostream>
#include<cstdio>
using namespace std;


int s[100010],p[100010];

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    int t;
    cin>>t;
    while(t--){
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            int d,v,a;
            cin>>d>>v>>a;
            s[d]=v;
        }
        
        int cnt=0,cnt2=0;
        for(int i=1;i<=m;i++){
            int p;
            cin>>p;
            
            if(s[p]>0){
                cnt++;
                if(s[p]>v) cnt2++;
            }
        }

        cout<<cnt2<<" "<<m-cnt<<endl;
    }
    return 0;
}