#include <bits/stdc++.h>

using namespace std;

/*
int partition(vector<int> &a, int l, int r) {
    swap(a[r], a[((rand() % (r - l + 1)) + l)]);

    int x = a[r], i = l;
    for (int j = l; j < r; j++) {
        if (a[j] <= x) {
            swap(a[i], a[j]);
            i++;
        }
    }

    swap(a[i], a[r]);

    return i;
}

int kth(vector<int> &a, int l, int r, int k) {
    if (l == r) {
        return a[l];
    }

    int pos = partition(a, l, r);

    if (pos == k) {
        return a[k];
    } else if (pos > k) {
        return kth(a, l, pos - 1, k);
    } else {
        return kth(a, pos + 1, r, k);
    }
}
*/

int kth(vector<int> &a, int k) {
    nth_element(a.begin(), a.begin() + (k - 1), a.end());

    return a[k - 1];
}
