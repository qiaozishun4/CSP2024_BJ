#include<bits/stdc++.h>
using namespace std;
int n,m,L,V,t;
int h[10005][3],w[10005];
bool w1[3005][3005];
int temp[10005];
int main(){
    const int d = 0,v = 1,a = 2;
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    bool flag1=true,flag2 = true,flag3 = true;
    for(int i=0;i<t;i++){
        flag1=true,flag2 = true,flag3 = true;
        cin>>n>>m>>L>>V;
        for(int j=1;j<=n;j++){
            cin>>h[j][d]>>h[j][v]>>h[j][a];
            if(h[j][a]!=0){
                flag1 = false;
            }

        }
        for(int j=1;j<=m;j++){
            cin>>w[j];
        }
        if(flag1){
            for(int j=1;j<=n;j++){
                if(h[j][v]>V){
                    for(int c=1;c<=m;c++){
                        if(w[c]>h[j][d]){
                            w1[j][0]++;

                        }
                    }
                }
            }
            for(int ccc=1;ccc<=n;ccc++){
                if(w1[ccc][0]){
                    temp[i]++;
                }
            }
        }

    }
    for(int i=1;i<=n;i++){
        cout<<temp[i]<<endl;
    }
    return 0;
}
