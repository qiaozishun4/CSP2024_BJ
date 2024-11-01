#include<bits/stdc++.h>
using namespace std;
struct number{
    int num;
    int stick;
};
const int N=13;
number c[N];
int main(){
    int a[10]={6,5,2,5,4,5,6,7,6,3};
    int b[10]={0,2,1,3,4,5,6,8,9,7};
    for(int i=0;i<=9;i++){
        c[i].num=b[i];
        c[i].stick=a[i];
    }
    freopen("explore.in","r",stdin);
    freopen("explore.out","w+",stdout);
    int t,xinhao=0,shu;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,pren,ii=0;
        cin>>n;
        pren=n;
        while(n<=0){
            if(n%7<=1&ii==0&&xinhao==0){
                cout<<"-1"<<endl;
                break;
            }else if(n%7>1&&xinhao==0){
                if(ii=0){
                    for(int j=1;j<10;j++){
                        if (n-c[j].stick>=0){
                                shu=c[j].num;
                            cout<<c[j].num;
                            n-=c[j].stick;
                            if(n%7>1){
                                pren=n;
                            }
                            break;
                        }else{
                            continue;
                        }
                    }

                }else{
                    for(int j=0;j<10;j++){
                        if (n-c[j].stick>=0){
                            cout<<c[j].num;
                            n-=c[j].stick;
                            break;
                        }else{
                            continue;
                        }
                    }
                }
            }else if(n%7==1&&ii>0&&xinhao==0){
                n=pren;
                xinhao=1;
            }else if(n%7==1&&ii>0&&xinhao==1){
                for(int shu=1,j=0;j<10;j++){
                        if (n-c[j].stick>=0){
                                shu=c[j].num;
                            cout<<c[j].num;
                            n-=c[j].stick;
                            if(n%7>1){
                                pren=n;
                            }
                            break;
                        }else{
                            continue;
                        }
                    }
            }
        }
        ii++;
    }
    fclose(stdout);
    fclose(stdin);
    return 0;
}
