#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;


vector<char> d[100005];
vector<int> inputs;

const int table[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};


bool cmp(vector<char> a, vector<char> b)
{
//    int sza = a.size(), szb = b.size();
//    for(int i = a.size() - 1; i >= 0; --i)
//        if(a[i] != 0)
//        {
//            sza = i + 1;
//            break;
//        }
//    for(int i = b.size() - 1; i >= 0; --i)
//        if(b[i] != 0)
//        {
//            szb = i + 1;
//            break;
//        }
//    if(sza != szb)
//        return sza < szb;
//    for(int i = 0; i < sza; ++i)
//    {
//        if(a[sza - i - 1] != b[sza - i - 1])
//            return a[sza - i - 1] < b[sza - i - 1];
//    }
//    return false;
    int sza = a.size(), szb = b.size(), szm = min(sza, szb);
    if(szb == 0)
        return true;
    if(sza != szb)
        return sza < szb;
    for(int i = szm - 1; i >= 0; ++i)
    {
        if(a[i] != b[i])
        {
            return a[i] < b[i];
        }
    }
    return true;
}


inline void output(int n)
{
    if(d[n].size() == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        for(int i = d[n].size() - 1; i >= 0; --i)
            cout << (int)d[n][i];
        cout << endl;
    }
}
inline void output(vector<char> tmp)
{
    if(tmp.size() == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        for(int i = tmp.size() - 1; i >= 0; --i)
            cout << (int)tmp[i];
        cout << endl;
    }
}


int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    int T;
    cin >> T;

    d[2] = {1};
    d[3] = {7};
    d[4] = {4};
    d[5] = {2};
    d[6] = {0};
    d[7] = {8};

    int maxn = -1;
    for(int t = 0, n; t < T; ++t)
    {
        cin >> n;
        maxn = max(maxn, n);
        inputs.push_back(n);
    }

    for(int i = 8; i <= maxn; ++i)
    {
        for(int j = 0, k; j < 10; ++j)
        {
            k = table[j];
            if(d[i - k].size() != 0)
            {
                vector<char> tmp = d[i - k];
                tmp.push_back(j);
//                printf("wow(i=%d, j=%d, k=%d): ", i, j, k);
//                if(tmp.size() == 0)
//                {
//                    cout << -1 << endl;
//                }
//                else
//                {
//                    for(int i = tmp.size() - 1; i >= 0; --i)
//                        cout << (int)tmp[i];
//                    cout << endl;
//                }

                if(cmp(tmp, d[i]))
                {
//                    cout << "hahahaha" << endl;
                    d[i] = tmp;
                }
            }
        }
    }
//    for(int i = 1; i <= maxn; ++i)
//        cout << "t: ", output(i);

    for(int t = 0, n; t < T; ++t)
    {
        n = inputs[t];
        if(n <= 7)
        {
            switch(n)
            {
            case 1:
                cout << -1;
                break;
            case 2:
                cout << 1;
                break;
            case 3:
                cout << 7;
                break;
            case 4:
                cout << 4;
                break;
            case 5:
                cout << 2;
                break;
            case 6:
                cout << 6;
                break;
            case 7:
                cout << 8;
                break;
            }
            cout << endl;
        }
        else
        {
            vector<char> ans;
            for(int j = 1, k; j < 10; ++j)
            {
                k = table[j];
                if(d[n - k].size() != 0)
                {
                    vector<char> tmp = d[n - k];
                    tmp.push_back(j);
//                    printf("wow(i=%d, j=%d, k=%d): ", i, j, k);
//                    if(tmp.size() == 0)
//                    {
//                        cout << -1 << endl;
//                    }
//                    else
//                    {
//                        for(int i = tmp.size() - 1; i >= 0; --i)
//                            cout << (int)tmp[i];
//                        cout << endl;
//                    }

                    if(cmp(tmp, ans))
                    {
                        ans = tmp;
                    }
                }
            }
            output(ans);
        }
    }
}
