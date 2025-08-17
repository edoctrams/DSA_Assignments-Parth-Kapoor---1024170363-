#include <iostream>
using namespace std;
int main() {
    int n, key;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> key;
    int l = 0, r = n - 1, mid, found = -1;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] == key) { found = mid; break; }
        else if (a[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    if (found != -1) cout << "Found at index " << found;
    else cout << "Not found";
}
