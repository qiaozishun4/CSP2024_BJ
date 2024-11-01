#include<bits/stdc++.h>
using namespace std;
struct sticks{
    int num,shu;
};
sticks a[10];
bool cmd(sticks a,sticks b){
    if(a.num!=b.num)return a.num<b.num;
    else return a.shu>b.shu;
}
int ans[10000],n,d,i=0,minn,jx,sl=0;
void f(int x,int y){
    if(y==1)return;
    if(y==0){
        ans[i]=x;
        i++;
        jx=1;
        return;
    }
    for(int j=0;j<=9;j++){
        if(a[j].shu<=y){
            x=x*10+a[j].num;
            f(x,y-a[j].shu);
            if(jx=1){
                x/=10;
                jx=0;
            }
        }
    }

}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    for(int i=0;i<=9;i++)a[i].num=i;
    a[0].shu=6;a[1].shu=2;a[2].shu=5;a[3].shu=5;a[4].shu=4;
    a[5].shu=5;a[6].shu=6;a[7].shu=3;a[8].shu=7;a[9].shu=6;
    sort(a,a+10,cmd);
    cin>>n;
    for(int k=0;k<n;k++){
        minn=1024*1024*2048-100;
        cin>>d;
        memset(ans,0,sizeof(ans));
        f(0,d);
        if(i==0)
            cout<<-1<<endl;
        else{
            for(int j=0;j<i;j++){
                int c=ans[j],b=0;
                while(c!=0){
                    b+=a[c%10].shu;
                    c/=10;
                }
                if(b==d){
                    minn=min(minn,ans[j]);
                }
            }
            cout<<minn<<endl;
        }
    }
    return 0;
}