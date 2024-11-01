#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,ans;
int r[100001];
bool flag[100001]={0};

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;
    ans=n;
    for(int i=0;i<n;i++)
        cin>>r[i];

    sort(r,r+n);

    for(int i=0;i<n;i++)
        for(int j=1;j<n;j++){
            if(r[i]<r[j]&&flag[j]==0){
                ans--;
                flag[i]=flag[j]=1;
            }
        }

    cout<<ans<<endl;
    return 0;
}
