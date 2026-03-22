#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    string name;
    double score;
};

int main() {
    int n;
    cin >> n;

    vector<Student> students(n);
    for (int i = 0; i < n; i++) {
        cin >> students[i].id >> students[i].name >> students[i].score;
    }

    int searchId;
    cin >> searchId;

    if (n == 0) {
        cout << "Average: 0\nHighest: N/A\nLowest: N/A\nPassing: 0\nNot found\n";
        return 0;
    }

    double sum = 0;
    int pass = 0;
    int high = 0, low = 0;

    for (int i = 0; i < n; i++) {
        sum += students[i].score;
        if (students[i].score > 60) pass++; // BUG: should include 60
        if (students[i].score > students[high].score) high = i;
        if (students[i].score < students[low].score) low = i;
    }

    cout << "Average: " << (sum / n) << "\n";
    cout << "Highest: " << students[high].id << " " << students[high].name << " " << students[high].score << "\n";
    cout << "Lowest: " << students[low].id << " " << students[low].name << " " << students[low].score << "\n";
    cout << "Passing: " << pass << "\n";

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.score > b.score;
    });

    cout << "Sorted:\n";
    for (const auto& s : students) {
        cout << s.id << " " << s.name << " " << s.score << "\n";
    }

    bool found = false;
    for (const auto& s : students) {
        if (s.id == searchId) {
            cout << "Found: " << s.id << " " << s.name << " " << s.score << "\n";
            found = true;
            break;
        }
    }

    if (!found) cout << "Not found\n";

    return 0;
}
