#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int CMAX = 6;
const int PMAX = 15;

int N;
bool poker[CMAX][PMAX];
int n_left = 52;

int color2i(char ch)
{
    int res = 0;
    if(ch == 'D') {
        res = 1;
    } else if(ch == 'C') {
        res = 2;
    } else if(ch == 'H') {
        res = 3;
    } else if(ch == 'S') {
        res = 4;
    }
    return res;
}

int point2i(char ch)
{
    if(ch == 'A') {
        return 1;
    } else if('2' <= ch && ch <= '9') {
        return ch - '0';
    } else if(ch == 'T') {
        return 10;
    } else if(ch == 'J') {
        return 11;
    } else if(ch == 'Q') {
        return 12;
    } else if(ch == 'K') {
        return 13;
    }
    return 0;
}

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 1;i <= N;i += 1) {
        char c, p;
        scanf(" %c %c", &c, &p);
        int ic = color2i(c), ip = point2i(p);
        if(!poker[ic][ip]) {
            n_left -= 1;
            poker[ic][ip] = true;
        }
    }
    printf("%d\n", n_left);
    exit(0);
}