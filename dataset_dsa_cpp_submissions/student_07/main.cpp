#include <iostream>
#include <vector>

using namespace std;

struct Student {
    int id;
    string name;
    double score;
};

void bubbleSort(vector<Student>& s) {
    for (int i = 0; i < (int)s.size(); i++) {
        for (int j = 0; j + 1 < (int)s.size() - i; j++) {
            if (s[j].score < s[j + 1].score) {
                Student t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<Student> s;
    for (int i = 0; i < n; i++) {
        Student item;
        cin >> item.id >> item.name >> item.score;
        s.push_back(item);
    }

    int qid;
    cin >> qid;

    if (s.empty()) {
        cout << "Average: 0\nHighest: N/A\nLowest: N/A\nPassing: 0\nNot found\n";
        return 0;
    }

    double total = 0;
    int pass = 0;
    Student hi = s[0];
    Student lo = s[0];

    for (int i = 0; i < (int)s.size(); i++) {
        total += s[i].score;
        if (s[i].score >= 60.0) pass++;

        if (s[i].score >= hi.score) hi = s[i];
        if (s[i].score <= lo.score) lo = s[i];
    }

    cout << "Average: " << total / s.size() << "\n";
    cout << "Highest: " << hi.id << " " << hi.name << " " << hi.score << "\n";
    cout << "Lowest: " << lo.id << " " << lo.name << " " << lo.score << "\n";
    cout << "Passing: " << pass << "\n";

    bubbleSort(s);

    cout << "Sorted:\n";
    for (auto st : s) {
        cout << st.id << " " << st.name << " " << st.score << "\n";
    }

    bool found = false;
    for (auto st : s) {
        if (st.id == qid) {
            found = true;
            cout << "Found: " << st.id << " " << st.name << " " << st.score << "\n";
            break;
        }
    }

    if (!found) cout << "Not found\n";

    return 0;
}
