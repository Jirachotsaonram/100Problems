#include <iostream>
#include <map>
#include <string>
#include <variant>

// กำหนดประเภทข้อมูลใน dictionary (ใช้ std::variant รองรับหลายประเภทข้อมูล)
using JsonValue = std::variant<std::string, int, std::map<std::string, JsonValue>>;
using JsonDict = std::map<std::string, JsonValue>;

// ฟังก์ชันสำหรับตรวจสอบและเปรียบเทียบค่า
void compare_json(const JsonValue &dict1, const JsonValue &dict2, JsonDict &added, JsonDict &removed, JsonDict &modified) {
    // แปลง JsonValue เป็น map (กรณีที่ค่าเป็น map)
    const auto* map1 = std::get_if<JsonDict>(&dict1);
    const auto* map2 = std::get_if<JsonDict>(&dict2);
    
    if (!map1 || !map2) return;  // ถ้าข้อมูลไม่ใช่ map ก็ไม่สามารถเปรียบเทียบได้
    
    for (const auto& [key, val] : *map2) {
        if (map1->find(key) == map1->end()) {
            // กรณี key อยู่ใน dict2 แต่ไม่อยู่ใน dict1 -> ถือว่าเป็น "added"
            added[key] = val;
        } else {
            const JsonValue &val1 = (*map1).at(key);
            if (val1 != val) {
                // กรณี key อยู่ในทั้ง dict1 และ dict2 แต่มีค่าต่างกัน -> ถือว่าเป็น "modified"
                modified[key] = JsonDict{{"from", val1}, {"to", val}};
            }
        }
    }
    
    for (const auto& [key, val] : *map1) {
        if (map2->find(key) == map2->end()) {
            // กรณี key อยู่ใน dict1 แต่ไม่อยู่ใน dict2 -> ถือว่าเป็น "removed"
            removed[key] = val;
        }
    }
}

// ฟังก์ชันหลักสำหรับเรียกการเปรียบเทียบ JSON dictionaries
JsonDict json_diff(const JsonDict &dict1, const JsonDict &dict2) {
    JsonDict added, removed, modified;
    
    compare_json(dict1, dict2, added, removed, modified);
    
    return JsonDict{
        {"added", added},
        {"removed", removed},
        {"modified", modified}
    };
}

// ฟังก์ชันแสดงผล JSON แบบง่าย ๆ
void print_json(const JsonDict &json) {
    std::cout << "{\n";
    for (const auto& [key, val] : json) {
        std::cout << "  \"" << key << "\": ";
        if (std::holds_alternative<JsonDict>(val)) {
            print_json(std::get<JsonDict>(val));
        } else if (std::holds_alternative<int>(val)) {
            std::cout << std::get<int>(val);
        } else {
            std::cout << "\"" << std::get<std::string>(val) << "\"";
        }
        std::cout << ",\n";
    }
    std::cout << "}\n";
}

int main() {
    // ตัวอย่าง dict1 และ dict2
    JsonDict dict1 = {
        {"name", "Alice"},
        {"age", 30},
        {"address", JsonDict{
            {"city", "Wonderland"},
            {"zip", "12345"}
        }}
    };
    
    JsonDict dict2 = {
        {"name", "Alice"},
        {"age", 31},
        {"address", JsonDict{
            {"city", "Wonderland"},
            {"zip", "54321"}
        }},
        {"email", "alice@example.com"}
    };

    // เรียกฟังก์ชัน json_diff
    JsonDict result = json_diff(dict1, dict2);
    
    // แสดงผลลัพธ์
    print_json(result);

    return 0;
}
