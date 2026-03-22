#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Student {
    int id;
    string name;
    double score;
};

void printStats(const vector<Student>& students) {
    if (students.empty()) {
        cout << "Average: 0\n";
        cout << "Highest: N/A\n";
        cout << "Lowest: N/A\n";
        cout << "Passing: 0\n";
        return;
    }

    double sum = 0;
    int pass = 0;
    Student hi = students.front();
    Student lo = students.front();

    for (const Student& s : students) {
        sum += s.score;
        pass += (s.score >= 60);
        if (s.score > hi.score) hi = s;
        if (s.score < lo.score) lo = s;
    }

    cout << "Average: " << (sum / students.size()) << "\n";
    cout << "Highest: " << hi.id << " " << hi.name << " " << hi.score << "\n";
    cout << "Lowest: " << lo.id << " " << lo.name << " " << lo.score << "\n";
    cout << "Passing: " << pass << "\n";
}

int main() {
    int n;
    cin >> n;

    vector<Student> students;
    students.reserve(n);

    for (int i = 0; i < n; i++) {
        Student s;
        cin >> s.id >> s.name >> s.score;
        students.push_back(s);
    }

    int searchId;
    cin >> searchId;

    printStats(students);

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if (a.score == b.score) return a.id < b.id;
        return a.score > b.score;
    });

    cout << "Sorted:\n";
    for (const Student& s : students) {
        cout << s.id << " " << s.name << " " << s.score << "\n";
    }

    auto it = find_if(students.begin(), students.end(), [searchId](const Student& s) {
        return s.id == searchId;
    });

    if (it == students.end()) {
        cout << "Not found\n";
    } else {
        cout << "Found: " << it->id << " " << it->name << " " << it->score << "\n";
    }

    return 0;
}
