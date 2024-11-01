#include <bits/stdc++.h>
using namespace std;
int a[11];
int num[100005];
int cnt;
int n;

void fid(int x,int nm,bool iss){
    if(x==0){
        cnt++;
        num[cnt]=nm;
        return;
    }
    nm*=10;
    if(iss==true){
        fid(x-7,nm+8,iss);
    }
    if(x%7==0){
        iss==true;
        fid(x-7,nm+8,iss);
    }
    if(x==n){
        for(int i=1;i<=9;i++){
            fid(x-a[i],nm+i,iss);
        }
        return;
    }
    for(int i=0;i<=9;i++){
        fid(x-a[i],nm+i,iss);
    }
    return;
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    a[0]=6,a[1]=2,a[2]=5,a[3]=5,a[4]=4,a[5]=5,a[6]=6,a[7]=3,a[8]=7,a[9]=6;
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&n);
        if(n<=1){
            printf("-1\n");
            continue;
        }
        cnt=0;
        fid(n,0,false);
        int minn=9999999;
        for(int j=1;j<=cnt;j++){
            minn=min(minn,num[j]);
        }
        printf("%d",minn);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
