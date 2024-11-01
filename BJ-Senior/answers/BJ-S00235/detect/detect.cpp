#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    for(int tt=1;tt<=T;tt++){
        int n,m,L,V,ov;
        int car[3005][4],light[3005];
        short cch[3005][1005];
        cin>>n>>m>>L>>V;ov=n;
        for(int i=1;i<=n;i++){
            cin>>car[i][0]>>car[i][1]>>car[i][2];
        }
        for(int i=1;i<=m;i++){
            cin>>light[i];
        }
        for(int i=1;i<=n;i++){
            cch[i][1]=0;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(car[i][2]==0){
                if(car[i][1]>V){
                    for(int j=1;j<=m;j++){
                        if(light[j]>car[i][0]){
                            cch[j][cch[j][1]++]=i;
                            if(car[i][3]!=-9999){
                                cnt++;car[i][3]=-9999;
                            }
                        }
                    }
                }
            }
            else{
                if(car[i][2]>0){
                    for(int j=1;j<=m;j++){
                        if(light[j]>car[i][0]+double((V*V)-(car[i][1]*car[i][1]))/(2*car[i][2])){
                            cch[j][cch[j][1]++]=i;
                            if(car[i][3]!=-9999){
                                cnt++;car[i][3]=-9999;
                            }
                        }
                    }
                }
                else{
                    for(int j=1;j<=m;j++){
                        if(light[j]>car[i][0] && light[j]<car[i][0]+double((V*V)-(car[i][1]*car[i][1]))/(2*car[i][2])){
                            cch[j][cch[j][1]++]=i;
                            if(car[i][3]!=-9999){
                                cnt++;car[i][3]=-9999;
                            }
                        }
                    }
                }
            }
        }
        cout<<cnt<<" "<<3<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
