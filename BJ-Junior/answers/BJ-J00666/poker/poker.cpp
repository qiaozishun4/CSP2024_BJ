#include<bits/stdc++.h>
using namespace std;
int n;
int D[15] = {0},C[15] = {0},H[15] = {0},S[15] = {0};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        string a;
        cin >> a;
        //cout << a[0] << a[1] << endl;
        if(a[0] == 'D')
        {
            if(a[1] == 'T')
                D[10]++;
            else if(a[1] == 'J')
                D[11]++;
            else if(a[1] == 'Q')
                D[12]++;
            else if(a[1] == 'K')
                D[13]++;
            else if(a[1] == 'A')
                D[1]++;
            else
                D[a[1] -'0']++;
        }
        else if(a[0] == 'C')
        {
            if(a[1] == 'T')
                C[10]++;
            else if(a[1] == 'J')
                C[11]++;
            else if(a[1] == 'Q')
                C[12]++;
            else if(a[1] == 'K')
                C[13]++;
            else if(a[1] == 'A')
                C[1]++;
            else
                C[a[1] -'0']++;
        }
        else if(a[0] == 'H')
        {
            if(a[1] == 'T')
                H[10]++;
            else if(a[1] == 'J')
                H[11]++;
            else if(a[1] == 'Q')
                H[12]++;
            else if(a[1] == 'K')
                H[13]++;
            else if(a[1] == 'A')
                H[1]++;
            else
                H[a[1]-'0']++;
        }
        else if(a[0] == 'S')
        {
            if(a[1] == 'T')
                S[10]++;
            else if(a[1] == 'J')
                S[11]++;
            else if(a[1] == 'Q')
                S[12]++;
            else if(a[1] == 'K')
                S[13]++;
            else if(a[1] == 'A')
                S[1]++;
            else
                S[a[1]-'0']++;
        }
    }
    int cnt = 0;
    for(int i = 1;i <= 13;i++)
    {
        //cout << D[i] << C[i] << H[i] << S[i] << endl;
        if(D[i] == 0)
            cnt++;
        if(C[i] == 0)
            cnt++;
        if(H[i] == 0)
            cnt++;
        if(S[i] == 0)
            cnt++;
    }
    cout << cnt;
    return 0;
}