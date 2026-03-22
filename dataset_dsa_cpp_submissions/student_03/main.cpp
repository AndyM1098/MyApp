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

    vector<Student> data;
    while (n--) {
        Student s;
        cin >> s.id >> s.name >> s.score;
        data.push_back(s);
    }

    int targetId;
    cin >> targetId;

    if (data.size() == 0) {
        cout << "Average: 0\n";
        cout << "Highest: N/A\n";
        cout << "Lowest: N/A\n";
        cout << "Passing: 0\n";
        cout << "Not found\n";
        return 0;
    }

    double average = 0;
    int passing = 0;

    for (auto s : data) {
        average += s.score;
        if (s.score >= 60) {
            passing++;
        }
    }
    average = average / data.size();

    auto highIt = max_element(data.begin(), data.end(), [](Student a, Student b) {
        return a.score < b.score;
    });

    auto lowIt = min_element(data.begin(), data.end(), [](Student a, Student b) {
        return a.score < b.score;
    });

    cout << "Average: " << average << "\n";
    cout << "Highest: " << highIt->id << " " << highIt->name << " " << highIt->score << "\n";
    cout << "Lowest: " << lowIt->id << " " << lowIt->name << " " << lowIt->score << "\n";
    cout << "Passing: " << passing << "\n";

    sort(data.begin(), data.end(), [](const Student& a, const Student& b) {
        return a.score > b.score;
    });

    cout << "Sorted:\n";
    for (Student s : data) {
        cout << s.id << " " << s.name << " " << s.score << "\n";
    }

    bool ok = false;
    for (Student s : data) {
        if (s.id == targetId) {
            cout << "Found: " << s.id << " " << s.name << " " << s.score << "\n";
            ok = true;
        }
    }
    if (!ok) cout << "Not found\n";

    return 0;
}
