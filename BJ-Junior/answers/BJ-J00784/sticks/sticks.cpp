#include<bits/stdc++.h>
using namespace std;
int c[12]={0,6,2,5,5,4,5,6,3,7,6},n,a[10010];
struct st{
    int s,num; //s是棍数三代表数
}b[30];
bool cmp(st a,st b) {
    if(a.s>b.s) return a.s>b.s;
    else if(a.s==b.s) return a.num<b.num;
}
int main() {
    for(int i=1;i<=10;i++) {
        b[i].s=c[i]; b[i].num=i-1;
    }
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    sort(b+1,b+11,cmp);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(a[i]<=1){
            cout<<-1<<endl;
            continue;
        }
        int t=0,j=1;
        while(j<=10||a[i]>0) {
            if(a[i]>=b[j].s &&a[i]-b[j].s>=0){
                if(b[i].num==0&&t==0) {
                    continue;
                }
                a[i]-=b[j].s;
                t*=10; t+=b[j].num;
                //cout <<t<<';';
            }else if(a[i]==0) {
                break;
            }else if(a[i]<b[j].s||a[i]-b[j].s<=0) {
                j++;
            }
        }
        cout <<t<<endl;
    }
    return 0;
}