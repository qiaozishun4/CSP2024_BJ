#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n;
int r[N];
bool flag[N];
bool die[N];//live or die
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    bool p=false;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        if(r[i]!=1&&r[i]!=2){
            p=true;
        }
    }
    if(p==true){
        for(int i=1;i<=n;i++){
            flag[i]=false;
            die[i]=true;
        }
        sort(r+1,r+n+1,cmp);
        for(int i=1;i<=n;i++){
            bool q=false;
            for(int j=i+1;j<=n;j++){
                if((r[j]>r[i])&&q==false&&die[j]==true&&flag[j]==false){
                    q=true;
                    flag[j]=true;
                    die[i]=false;
                    break;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(die[i]==true){
                ans++;
            }
        }
        cout<<ans;
    }
    else{
        int cnt1=0;
        int cnt2=0;
        for(int i=1;i<=n;i++){
            if(r[i]==1){
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        if(cnt2>=cnt1){
            cout<<cnt2;
        }
        else{
            cout<<cnt1;
        }
    }
    return 0;
}
