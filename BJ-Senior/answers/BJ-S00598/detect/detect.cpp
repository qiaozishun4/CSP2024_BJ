#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
long long T,n,m,L,V;
long long a[101000];
long long b[100010];
long long c[100010];
long long s[100010];

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    int sum=0;
    while(T--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        for(int i=1;i<=m;i++){
            cin>>s[i];
        }
        for(int i=1;i<=n;i++){
            double l,r;
            if(c[i]!=0){
                l=a[i]+(V*V-b[i]*b[i])*1.0/(2*c[i]);
                r=L;
            }
            else if(c[i]==0&&b[i]>V){
                sum++;
                l=-1,r=-1;
            }else{
                l=-1,r=-1;
            }
            if(c[i]<0){
                r=l;
                l=a[i];
            }
            int flag=0;
            vector<int> p[100010];
            if(l<=L){
                for(int j=1;j<=m;j++){
                    if(s[j]>=l&&s[j]<=r){
                        if(!flag){
                           sum++;
                           flag=1;
                        }
                        p[j].push_back();
                    }
                }
            }
        }
        cout<<sum<<endl;
        sum=0;
    }

    return 0;
}
