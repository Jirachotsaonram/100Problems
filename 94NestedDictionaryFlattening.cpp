#include <iostream>
#include <map>
#include <string>
#include <variant>
#include <vector>

using namespace std;

// ใช้ std::variant เพื่อรองรับค่าหลายประเภท
using JsonValue = variant<int, string, map<string, variant<int, string>>, vector<map<string, variant<int, string>>>>;

void flattenHelper(const map<string, JsonValue>& d, map<string, JsonValue>& flatDict, const string& prefix, const string& separator) {
    for (const auto& [key, value] : d) {
        string newKey = prefix.empty() ? key : prefix + separator + key;

        // ตรวจสอบประเภทของค่า
        if (holds_alternative<int>(value)) {
            flatDict[newKey] = get<int>(value);
        } else if (holds_alternative<string>(value)) {
            flatDict[newKey] = get<string>(value);
        } else if (holds_alternative<map<string, JsonValue>>(value)) {
            flattenHelper(get<map<string, JsonValue>>(value), flatDict, newKey, separator);
        } else if (holds_alternative<vector<map<string, JsonValue>>>(value)) {
            const auto& vec = get<vector<map<string, JsonValue>>>(value);
            for (size_t i = 0; i < vec.size(); ++i) {
                flattenHelper(vec[i], flatDict, newKey + separator + to_string(i), separator);
            }
        }
    }
}

// ฟังก์ชันหลักในการแปลงดิกชันนารีที่ซ้อนกัน
map<string, JsonValue> flatten_dict(const map<string, JsonValue>& d, const string& separator = ".") {
    map<string, JsonValue> flatDict;
    flattenHelper(d, flatDict, "", separator);
    return flatDict;
}

int main() {
    // ตัวอย่างดิกชันนารี
    map<string, JsonValue> d = {
        {"user", map<string, JsonValue>{
            {"name", "Alice"},
            {"address", map<string, JsonValue>{
                {"city", "Wonderland"},
                {"zip", "12345"}
            }},
            {"email", "alice@example.com"}
        }}
    };

    // เรียกใช้งานฟังก์ชัน flatten_dict
    auto flattened = flatten_dict(d, "_");

    // แสดงผลลัพธ์
    for (const auto& [key, value] : flattened) {
        if (holds_alternative<int>(value)) {
            cout << key << ": " << get<int>(value) << endl;
        } else if (holds_alternative<string>(value)) {
            cout << key << ": " << get<string>(value) << endl;
        }
    }

    return 0;
}
