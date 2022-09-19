#include <bits/stdc++.h>

using namespace std;

string s;
string hg[] = {"aespa",    "baekjoon", "cau",  "debug",  "edge",   "firefox",
               "golang",   "haegang",  "iu",   "java",   "kotlin", "lol",
               "mips",     "null",     "os",   "python", "query",  "roka",
               "solvedac", "tod",      "unix", "virus",  "whale",  "xcode",
               "yahoo",    "zebra"};

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string ret;

    cin >> s;
    for (int i = 0; i < s.length();) {
        int target = s[i] - 'a';

        if (target < 0 || 26 <= target) {
            target = -1;
        } else {
            if (s.length() - i < hg[target].length()) {
                target = -1;
            } else {
                for (int j = 0; j < hg[target].length(); j++) {
                    if (s[i + j] != hg[target][j]) {
                        target = -1;
                        break;
                    }
                }
            }
        }

        if (target == -1) {
            cout << "ERROR!";
            return 0;
        }

        ret += (target + 'a');
        i += hg[target].length();
    }

    cout << "It's HG!\n" << ret;

    return 0;
}
