#include<bits/stdc++.h>
using namespace std;
const int alp[10]={6,2,5,5,4,5,6,3,7,6};
int n,a[100000],len;
int getmin(int x,bool flag){
    if(x==2) return 1;
    if(x==3) return 7;
    if(x==4) return 4;
    if(x==5) return 2;
    if(x==6){
        if(flag==true) return 0;
        else return 6;
    }
    if(x==7) return 8;
}
void print(){
    for(int i=len;i>=1;i--) cout<<a[i];
    cout<<endl;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        len=n/7;
        for(int i=1;i<=n/7;i++) a[i]=8;
        if(n%7==1){
            a[len]=0;
            a[++len]=1;
            print();
            return 0;
        }else if(n%7!=0){
            a[++len]=getmin(n%7,false);
        }
        int last=len,sum=alp[a[len]];
        for(int i=len-1;i>=1;i--){
            while(a[last]==(last==len ? 1:0)) last--;
            sum+=alp[a[i]];
            int lth=last-i+1;
            //cout<<sum<<" "<<last<<" "<<lth<<endl;
            if(sum-2>(lth-1)*7){
                while(sum<=lth*7 && sum>=lth*2){
                    int tmp=(last==len?2:0);
                    if(sum-alp[tmp]>(lth-1)*7 || sum-alp[tmp]<(lth-1)*2) break;
                    //sum+=alp[a[last]];
                    if(last==len) a[last]=2;
                    else a[last]=0;
                    last--;
                    sum-=alp[tmp];
                    lth--;
                }
                //cout<<last<<" "<<sum<<endl;
            }else{
                sum+=alp[a[last]];
                a[last]=1;
                lth--;
                sum-=2;
            }
            int k=lth*7-sum;
            if(7-k==0) continue;
            if(7-k==1){
                a[last]=0;
                a[--last]=1;
            }else{
                a[last]=getmin(7-k,last==len?0:1);
            }
            //cout<<"----------------------"<<endl;
        }
        print();
    }

    return 0;
}
