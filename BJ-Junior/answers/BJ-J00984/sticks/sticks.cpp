#include<bits/stdc++.h>

using namespace std;
long long T;
long long n;
const int N = 1e5 + 10;
const int M = 1e5;
long long nums[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int a[N];
int s[N];
int sn = 1e9;
bool ch;

void dfs(int w, int l)
{
    if(l == 1) return ;
    if(l == 0)
    {
        ch = true;
        if(sn > w)
        {
            sn = w;
            for(int i = 0; i < sn; i ++ )
            {
                s[i] = a[i];
            }
        }
        return ;
    }
    for(int i = 0; i <= 9; i ++ )
    {
        if(w == 0 && i == 0)
        {
            continue;
        }
        if(l - nums[i] >= 0)
        {
            a[w] = i;
            dfs(w + 1, l - nums[i]);
            a[w] = 0;
        }
    }
}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
	cin >> T;
	while(T -- )
    {
        memset(s, 10, sizeof s);
        memset(a, 0, sizeof a);
        sn = 1e9;
        ch = false;

        cin >> n;
        dfs(0, n);

        if(ch == false) puts("-1");
        else{
            for(int i = 0; i < sn; i ++ )
            {
                cout << s[i];
            }
            puts("");
        }
    }
	return 0;
}
