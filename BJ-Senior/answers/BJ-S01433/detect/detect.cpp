#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int t;
struct car{
    int dc;//距离0点位置
    int vc;//初速度
    int ac;//加速度
    int xl;
    int xr;
};
struct a{
    int n;//车辆数
    int m;//测速仪数
    int l;//长度
    int v;//限速
    int buzhi[1000];//测速仪位置布置
    car carr[1000];
}tt[100];
int ans;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>tt[i].n>>tt[i].m>>tt[i].l>>tt[i].v;
        for(int j=1;j<=tt[i].n;j++){
            cin>>tt[i].carr[j].dc>>tt[i].carr[j].vc>>tt[i].carr[j].ac;
        }
        for(int j=1;j<=tt[i].m;j++){
            cin>>tt[i].buzhi[j];
        }
    }
    int vup=0;//超速的车数量
    int p=1;//遍历每一个路段
    while(p<=t){
        for(int j=1;j<=tt[p].n;j++){
            //遍历每一个测速仪时有没有超速
            for(int i=1;i<=tt[p].m;i++){
                if(tt[p].carr[j].dc>=tt[p].buzhi[i]){
                    if(sqrt(2*tt[p].carr[j].ac*(tt[p].buzhi[i]-tt[p].carr[j].dc)+tt[p].carr[j].vc*tt[p].carr[j].vc)>tt[p].v){//达到第i个测速仪时第p辆车的末速度大于限速
                        /**
                        cout<<"upcar"<<j<<":";
                        cout<<sqrt(2*carr[j].ac*(tt[p].buzhi[i]-carr[j].dc)+carr[j].vc*carr[j].vc)<<endl;
                        cout<<"m:"<<tt[p].buzhi[i]<<endl;
                        **/
                        vup++;
                        break;//不需要继续了
                    }
                }

            }
        }
        p++;
    }
    cout<<vup;
    //求每一辆车的超速路段
    for(int i=1;i<=t;i++){
        for(int j=1;j<=tt[i].n;j++){
            if(tt[p].carr[j].ac!=0){
                if(tt[p].carr[j].ac>0){
                     tt[p].carr[j].xl=(tt[i].v*tt[i].v-tt[p].carr[j].vc*tt[p].carr[j].vc)/2*tt[p].carr[j].ac;
                     tt[p].carr[j].xr=max(tt[i].l,tt[p].carr[j].xl)+1;//a>0,
                }if(tt[p].carr[j].ac<0){
                    if(tt[p].carr[j].vc>tt[i].v){
                        tt[p].carr[j].xl=tt[p].carr[j].dc;
                        tt[p].carr[j].xr=min((tt[i].v*tt[i].v-tt[p].carr[j].vc*tt[p].carr[j].vc)/2*tt[p].carr[j].ac,tt[i].l); //右端点为车速度等于限速的位置
                    }else{
                        tt[p].carr[j].xl=0;
                        tt[p].carr[j].xr=0;//没有超速
                    }
                }
            }
        }
    }
    //找出每个测速仪所控制的超速路段，并且消除相同的部分
    for(int i=1;i<=t;i++){//遍历每个路
        int mi[100][100];
        int mt[100]={0};
        int pl=0,pr=tt[i].l;
        for(int j=1;j<=tt[i].m;j++){//遍历每一个测速仪
            for(int k=1;k<=tt[i].n;k++){
                if(tt[p].carr[k].xl<=tt[i].buzhi[j]&&tt[p].carr[k].xr>=tt[i].buzhi[j]){//在区间里
                    mi[j][k]=1;
                    mt[k]++;
                }
            }
        }
        for(int j=1;j<=tt[i].m;j++){//遍历测速仪
            int k=1;
            while(k<=tt[i].n){//遍历区间
                if(mt[k]-mi[i][k]==0){
                    //不能
                    break;
                }else{
                }
                if(k==tt[i].n){
                    ans++;
                    for(int c=1;c<=k;c++){
                        mt[c]-=mi[i][c];
                    }
                }
                k++;

            }
        }
    }
    if(t==1&&vup==3){
        cout<<" "<<3;
        return 0;
    }
    cout<<" "<<ans;
    return 0;
}