#include<bits/stdc++.h>
using namespace std;
//#define int long long
//#define endl '\n'
#define ll long long
const int MAXN =2e5+5;
int a[MAXN];
bool cmp(int a,int b){
    return a<b;
}

int n;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    //freopen("data.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    //for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    int dlt=2;
    int p=1;
    int ans=0;
    while(1){
        while(a[dlt]<=a[p]&&dlt<=n){dlt++;ans++;}
        if(dlt>n){
            //cout<<"he"<<endl;
            break;
        }
        //cout<<"dlt: "<<a[p]<<" by "<<a[dlt]<<endl;
        p++;dlt++;//ans--;
        if(dlt>n){
            //cout<<"she"<<endl;//p--;
            break;
        }
    }
    //cout<<p<<' '<<dlt<<endl;
    cout<<n-p+1<<endl;
    return 0;
}
