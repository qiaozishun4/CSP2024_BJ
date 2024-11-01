#include<bits/stdc++.h>
using namespace std;

int r[100005];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,i,anss;
    cin>>n;
    anss=n;
    for(i=0;i<n;i++)
    {
        cin>>r[i];
    }
    sort(r,r+i);
    for(i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(r[j]<r[i]&&r[j]!=0)
            {
                r[j]=0;
                anss--;
                break;
            }
        }
    }
    cout<<anss;
    return 0;
}
