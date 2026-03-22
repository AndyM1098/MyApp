#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Student {
    int id;
    string name;
    double score;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Student> students;
    students.reserve(max(0, n));

    for (int i = 0; i < n; ++i) {
        Student s;
        cin >> s.id >> s.name >> s.score;
        students.push_back(s);
    }

    int query;
    cin >> query;

    if (students.empty()) {
        cout << "Average: 0.00\n";
        cout << "Highest: N/A\n";
        cout << "Lowest: N/A\n";
        cout << "Passing: 0\n";
        cout << "Not found\n";
        return 0;
    }

    double sum = 0.0;
    int passing = 0;
    size_t hi = 0, lo = 0;

    for (size_t i = 0; i < students.size(); ++i) {
        sum += students[i].score;
        if (students[i].score >= 60.0) ++passing;
        if (students[i].score > students[hi].score) hi = i;
        if (students[i].score < students[lo].score) lo = i;
    }

    cout << fixed << setprecision(2);
    cout << "Average: " << sum / students.size() << "\n";
    cout << "Highest: " << students[hi].id << " " << students[hi].name << " " << students[hi].score << "\n";
    cout << "Lowest: " << students[lo].id << " " << students[lo].name << " " << students[lo].score << "\n";
    cout << "Passing: " << passing << "\n";

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.score > b.score;
    });

    cout << "Sorted:\n";
    for (const auto& s : students) {
        cout << s.id << " " << s.name << " " << s.score << "\n";
    }

    auto it = find_if(students.begin(), students.end(), [query](const Student& s) {
        return s.id == query;
    });

    if (it != students.end()) {
        cout << "Found: " << it->id << " " << it->name << " " << it->score << "\n";
    } else {
        cout << "Not found\n";
    }

    return 0;
}
