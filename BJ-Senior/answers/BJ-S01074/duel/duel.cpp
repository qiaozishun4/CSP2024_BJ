#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int r[n];
    for(int i=0;i<n;i++)
    {
        cin>>r[i];
    }
    for(int j1=0;j1<n;j1++)
    {
        for(int i1=j1;i1<n;i1++)
        {
            if(r[i1]<r[j1])
            {
                int f1=r[i1];
                r[i1]=r[j1];
                r[j1]=f1;
            }
        }
    }
    queue <int> b;
    for(int i1=0;i1<n;i1++)
    {
        if(!b.empty()&&r[i1]>b.front())
            b.pop();
        b.push(r[i1]);
    }
    cout<<b.size();
    return 0;
}
