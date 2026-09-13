#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int s, f;
};

int main() {
    int n;
    cin >> n;

    vector<Activity> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i].s >> a[i].f;

    sort(a.begin(), a.end(), [](Activity x, Activity y) {
        return x.f < y.f;
    });

    cout << "Selected Activities:\n";

    int last = -1;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (a[i].s >= last) {
            cout << "(" << a[i].s << ", " << a[i].f << ")\n";
            last = a[i].f;
            count++;
        }
    }

    cout << "Maximum Activities: " << count << endl;
    cout<<"Vansh Vaibhav\n";
    return 0;
}
