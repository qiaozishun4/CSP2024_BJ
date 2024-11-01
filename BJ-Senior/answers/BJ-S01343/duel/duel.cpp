#include <bits/stdc++.h>

using namespace std;

int arr[100005];
int num[100005];

struct Node
{
    int value , number;
    int can_kill;
    bool operator < (const Node &x) const
    {
        return x.value < value;
    }
};

struct ki
{
    int value , number;
    bool operator < (const ki &x) const
    {
        return x.value < value;
    }
};

priority_queue <Node> que;
priority_queue <ki> k;

int main ()
{
    freopen("duel.in" , "r" , stdin);
    freopen("duel.out" , "w" , stdout);

    int n;
    cin >> n;

    for(int i = 1;i<=n;i++)
    {
        int temp;
        cin >> temp;
        arr[temp] ++;
    }

    int cnt = 0;
    for(int i = 0;i<= 100005 ; i++)
    {
        que.push({cnt , arr[i] ,arr[i]});
        cnt ++;
    }

    int ans = 0;
    k.push({que.top().value , que.top().number});
    que.pop();
    while(que.size() >= 2)
    {
        if(k.empty())
        {
            k.push({que.top().value , que.top().number});
            que.pop();
        }
        Node killer = que.top();
        ki be_killed = k.top();
        que.pop();
        k.pop();
        int die = min(be_killed.number, killer.can_kill);
        be_killed.number -= die;
        killer.can_kill -= die;
        if(be_killed.number != 0)
        {
            k.push({be_killed.value , be_killed.number});
        }
        if(killer.can_kill != 0)
        {
            que.push({killer.value , killer.number , killer.can_kill});
        }
        else
        {
            k.push({killer.value , killer.number});
        }
        ans += die;
    }

    cout << (n - ans);
    return 0;
}

