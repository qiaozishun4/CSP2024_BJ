#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    int len,ba;
    ll pre; //pre contains st
}a[100005];
int t,n,ST[10],u[10];
bool cmp(node x,node y)
{
    if(x.len != y.len)  return x.len < y.len;
    return x.pre < y.pre;
}
int main()
{
    //remember to freopen
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    ST[1] = 1;
    ST[2] = 2;
    ST[3] = 4;
    ST[4] = 6;
    ST[5] = 7;
    ST[6] = 8;
    u[0] = 6;
    u[1] = 2;
    u[2] = 5;
    u[4] = 4;
    u[6] = 6;
    u[7] = 3;
    u[8] = 7;
    while(t --)
    {
        cin >> n;
        if(n == 1)
        {
            cout << "-1\n";
            continue;
        }
        int id = 0;
        for(int i=1;i<=6;i++)
        {
            int st = ST[i];
            for(int ling=0;ling<=6;ling++)
            {
                for(int yi=0;yi<=1;yi++)
                {
                    for(int er=0;er<=5;er++)
                    {
                        for(int si=0;si<=2;si++)
                        {
                            for(int qi=0;qi<=1;qi++)
                            {
                                int lst = (n - u[st] - u[0] * ling - u[1] * yi - u[2] * er - u[4] * si - u[7] * qi);
                                if(lst < 0) continue;
                                if(lst % 7 == 0)
                                {
                                    ll cur = st;
                                    int Ling = ling,Yi = yi,Er = er,Si = si,Qi = qi,curl = 1;
                                    //curl = 1 because of st
                                    while(Ling --)
                                    {
                                        cur *= 10;
                                        curl ++;
                                    }
                                    while(Yi --)
                                    {
                                        cur = cur * 10 + 1;
                                        curl ++;
                                    }
                                    while(Er --)
                                    {
                                        cur = cur * 10 + 2;
                                        curl ++;
                                    }
                                    while(Si --)
                                    {
                                        cur = cur * 10 + 4;
                                        curl ++;
                                    }
                                    while(Qi --)
                                    {
                                        cur = cur * 10 + 7;
                                        curl ++;
                                    }
                                    while(curl < 16 && lst)
                                    {
                                        curl ++;
                                        cur = cur * 10 + 8;
                                        lst -= 7;
                                    }
                                    a[++id].pre = cur;
                                    a[id].len = curl + lst / 7;
                                    a[id].ba = lst / 7;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(!id)
        {
            cout << "-1\n";
            continue;
        }
        sort(a+1,a+id+1,cmp);
        cout << a[1].pre;
        int bacnt = a[1].ba;
        while(bacnt --)   cout << 8;
        cout << '\n';
    }
    return 0;
}
