#include<bits/stdc++.h>
using namespace std;
int T,s,cnt,maxn,n;
int a[1000005];
bool colo[1000005];
int jisuan(bool k1,bool k2,bool k3,bool k4,bool k5,bool k6,bool k7,bool k8,bool k9,bool k10,bool k11,bool k12,bool k13,bool k14,bool k15,int nn){
    colo[1]=k1;
    colo[2]=k2;
    colo[3]=k3;
    colo[4]=k4;
    colo[5]=k5;
    colo[6]=k6;
    colo[7]=k7;
    colo[8]=k8;
    colo[9]=k9;
    colo[10]=k10;
    colo[11]=k11;
    colo[12]=k12;
    colo[13]=k13;
    colo[14]=k14;
    colo[15]=k15;
    cnt=0;
    for(int i=2;i<=nn;++i){
        int j=i-1;
        while((colo[j]!=colo[i])&&j>0){
            j--;
        }
        if(a[i]==a[j]){
            cnt+=a[i];
        }
    }
    return cnt;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;++i){
        maxn=0;
        cin>>n;
        for(int j=1;j<=n;++j){
            cin>>a[j];
        }
        for(int k1=0;k1<=1;++k1){
            for(int k2=0;k2<=1;++k2){
                for(int k3=0;k3<=1;++k3){
                    for(int k4=0;k4<=1;++k4){
                        for(int k5=0;k5<=1;++k5){
                            for(int k6=0;k6<=1;++k6){
                                for(int k7=0;k7<=1;++k7){
                                    for(int k8=0;k8<=1;++k8){
                                        for(int k9=0;k9<=1;++k9){
                                            for(int k10=0;k10<=1;++k10){
                                                for(int k11=0;k11<=1;++k11){
                                                    for(int k12=0;k12<=1;++k12){
                                                        for(int k13=0;k13<=1;++k13){
                                                            for(int k14=0;k14<=1;++k14){
                                                                for(int k15=0;k15<=1;++k15){
                                                                    maxn=max(maxn,jisuan(k1,k2,k3,k4,k5,k6,k7,k8,k9,k10,k11,k12,k13,k14,k15,n));
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<maxn<<endl;
    }
    return 0;
}
