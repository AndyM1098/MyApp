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
    int n;
    cin >> n;

    vector<Student> students;
    for (int i = 0; i < n; i++) {
        Student s;
        cin >> s.id >> s.name >> s.score;
        students.push_back(s);
    }

    int searchId;
    cin >> searchId;

    if (students.empty()) {
        cout << "Average: 0.00\n";
        cout << "Highest: N/A\n";
        cout << "Lowest: N/A\n";
        cout << "Passing: 0\n";
        cout << "Not found\n";
        return 0;
    }

    double sum = 0;
    int passCount = 0;
    Student highest = students[0];
    Student lowest = students[0];

    for (const auto& s : students) {
        sum += s.score;
        if (s.score >= 60.0) passCount++;
        if (s.score > highest.score) highest = s;
        if (s.score < lowest.score) lowest = s;
    }

    cout << fixed << setprecision(2);
    cout << "Average: " << (sum / students.size()) << "\n";
    cout << "Highest: " << highest.id << " " << highest.name << " " << highest.score << "\n";
    cout << "Lowest: " << lowest.id << " " << lowest.name << " " << lowest.score << "\n";
    cout << "Passing: " << passCount << "\n";

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
