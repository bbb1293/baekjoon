#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300000;
char word[26], reversed_word[26], text[MAXN + 1];
int word_len, text_len;
int prefix[25], suffix[25];

struct State {
    char data;
    int cnt;
};

void set_prefix(char s[26], int pi[25]) {
    for (int i = 1, j = 0; i < word_len; i++) {
        while (j && (s[i] != s[j])) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
}

void set_pi() {
    for (int i = 0; i < word_len; i++) {
        reversed_word[i] = word[word_len - 1 - i];
    }
    reversed_word[word_len] = 0;

    set_prefix(word, prefix);
    set_prefix(reversed_word, suffix);
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%s", word);
    scanf("%s", text);

    word_len = strlen(word);
    text_len = strlen(text);

    stack<State> left_s, right_s;

    set_pi();
    bool left_turn = true;
    int left = 0, right = text_len - 1;
    while (left <= right) {
        if (left_turn) {
            int cnt = (left_s.empty() ? 0 : left_s.top().cnt);

            while (cnt && (text[left] != word[cnt])) {
                cnt = prefix[cnt - 1];
            }
            if (text[left] == word[cnt]) {
                cnt++;
            }

            if (cnt == word_len) {
                while (--cnt) {
                    left_s.pop();
                }
                left_turn = false;
            } else {
                left_s.push({text[left], cnt});
            }
            left++;
        } else {
            int cnt = (right_s.empty() ? 0 : right_s.top().cnt);

            while (cnt && (text[right] != reversed_word[cnt])) {
                cnt = suffix[cnt - 1];
            }
            if (text[right] == reversed_word[cnt]) {
                cnt++;
            }

            if (cnt == word_len) {
                while (--cnt) {
                    right_s.pop();
                }
                left_turn = true;
            } else {
                right_s.push({text[right], cnt});
            }
            right--;
        }
    }

    while (!left_s.empty() && !right_s.empty()) {
        if (left_turn) {
            int cnt = (left_s.empty() ? 0 : left_s.top().cnt);
            char cur_data = right_s.top().data;

            while (cnt && (cur_data != word[cnt])) {
                cnt = prefix[cnt - 1];
            }
            if (cur_data == word[cnt]) {
                cnt++;
            }

            if (cnt == word_len) {
                while (--cnt) {
                    left_s.pop();
                }
                left_turn = false;
            } else {
                left_s.push({cur_data, cnt});
            }
            right_s.pop();
        } else {
            int cnt = (right_s.empty() ? 0 : right_s.top().cnt);
            char cur_data = left_s.top().data;

            while (cnt && (cur_data != reversed_word[cnt])) {
                cnt = suffix[cnt - 1];
            }
            if (cur_data == reversed_word[cnt]) {
                cnt++;
            }

            if (cnt == word_len) {
                while (--cnt) {
                    right_s.pop();
                }
                left_turn = true;
            } else {
                right_s.push({cur_data, cnt});
            }
            left_s.pop();
        }
    }

    if (!left_s.empty()) {
        text_len = left_s.size();
        for (int i = text_len - 1; i >= 0; i--) {
            text[i] = left_s.top().data;
            left_s.pop();
        }
    } else if (!right_s.empty()) {
        text_len = right_s.size();
        for (int i = 0; i < text_len; i++) {
            text[i] = right_s.top().data;
            right_s.pop();
        }
    } else {
        text_len = 0;
    }
    text[text_len] = 0;

    printf("%s", text);

    return 0;
}