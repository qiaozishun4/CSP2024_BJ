#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int r[N];

queue<int> q;
int main()
{
    freopen("duel.in" , "r" ,stdin);
    freopen("duel.out", "w" ,stdout);

    long long n;
    cin >> n;
    long long ans=n;
    for(int i=1;i<=n;i++)
    {
        cin >> r[i];
    }
    sort(r+1,r+n+1);
    q.push(r[1]);
    if(n==1)
    {
        cout << "1" << endl;
        return 0;

    }
    if(n==2)
    {
        if(r[1]==r[2])
        {
            cout << "2";
            return 0;

        }else{
            cout << "1";
            return 0;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(r[i]>q.front())
        {
            q.pop();
            ans--;
            }else{
            q.push(r[i]);


        }
    }
    cout << ans;
    return 0;
}
