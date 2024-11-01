#include<iostream>
#include<cmath>
using namespace std;
int a1[100005],c[100005],x[10],d[20][250005],rec[100005];
struct node{
    int num,id;
}a[100005];

int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a1[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    int cur=1;
    for(int i=1;i<=18;i++){
        if(cur>=n){
            cur=i-1;
            break;
        }
        cur*=2;
    }
    for(int i=1;i<=cur;i++){
        for(int j=1;j<=pow(2,cur-i);j++){
            char ch;
            cin>>ch;
            d[i][j]=(int)ch-'0';
        }
    }
    int t;
    cin>>t;
    while(t--){
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++){
            a[i].num=a1[i]^x[i%4];
            a[i].id=i;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                a[j].num=a1[j]^x[j%4];
                a[j].id=j;
            }
            for(int j=1;j<=log2(c[i]);j++){
                for(int k=1;k<=c[i]/pow(2,j);k++){
                    if(d[j][k]==0){
                        if(a[2*k-1].num<j) a[k]=a[2*k];
                        else a[k]=a[2*k-1];
                    }
                    else{
                        if(a[2*k].num<j) a[k]=a[2*k-1];
                        else a[k]=a[2*k];
                    }
                }
            }
            rec[i]=a[1].id;
        }
        int cnt=rec[1];
        for(int i=2;i<=m;i++){
            cnt=cnt^(i*rec[i]);
        }
        cout<<cnt<<'\n';
    }
    return 0;
}

//10pts finish time: 17:59
//luogu uid 453759
//BJ-S01147
//:(
//IcantAKCSPS
