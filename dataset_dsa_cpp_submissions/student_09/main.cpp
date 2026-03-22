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

    vector<Student> list;
    for (int i = 0; i < n; i++) {
        Student temp;
        cin >> temp.id >> temp.name >> temp.score;
        list.push_back(temp);
    }

    int idToFind;
    cin >> idToFind;

    double sum = 0;
    int passing = 0;

    if (!list.empty()) {
        Student highest = list[0];
        Student lowest = list[0];

        for (int i = 0; i < (int)list.size(); i++) {
            sum += list[i].score;
            if (list[i].score >= 60) passing++;
            if (list[i].score > highest.score) highest = list[i];
            if (list[i].score < lowest.score) lowest = list[i];
        }

        cout << "Average: " << sum / list.size() << "\n";
        cout << "Highest: " << highest.id << " " << highest.name << " " << highest.score << "\n";
        cout << "Lowest: " << lowest.id << " " << lowest.name << " " << lowest.score << "\n";
        cout << "Passing: " << passing << "\n";
    } else {
        cout << "Average: 0\n";
        cout << "Highest: N/A\n";
        cout << "Lowest: N/A\n";
        cout << "Passing: 0\n";
    }

    sort(list.begin(), list.end(), [](Student a, Student b) {
        return a.score > b.score;
    });

    cout << "Sorted:\n";
    for (int i = 0; i < (int)list.size(); i++) {
        cout << list[i].id << " " << list[i].name << " " << list[i].score << "\n";
    }

    int idx = -1;
    for (int i = 0; i < (int)list.size(); i++) {
        if (list[i].id == idToFind) {
            idx = i;
            break;
        }
    }

    if (idx == -1)
        cout << "Not found\n";
    else
        cout << "Found: " << list[idx].id << " " << list[idx].name << " " << list[idx].score << "\n";

    return 0;
}
