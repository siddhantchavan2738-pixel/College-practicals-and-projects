// Practical 9
// Title: Use STL Containers (vector, map, unordered_map)
// and Algorithms (sort, find_if, transform) to process
// a student marks dataset.


#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    vector<pair<string, int>> students = {
        {"Amit", 85},
        {"Rahul", 72},
        {"Sneha", 95},
        {"Priya", 68},
        {"Rohit", 80}
    };

    map<string, int> marksMap;
    unordered_map<string, int> studentData;

    for (auto s : students) {
        marksMap[s.first] = s.second;
        studentData[s.first] = s.second;
    }

    sort(students.begin(), students.end(),
         [](auto a, auto b) {
             return a.second > b.second;
         });

    cout << "Students sorted by marks:\n";
    for (auto s : students) {
        cout << s.first << " : " << s.second << endl;
    }

    auto it = find_if(students.begin(), students.end(),
        [](auto s) {
            return s.second >= 90;
        });

    if (it != students.end())
        cout << "\nStudent scoring 90 or above: "
             << it->first << endl;

    vector<int> updatedMarks;

    transform(students.begin(), students.end(),
              back_inserter(updatedMarks),
              [](auto s) {
                  return s.second + 5;
              });

    cout << "\nMarks after adding 5 bonus marks:\n";
    for (int m : updatedMarks)
        cout << m << " ";

    cout << "\n\nUsing map:\n";
    for (auto s : marksMap)
        cout << s.first << " : " << s.second << endl;

    cout << "\nUsing unordered_map:\n";
    for (auto s : studentData)
        cout << s.first << " : " << s.second << endl;

    return 0;
}
