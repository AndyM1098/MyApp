#include <iostream>
#include <vector>

using namespace std;

struct Student {
    int id;
    string name;
    double score;
};

double getAverage(const vector<Student>& a) {
    double sum = 0;
    for (auto x : a) sum += x.score;
    return a.empty() ? 0 : sum / a.size();
}

int main() {
    int n;
    cin >> n;

    vector<Student> a;
    for (int i = 0; i < n; i++) {
        Student s;
        cin >> s.id >> s.name >> s.score;
        a.push_back(s);
    }

    int q;
    cin >> q;

    if (a.empty()) {
        cout << "Average: 0\n";
        cout << "Highest: N/A\n";
        cout << "Lowest: N/A\n";
        cout << "Passing: 0\n";
        cout << "Not found\n";
        return 0;
    }

    int hi = 0, lo = 0, pass = 0;

    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i].score > a[hi].score) hi = i;
        if (a[i].score < a[lo].score) lo = i;
        if (a[i].score >= 60) pass++;
    }

    cout << "Average: " << getAverage(a) << "\n";
    cout << "Highest: " << a[hi].id << " " << a[hi].name << " " << a[hi].score << "\n";
    cout << "Lowest: " << a[lo].id << " " << a[lo].name << " " << a[lo].score << "\n";
    cout << "Passing: " << pass << "\n";

    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = i + 1; j < (int)a.size(); j++) {
            if (a[i].score < a[j].score) {
                swap(a[i], a[j]);
            }
        }
    }

    cout << "Sorted:\n";
    for (const auto& s : a) {
        cout << s.id << " " << s.name << " " << s.score << "\n";
    }

    bool found = false;
    for (const auto& s : a) {
        if (s.id == q) {
            found = true;
            cout << "Found: " << s.id << " " << s.name << " " << s.score << "\n";
            break;
        }
    }

    if (!found) cout << "Not found\n";

    return 0;
}
