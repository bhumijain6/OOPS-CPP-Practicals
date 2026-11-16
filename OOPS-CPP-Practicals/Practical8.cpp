
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    vector<int> marks = {75, 90, 65, 85, 70};

    // Sort
    sort(marks.begin(), marks.end());

    cout << "Sorted Marks: ";
    for (int m : marks)
        cout << m << " ";
    cout << endl;

    // Find
    auto it = find(marks.begin(), marks.end(), 85);

    if (it != marks.end())
        cout << "85 Found!" << endl;
    else
        cout << "85 Not Found!" << endl;

    // Transform
    vector<int> updated(marks.size());

    transform(marks.begin(), marks.end(),
              updated.begin(),
              [](int x) { return x + 5; });

    cout << "Updated Marks: ";
    for (int m : updated)
        cout << m << " ";
    cout << endl;

    // Map
    map<string, int> students;
    students["Aman"] = 90;
    students["Riya"] = 85;

    cout << "Student Marks:\n";
    for (auto p : students)
        cout << p.first << ": " << p.second << endl;

    // Unordered Map
    unordered_map<int, string> data;
    data[1] = "Aman";
    data[2] = "Riya";

    cout << "Unordered Map:\n";
    for (auto p : data)
        cout << p.first << ": " << p.second << endl;

    return 0;
}
