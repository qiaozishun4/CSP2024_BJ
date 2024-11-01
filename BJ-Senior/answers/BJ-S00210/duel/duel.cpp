#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,cnt;
int r[N],t[N];
int main()
{
    //1,1,2,2,3
    //freopen("duel.in","r",stdin);
  //  freopen("duel.out","w",stdout);
    cin>>n;
    cnt=n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
    }
    sort(r+1,r+n+1);
    for(int i=1;i<=n;i++)
    {
        int j=i+1;
        //if(i==n&&t[i]==1)
          //  cnt++;
        if(r[j]>r[i]&&t[i]==0){
            t[j]=1;cnt--;
            //cout<<r[j]<<"vs"<<r[i]<<",cnt="<<cnt<<endl;
        }
        //else if(r[i]==r[j])
        //{
            //cout<<r[j]<<"vs"<<r[i]<<",cnt="<<cnt<<endl;
        //}
    }
    cout<<cnt-1;
    return 0;
}
