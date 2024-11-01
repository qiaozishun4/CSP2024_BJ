#include <bits/stdc++.h>
using namespace std;

int n, remain;
struct Monster{
    int r, id;
    bool is_attack;
};
bool operator <(Monster x, Monster y)
{
    return x.r > y.r;
}
priority_queue<Monster> pq, t;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    remain = n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pq.push({x, i, false});
    }
    for(int i = 1; i <= n; i++)
    {
        Monster a = pq.top();
        if(!t.empty())
        {
            if(a.r < t.top().r)
            {
                pq.pop();
            }
            else
            {
                a = t.top();
                t.pop();
            }
        }
        else pq.pop();
        while(!pq.empty() && pq.top().is_attack == true)
        {
            t.push(pq.top());
            pq.pop();
        }
        if(pq.empty()) break;

        Monster b = pq.top();
        pq.pop();
        //cout << b.id << " " << b.r << "is trying to kill" << a.id << " " << a.r << endl;
        b.is_attack = true;
        if(a.r < b.r)
        {
            remain--;
            //cout << b.id << " " << b.r << "killed" << a.id << " " << a.r << endl;
            pq.push(b);
        }
        else
        {
            pq.push(a);
            pq.push(b);
        }
    }
    cout << remain << endl;
    return 0;
}
