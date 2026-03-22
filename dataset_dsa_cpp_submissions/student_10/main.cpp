#include <algorithm>
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
        int id;
        string name;
        double score;
        cin >> id >> name >> score;
        students.push_back({id, name, score});
    }

    int target;
    cin >> target;

    if (students.size() == 0) {
        cout << "Average: 0\n";
        cout << "Highest: N/A\n";
        cout << "Lowest: N/A\n";
        cout << "Passing: 0\n";
        cout << "Not found\n";
        return 0;
    }

    double sum = 0;
    int passCount = 0;
    Student hi = students[0];
    Student lo = students[0];

    for (auto& st : students) {
        sum += st.score;
        if (st.score >= 60.0) {
            passCount++;
        }
        if (st.score > hi.score) hi = st;
        if (st.score < lo.score) lo = st;
    }

    cout << "Average: " << (sum / students.size()) << "\n";
    cout << "Highest: " << hi.id << " " << hi.name << " " << hi.score << "\n";
    cout << "Lowest: " << lo.id << " " << lo.name << " " << lo.score << "\n";
    cout << "Passing: " << passCount << "\n";

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.score > b.score;
    });

    cout << "Sorted:\n";
    for (const auto& st : students) {
        cout << st.id << " " << st.name << " " << st.score << "\n";
    }

    bool found = false;
    for (const auto& st : students) {
        if (st.id == target) {
            cout << "Found: " << st.id << " " << st.name << " " << st.score << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Not found\n";
    }

    return 0;
}
