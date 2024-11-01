#include<bits/stdc++.h>
using namespace std;
int a[100005],c[100005];
struct node{
    int num,ak;
}b[100005];
bool cmp(node x,node y){
    return x.ak>y.ak
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,cnt;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x]++;
        b[x].num++;
    }
    bool bf=false;
    int sum=n-1;
    while(bf==false){
        int gon=0;
        for(int i=1;i<=sum;i++){
            if(b[i].num>b[i+1].num){
                a[i]-=a[i+1];
                b[i].num-=b[i+1].num;
                b[i+1].num=0;
            }
            else{
                a[i]=0;
                b[i+1].num-=b[i].num;
                b[i].num=0;
            }
        }
        for(int i=1;i<=n;i++){
            if(b[i].num<=0){
                gon++;
            }
            else{
                sum++;
            }
        }
        if(gon>=n-1){
            bf=true;
        }
        sort(b+1,b+1+sum,cmp);
        for(int i=1;i<=sum;i++){
            a[b[i].ak]=c[sum-i+1];
        }
        for(int i=1;i<=sum;i++){
            a[i]=c[i];
        }
    }
    for(int i=1;i<=n;i++){
        cnt+=a[i];
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
}