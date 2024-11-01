#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;


const int MAXN = 100005, MAXM = 100005, MAXL = 1000005;

int n, m, L, V;
int d[MAXN], v[MAXN], a[MAXN];
int p[MAXM];
bool alreadySet[MAXM];
bool overSpeed[MAXN];
pair<int, int> overSpeedRange[MAXN];


namespace Block
{
    int blockSize, tag[1005], data[MAXM];

    void flash();               // tag all clear, and affect datas
}


namespace ST
{
    bool data[MAXL][30];
    int rightHandCheckingPlaceIndex[MAXL];
    int leftHandCheckingPlaceIndex[MAXL];
    // for block
    struct DataForBlock
    {
        int value, id;

        DataForBlock operator+(const DataForBlock& other) const
        {
            return ((value > other.value) ? (DataForBlock){value, id} : (DataForBlock){other.value, other.id});
        }
    };
    DataForBlock dataForBlock[MAXM][30];//max


    void build()
    {
        int PIndex = 1;
        int lastIndex = -1;
        for(int i = 1; i <= L; ++i)
        {
            leftHandCheckingPlaceIndex[i] = lastIndex;
            rightHandCheckingPlaceIndex[i] =  PIndex;
            if(PIndex != 0x3f3f3f3f && i == p[PIndex])
            {
                data[i][0] = 1;
                leftHandCheckingPlaceIndex[i] = PIndex;
                lastIndex = PIndex;
                if(PIndex != 0x3f3f3f3f)
                    PIndex++;
                if(PIndex > m)
                    PIndex = 0x3f3f3f3f;
            }
            else
                data[i][0] = 0;
        }
        for(int i = 1; (1 << i) <= L; ++i)
        {
            for(int j = 1; j <= L - (1 << i) + 1; ++j)
            {
                data[j][i] = data[j][i - 1] || data[j + (1 << (i - 1))][i - 1];
            }
        }
    }

    void buildForBlock()
    {
        for(int i = 1; i <= m; ++i)
        {
            dataForBlock[i][0] = {Block::data[i], i};
        }
        for(int i = 1; (1 << i) <= m; ++i)
        {
            for(int j = 1; j <= m - (1 << i) + 1; ++j)
            {
                dataForBlock[j][i] = dataForBlock[j][i - 1] + dataForBlock[j + (1 << (i - 1))][i - 1];
            }
        }
    }

    bool query(int l, int r)
    {
        int t = log2(r - l + 1);
        return data[l][t] || data[r - t + 1][t];
    }

    DataForBlock queryForBlock(int l, int r)
    {
        int t = log2(r - l + 1);
        return dataForBlock[l][t] + dataForBlock[r - (1 << t) + 1][t];
    }
};


long double dist(int v0, int v1, int a)
{
    return ((long double)v1 * v1 - (long double)v0 * v0) / a / 2;
}


namespace Block
{
    int getBlock(int x)
    {
        return x / blockSize;
    }

    void init()
    {
        memset(tag, 0, sizeof tag);
        memset(data, 0, sizeof data);
        blockSize = sqrt(m);
    }

    void needed(int l, int r)
    {
//        printf("debug --- %d %d", l, r);
        l = ST::rightHandCheckingPlaceIndex[l], r = ST::leftHandCheckingPlaceIndex[r];
//        printf(" %d %d\n", l, r);
        for(int i = l; i <= (getBlock(l - 1) + 1) * blockSize - 1; ++i)
            data[i]++;
        for(int i = r; i >= getBlock(r + 1) * blockSize; --i)
            data[i]++;
        for(int i = getBlock(l - 1) + 1; i <= getBlock(r + 1) - 1; ++i)
        {
            tag[i]++;
        }
    }

    void flash()                // tag all clear, and affect datas
    {
        for(int i = 1; i <= m; ++i)
        {
            data[i] += tag[getBlock(i)];
        }
        memset(tag, 0, sizeof tag);
    }
}


int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        memset(overSpeed, 0, sizeof overSpeed);
        memset(alreadySet, 0, sizeof alreadySet);
        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; ++i)
        {
            cin >> d[i] >> v[i] >> a[i];
        }
        for(int i = 1; i <= m; ++i)
        {
            cin >> p[i];
        }

        ST::build();
        Block::init();

        int cnt = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(v[i] <= V && a[i] <= 0);         // must not over speed.
            else if(v[i] > V && a[i] >= 0)     // must over speed.
            {
                int l = d[i], r = L;
//                cout << "oh..." << r << "...";
//                if(r > L)
//                    cout << "nonono!";
//                cout << endl;
                overSpeed[i] = ST::query(l, r);
                if(overSpeed[i])
                    cnt++, overSpeedRange[i] = {l, r}, Block::needed(l, r);
            }
            else if(v[i] > V && a[i] < 0)      // over speed => not over speed
            {
                int l = d[i], r = min((long long)L, d[i] + (long long)(dist(v[i], V, a[i])));
//                cout << "oh..." << r << "...";
//                if(r > L)
//                    cout << "nonono!";
//                cout << endl;
//                cout << "hohoho " << l << " " << r << endl;
                overSpeed[i] = ST::query(l, r);
//                if(!overSpeed[i])
//                    ST::query(l, r);
                if(overSpeed[i])
                    cnt++, overSpeedRange[i] = {l, r}, Block::needed(l, r);
            }
            else if(v[i] <= V && a[i] > 0)      // not => over
            {
                int l = min((long long)L, d[i] + (long long)ceil(dist(v[i], V, a[i]))), r = L;
//                cout << "oh..." << r << "...";
//                if(r > L)
//                    cout << "nonono!";
//                cout << endl;
                overSpeed[i] = ST::query(l, r);
                if(overSpeed[i])
                    cnt++, overSpeedRange[i] = {l, r}, Block::needed(l, r);
            }
        }

//        cout << cnt << " ";
        cnt = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(overSpeed[i])
                cnt++;
        }
        cout << cnt << " ";

        Block::flash();
//        for(int i = 1; i <= m; ++i)
//            cout << Block::data[i] << " ";
//        cout << endl;
        ST::buildForBlock();
        for(int i = 1; i <= n; ++i)
        {
            if(!overSpeed[i])
            {
//                cout << "asfasdfasdfasdfasd " << overSpeedRange[i].first << " " << overSpeedRange[i].second << endl;
                continue;
            }
            int l = ST::rightHandCheckingPlaceIndex[overSpeedRange[i].first], r = ST::leftHandCheckingPlaceIndex[overSpeedRange[i].second];
//            printf("Debug --- %d %d => %d %d\n", overSpeedRange[i].first, overSpeedRange[i].second, l, r);
            if(r == -1)
                continue;
            if(l > r)
                continue;
            ST::DataForBlock willSet = ST::queryForBlock(l, r);
            alreadySet[willSet.id] = true;
        }

        int ans = 0;
        for(int i = 1; i <= m; ++i)
        {
//            cout << alreadySet[i] << "   ";
            if(alreadySet[i])
                ans++;
        }
//        cout << endl;
        cout << m - ans << endl;
    }


    return 0;
}
/*

1
10 10 150307 247
62978 968 -5
51700 883 -3
40408 564 -1
60366 870 -41
35943 797 -7
47476 595 -11
59020 672 -10
81024 964 -11
80637 695 -5
66114 874 -1
46720 48066 57373 60882 68842 72773 82820 116695 122159 150307

*/
