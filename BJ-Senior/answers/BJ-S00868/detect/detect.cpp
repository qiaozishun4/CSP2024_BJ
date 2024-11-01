#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct Car{
    int d, v, a;
}car[100001];

struct Qqj{
    int beginn, endn;
}qqj[100001];

int qqjlen;
int T, n, m, l, V, p[100001], ans, tmp, tmp2, tmp3;
int sa[100001];

int search1(int t) {
    int left = 1, right = m, mid;
    while (left < right) {
        mid = (left + right) >> 1;
        if (p[mid] >= t)
            right = mid;
        else
            left = mid + 1;
    }
    if (p[left] < t)
        return -1;
    return left;
}

int search2(int ind) {
    int left = search1(car[ind].d), right = m, mid;
    while (left < right) {
        mid = (left + right) >> 1;
        if (car[ind].v * car[ind].v + 2 * car[ind].a * (p[mid] - car[ind].d) > V * V)
            right = mid;
        else
            left = mid + 1;
    }
}

int search3(int ind) {
    int left = search1(car[ind].d), right = m, mid;
    while (left < right) {
        mid = (left + right + 1) >> 1;
        if (2 * car[ind].a * (p[mid] - car[ind].d) <= V * V - car[ind].v * car[ind].v)
            right = mid - 1;
        else
            left = mid;
    }
}

bool cmp(Qqj a, Qqj b) {
    if (a.endn == b.endn)
        return a.beginn < b.beginn;
    return a.endn < b.endn;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    cin >> T;
    while (T--) {
        cin >> n >> m >> l >> V;
        for (int i = 1;i <= n;i++)
            cin >> car[i].d >> car[i].v >> car[i].a;
        for (int i = 1;i <= m;i++) {
            cin >> p[i];
        }

        for (int i = 1;i <= m;i++)
            sa[i] = 0;

        ans = 0, qqjlen = 0;
        for (int i = 1;i <= n;i++) {
            if (car[i].a == 0) {
                if (car[i].v > V) {
                    tmp2 = search1(car[i].d);
                    if (tmp2 != -1) {
                        ans++;
                        if (sa[tmp2] == 0 || sa[tmp2] > (m - tmp2 + 1))
                            sa[tmp2] = m - tmp2 + 1;
                    }

                }
            }
            else if (car[i].a > 0) {
                if (p[m] >= car[i].d)
                    if (car[i].v * car[i].v + 2 * car[i].a * (p[m] - car[i].d) > V * V) {
                        ans++;
                        tmp2 = search2(i);
                        if (sa[tmp2] == 0 || sa[tmp2] > (m - tmp2 + 1))
                            sa[tmp2] = m - tmp2 + 1;
                    }

            }
            else {
                if (car[i].v > V) {
                    tmp = search1(car[i].d);
                    if (tmp != -1) {
                        tmp2 = V * V - car[i].v * car[i].v;
                        if (2 * car[i].a * (p[tmp] - car[i].d) > tmp2) {
                            ans++;
                            tmp3 = search3(i);
                            if (sa[tmp] == 0 || sa[tmp] > (tmp3 - tmp + 1))
                                sa[tmp] = tmp3 - tmp + 1;
                        }
                    }

                }


            }
        }
        cout << ans << ' ';

        for (int i = 1;i <= m;i++)
            if (sa[i] != 0) {
                qqj[++qqjlen].beginn = i;
                qqj[qqjlen].endn = i + sa[i] - 1;
            }

        if (qqjlen == 0) {
            cout << m << endl;
            continue;
        }

        sort(qqj + 1, qqj + qqjlen + 1, cmp);

        int anscnt = 1, nowind = 1, nextind;
        while (nowind <= qqjlen) {
            for (nextind = nowind;nextind + 1 <= qqjlen && qqj[nextind + 1].beginn <= qqj[nowind].endn;nextind++);
            if (nextind + 1 <= qqjlen)
                anscnt++;
            nowind = nextind + 1;
        }

        cout << m - anscnt << endl;
    }
}
