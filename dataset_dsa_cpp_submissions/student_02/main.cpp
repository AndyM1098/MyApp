#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Student {
    int id;
    string name;
    double score;
};

void selectionSortDesc(vector<Student>& arr) {
    for (int i = 0; i < (int)arr.size(); i++) {
        int maxIdx = i;
        for (int j = i + 1; j < (int)arr.size(); j++) {
            if (arr[j].score > arr[maxIdx].score) {
                maxIdx = j;
            }
        }
        swap(arr[i], arr[maxIdx]);
    }
}

int main() {
    int n;
    cin >> n;

    vector<Student> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].id >> v[i].name >> v[i].score;
    }

    int searchId;
    cin >> searchId;

    if (n == 0) {
        cout << "Average: 0.00\nHighest: N/A\nLowest: N/A\nPassing: 0\nNot found\n";
        return 0;
    }

    double total = 0;
    int passing = 0;
    int hi = 0;
    int lo = 0;

    for (int i = 0; i < n; i++) {
        total += v[i].score;
        if (v[i].score >= 60) passing++;
        if (v[i].score > v[hi].score) hi = i;
        if (v[i].score < v[lo].score) lo = i;
    }

    cout << fixed << setprecision(2);
    cout << "Average: " << total / n << "\n";
    cout << "Highest: " << v[hi].id << " " << v[hi].name << " " << v[hi].score << "\n";
    cout << "Lowest: " << v[lo].id << " " << v[lo].name << " " << v[lo].score << "\n";
    cout << "Passing: " << passing << "\n";

    selectionSortDesc(v);

    cout << "Sorted:\n";
    for (int i = 0; i < n; i++) {
        cout << v[i].id << " " << v[i].name << " " << v[i].score << "\n";
    }

    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (v[i].id == searchId) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "Not found\n";
    } else {
        cout << "Found: " << v[pos].id << " " << v[pos].name << " " << v[pos].score << "\n";
    }

    return 0;
}
