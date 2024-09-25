#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> search_countries_by_letter(const unordered_map<string, string> &country_data, char letter)
{
    vector<string> result;
    // แปลงตัวอักษรให้เป็นตัวเล็กเพื่อให้เป็น case-insensitive
    letter = tolower(letter);

    for (const auto &entry : country_data)
    {
        // ตรวจสอบว่า country name ตัวแรกตรงกับตัวอักษรที่ต้องการหรือไม่ (case-insensitive)
        if (tolower(entry.second[0]) == letter)
        {
            result.push_back(entry.second);
        }
    }

    // เรียงลำดับผลลัพธ์ตามลำดับตัวอักษร
    sort(result.begin(), result.end());

    return result;
}

int main()
{
    unordered_map<string, string> country_data = {
        {"+1", "United States"},
        {"+44", "United Kingdom"},
        {"+91", "India"},
        {"+81", "Japan"},
        {"+49", "Germany"},
        {"+86", "China"}};

    char letter;
    cout << "Enter a starting letter: ";
    cin >> letter;

    vector<string> result = search_countries_by_letter(country_data, letter);

    if (result.empty())
    {
        cout << "No countries found starting with '" << letter << "'." << endl;
    }
    else
    {
        cout << "Countries found starting with '" << letter << "':" << endl;
        for (const string &country : result)
        {
            cout << country << endl;
        }
    }

    return 0;
}
