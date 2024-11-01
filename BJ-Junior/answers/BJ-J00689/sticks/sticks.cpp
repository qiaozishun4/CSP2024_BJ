#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define r register
#define p putchar
using namespace std;

typedef long long l;

inline l read() {
    r l x(0);
    r char ch;
    for (; !isdigit(ch); ch = getchar()) ;
    for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
    return x;
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    r l t(read());
    while (--t > -1) {
        r l n(read());
        if (n % 7 == 1) {
            if (n == 1) {p(45); p(49); p(10); continue;}
            p(49); p(48); n -= 8;
            while (n > 0) {p(56); n -= 7;}
        } else if (n % 7 == 2) {
            p(49); n -= 2;
            while (n > 0) {p(56); n -= 7;}
        } else if (n % 7 == 3) {
            if (n == 3) {p(55); p(10); continue;}
            if (n == 10) {p(50); p(50); p(10); continue;}
            p(50); p(48); p(48); n -= 17;
            while (n > 0) {p(56); n -= 7;}
        } else if (n % 7 == 4) {
            if (n == 4) {p(52); p(10); continue;}
            p(50); p(48); n -= 11;
            while (n > 0) {p(56); n -= 7;}
        } else if (n % 7 == 5) {
            p(50); n -= 5;
            while (n > 0) {p(56); n -= 7;}
        } else if (n % 7 == 6) {
            p(54); n -= 6;
            while (n > 0) {p(56); n -= 7;}
        } else {
            while (n > 0) {p(56); n -= 7;}
        }
        p(10);
    }
}
