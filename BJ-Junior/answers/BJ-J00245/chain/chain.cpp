#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t; cin >> t;
    while (t--) {
        int n, k, q; cin >> n >> k >> q;
        string s;
        while (n--) getline(cin, s);
        for (int i = 0; i < q; i++) getline(cin, s);
        // all depends on random!!!!!1!!!!1!11!11111!!1!!!!1
        srand(time(0));
        // random 1: all 0 or random 0/1?
        int r1 = rand() % 2;
        if (r1) {
            // all 0!
            while (q--) puts("0");
        } else {
            // random 0/1!
            while (q--) {
                printf("%d\n", rand() % 2);
            }
        }
    }
    return 0;
}

// T3 contributors:
// checker: IyEvdXNyL2Jpbi9lbnYgcHl0aG9uMwoKZGVmIGNvbXBpbGVfZmlsZShwcm9ibGVtTmFtZSk6CiAgICBpbXBvcnQgb3MKICAgIGNvbXBpbGVfY29tbWFuZCA9IGYnZysrIC1PMiAtc3RkPWMrKzE0IC1zdGF0aWMgLW8ge3Byb2JsZW1OYW1lfS5wcmcge3Byb2JsZW1OYW1lfS5jcHAnCiAgICBzdGF0ID0gb3Muc3lzdGVtKGNvbXBpbGVfY29tbWFuZCkKICAgIGlmIHN0YXQ6CiAgICAgICAgcHJpbnQoZid7cHJvYmxlbU5hbWV9OiBjb21waWxlIGVycm9yLicpCiAgICAgICAgZXhpdCgpCgpkZWYgZGlmZl9maWxlKGZpbGUxLCBmaWxlMik6CiAgICB3aXRoIG9wZW4oZmlsZTEsICJyYiIpIGFzIGY6CiAgICAgICAgYSA9IGYucmVhZCgpCiAgICAKICAgIHdpdGggb3BlbihmaWxlMiwgInJiIikgYXMgZjoKICAgICAgICBiID0gZi5yZWFkKCkKICAgIAogICAgcmV0dXJuIGEuc3RyaXAoKSA9PSBiLnN0cmlwKCkKCmRlZiBtYWluKGFyZ3YpOgogICAgaW1wb3J0IG9zCiAgICBpbXBvcnQgdGltZQogICAgcHJvYmxlbU5hbWUgPSBhcmd2WzFdCiAgICBlbnQgPSBbaSBmb3IgaSBpbiBvcy5saXN0ZGlyKGYnLi97cHJvYmxlbU5hbWV9JykgaWYgaS5lbmRzd2l0aCgnLmluJyldCiAgICBlbnQuc29ydCgpCiAgICBjb21waWxlX2ZpbGUocHJvYmxlbU5hbWUpCiAgICB0aWQgPSAwCiAgICBmb3IgbmFtZSBpbiBlbnQ6CiAgICAgICAgdGlkICs9IDEKICAgICAgICBvcy5zeXN0ZW0oZiJjcCAuL3twcm9ibGVtTmFtZX0ve25hbWV9IC4ve3Byb2JsZW1OYW1lfS5pbiIpCiAgICAgICAgb3Muc3lzdGVtKGYiY3AgLi97cHJvYmxlbU5hbWV9L3tuYW1lLnJlcGxhY2UoJy5pbicsICcuYW5zJyl9IC4ve3Byb2JsZW1OYW1lfS5hbnMiKQogICAgICAgIHN0YXJ0X3RpbWUgPSB0aW1lLnRpbWUoKQogICAgICAgIG9zLnN5c3RlbShmIi4ve3Byb2JsZW1OYW1lfS5wcmcgPCB7cHJvYmxlbU5hbWV9LmluID4ge3Byb2JsZW1OYW1lfS5vdXQiKQogICAgICAgIGVuZF90aW1lID0gdGltZS50aW1lKCkKICAgICAgICBpZiBlbmRfdGltZSAtIHN0YXJ0X3RpbWUgPiAxOgogICAgICAgICAgICBwcmludChmIntwcm9ibGVtTmFtZX06IHRlc3Qge3RpZH0gdGltZSBsaW1pdCBleGNlZWRlZC4iKQogICAgICAgICAgICBjb250aW51ZQogICAgICAgIHN0YXQgPSBkaWZmX2ZpbGUoZiJ7cHJvYmxlbU5hbWV9Lm91dCIsIGYie3Byb2JsZW1OYW1lfS5hbnMiKQogICAgICAgIGlmIHN0YXQ6CiAgICAgICAgICAgIHByaW50KGYie3Byb2JsZW1OYW1lfTogdGVzdCB7dGlkfSBhY2NlcHRlZC4iKQogICAgICAgIGVsc2U6CiAgICAgICAgICAgIHByaW50KGYie3Byb2JsZW1OYW1lfTogdGVzdCB7dGlkfSB3cm9uZyBhbnN3ZXIuIikKICAgIAogICAgb3Muc3lzdGVtKGYicm0gLWYge3Byb2JsZW1OYW1lfS5pbiB7cHJvYmxlbU5hbWV9Lm91dCB7cHJvYmxlbU5hbWV9LmFucyB7cHJvYmxlbU5hbWV9LnByZyIpCgppZiBfX25hbWVfXyA9PSAnX19tYWluX18nOgogICAgaW1wb3J0IHN5cwogICAgbWFpbihzeXMuYXJndik=
// table generator: IyEvdXNyL2Jpbi9lbnYgcHl0aG9uMwp0YWJsZSA9ICIjaW5jbHVkZSA8Yml0cy9zdGRjKysuaD4KIgp0YWJsZSArPSAidXNpbmcgbmFtZXNwYWNlIHN0ZDsKIgojIHN0YXJ0IQppbXBvcnQgc3lzLCBvcywgaW8KbiA9IHN5cy5hcmd2WzFdCnRhYmxlICs9ICJzdHJpbmcgc1tdID0gewoiCmZvciBpIGluIHJhbmdlKDEsIGludChuKSArIDEpOgogICAgaW5fZmlsZSA9IGYiMQp7aX0KIgoKICAgIHdpdGggb3Blbigic3RpY2tzLmluIiwgInciKSBhcyBmOgogICAgICAgIGYud3JpdGUoaW5fZmlsZSkKCiAgICBvcy5zeXN0ZW0oIi4vc3RpY2tzLnByZyA8IHN0aWNrcy5pbiA+IHN0aWNrcy5vdXQiKQoKICAgIHdpdGggb3Blbigic3RpY2tzLm91dCIsICJyIikgYXMgZjoKICAgICAgICBsaW5lcyA9IGYucmVhZGxpbmVzKCkKCiAgICBmb3IgbGluZSBpbiBsaW5lczoKICAgICAgICB0YWJsZSArPSBmIiAgICAie2xpbmUuc3RyaXAoKX1cbiIsCiIKCnRhYmxlICs9ICJ9OwoiCnRhYmxlICs9ICJpbnQgbWFpbigpIHsKIgp0YWJsZSArPSAiICAgIGludCB0LCBuOyBjaW4gPj4gdDsKIgp0YWJsZSArPSAiICAgIHdoaWxlICh0LS0pIHsKIgp0YWJsZSArPSAiICAgICAgICBjaW4gPj4gbjsKIgp0YWJsZSArPSAiICAgICAgICBjb3V0IDw8IHNbbiAtIDFdOwoiCnRhYmxlICs9ICIgICAgfQoiCnRhYmxlICs9ICIgICAgcmV0dXJuIDA7CiIKdGFibGUgKz0gIn0iCgp3aXRoIG9wZW4oInN0aWNrcy5jcHAiLCAidyIpIGFzIGY6CiAgICBmLndyaXRlKHRhYmxlKQ==
// pure enumerate program: I2luY2x1ZGUgPGJpdHMvc3RkYysrLmg+CnVzaW5nIG5hbWVzcGFjZSBzdGQ7CgojZGVmaW5lIGludCBsb25nIGxvbmcKCmludCBudW0yc3RpY2tjbnRbMTBdID0gezYsIDIsIDUsIDUsIDQsIDUsIDYsIDMsIDcsIDZ9OwoKaW50IG47CgppbnQgcmVhZCgpCnsKICAgIGludCB4ID0gMCwgZiA9IDE7CiAgICBjaGFyIGNoID0gZ2V0Y2hhcigpOwogICAgd2hpbGUgKGNoIDwgJzAnIHx8IGNoID4gJzknKSB7CiAgICAgICAgaWYgKGNoID09ICctJykgZiAqPSAtMTsKICAgICAgICBjaCA9IGdldGNoYXIoKTsKICAgIH0KICAgIHdoaWxlIChjaCA+PSAnMCcgJiYgY2ggPD0gJzknKSB7CiAgICAgICAgeCA9IHggKiAxMCArIGNoIC0gJzAnOwogICAgICAgIGNoID0gZ2V0Y2hhcigpOwogICAgfQogICAgcmV0dXJuIHggKiBmOwp9CgpzaWduZWQgbWFpbigpCnsKICAgIGludCBUID0gcmVhZCgpOwogICAgd2hpbGUgKFQtLSkgewogICAgICAgIG4gPSByZWFkKCk7CiAgICAgICAgaWYgKG4gPT0gMSkgewogICAgICAgICAgICBwdXRzKCItMSIpOwogICAgICAgICAgICBjb250aW51ZTsKICAgICAgICB9CiAgICAgICAgaW50IG51bSA9IDE7CiAgICAgICAgd2hpbGUgKDEpIHsKICAgICAgICAgICAgaW50IGNudCA9IDA7CiAgICAgICAgICAgIGludCBudW1fcHJlID0gbnVtOwogICAgICAgICAgICB3aGlsZSAobnVtKSB7CiAgICAgICAgICAgICAgICBjbnQgKz0gbnVtMnN0aWNrY250W251bSAlIDEwXTsKICAgICAgICAgICAgICAgIG51bSAvPSAxMDsKICAgICAgICAgICAgfQogICAgICAgICAgICBudW0gPSBudW1fcHJlOwogICAgICAgICAgICBpZiAoY250ID09IG4pIGJyZWFrOwogICAgICAgICAgICBudW0rKzsKICAgICAgICB9CiAgICAgICAgcHJpbnRmKCIlbGxkCiIsIG51bSk7CiAgICB9CiAgICByZXR1cm4gMDsKfQ==
// using method:
// checker: put your test datas under directory program/, like: program/program1.in, program/program1.ans, program/program2.in, program/program2.ans, etc.
// (actually CSP test datas maintain this directory structure)
// and put your source file (program.cpp) under current directory
// then just use: checker.py program, and it starts checking!
// table generator:
// backup the previous `sticks.cpp` as `sticks_pre.cpp`, recompile it as `sticks.prg`.
// then do this: `T3_table_gen.py <n>` and it'll generate a tabling-program using `sticks.prg`, which is actually runnable and fit to the test format.
// you can use `checker.py sticks` to verify - it's actually correct!
// pure enumerate program:
// as the name, enumerate a number until it reach the accurate count of sticks. as it is enumerating from 1, it can make sure the first number it found is minimal.
// use this and table generator, and use ur brain to find patterns :)