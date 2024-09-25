#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// ฟังก์ชันสำหรับดำเนินการ union และ intersection
pair<set<char>, set<char>> set_operations(const set<char>& set1, const set<char>& set2) {
    set<char> unionSet;
    set<char> intersectionSet;

    // หาผลรวม (Union) ของ set1 และ set2
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(unionSet, unionSet.begin()));

    // หาจุดตัด (Intersection) ของ set1 และ set2
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(intersectionSet, intersectionSet.begin()));

    return {unionSet, intersectionSet};
}

int main() {
    // เซ็ตตัวอักษร 2 ชุด
    set<char> set1 = {'a', 'e', 'i', 'o', 'u'};
    set<char> set2 = {'h', 'e', 'l', 't', 'o'};

    // เรียกฟังก์ชัน set_operations
    pair<set<char>, set<char>> result = set_operations(set1, set2);

    // แสดงผลลัพธ์
    cout << "Union: { ";
    for (char c : result.first) {
        cout << c << " ";
    }
    cout << "}" << endl;

    cout << "Intersection: { ";
    for (char c : result.second) {
        cout << c << " ";
    }
    cout << "}" << endl;

    return 0;
}
