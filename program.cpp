#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>  // สำหรับการสุ่ม
#include <ctime>    // สำหรับตั้งค่าสุ่ม

using namespace std;

// โครงสร้างสำหรับคำถามแต่ละข้อ
struct Question {
    string question;  // คำถามที่มีช่องว่าง
    string answer;    // คำตอบที่ถูกต้อง
    string explanation; // คำอธิบายเพิ่มเติม
    int difficulty;   // ระดับความยาก: 1=ง่าย, 2=ปานกลาง, 3=ยาก
};

// ฟังก์ชันที่ใช้สุ่มคำถาม
void shuffleQuestions(vector<Question>& questions) {
    srand(time(0)); // ตั้งค่าการสุ่มด้วยเวลา
    random_shuffle(questions.begin(), questions.end());
}

// ฟังก์ชันหลักของโปรแกรม
int main() {
    vector<Question> allQuestions = {
        {"I am learning to ______ in C++.", "code", "The correct word is 'code'.", 1},
        {"The sun rises in the ______.", "east", "The sun rises in the east.", 1},
        {"An apple a day keeps the ______ away.", "doctor", "An apple a day keeps the doctor away.", 1},
        {"Water boils at ______ degrees Celsius.", "100", "Water boils at 100 degrees Celsius.", 2},
        {"The capital of France is ______.", "paris", "The capital of France is Paris.", 2},
        {"The largest planet in our solar system is ______.", "jupiter", "The largest planet in our solar system is Jupiter.", 2},
        {"The chemical symbol for water is ______.", "h2o", "The chemical symbol for water is H2O.", 3},
        {"______ is the fastest land animal.", "cheetah", "The fastest land animal is the cheetah.", 3},
        {"The process of converting liquid to gas is called ______.", "evaporation", "The process is called evaporation.", 3},
        {"The freezing point of water is ______ degrees Celsius.", "0", "The freezing point of water is 0 degrees Celsius.", 3}
    };

    int difficultyChoice;
    cout << "Select difficulty level (1 = Easy, 2 = Medium, 3 = Hard): ";
    cin >> difficultyChoice;

    // สร้างรายการคำถามตามระดับความยากที่ผู้ใช้เลือก
    vector<Question> selectedQuestions;
    for (Question q : allQuestions) {
        if (q.difficulty == difficultyChoice) {
            selectedQuestions.push_back(q);
        }
    }

    // สุ่มคำถามในระดับที่เลือก
    shuffleQuestions(selectedQuestions);
int totalQuestions = selectedQuestions.size();
    int correct = 0, incorrect = 0;
    vector<Question> wrongQuestions;

    for (Question q : selectedQuestions) {
        string userAnswer;
        cout << q.question << endl;
        cout << "Your answer: ";
        cin >> userAnswer;

        // ตรวจสอบคำตอบโดยไม่สนใจตัวพิมพ์ใหญ่-เล็ก
        transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), ::tolower);
        string correctAnswer = q.answer;
        transform(correctAnswer.begin(), correctAnswer.end(), correctAnswer.begin(), ::tolower);

        if (userAnswer == correctAnswer) {
            cout << "Correct!" << endl;
            correct++;
        } else {
            cout << "Incorrect. " << q.explanation << endl;
            wrongQuestions.push_back(q);
            incorrect++;
        }
    }

  float scorePercentage = (float)correct / totalQuestions * 100;
    cout << "You answered " << correct << " correct and " << incorrect << " incorrect." << endl;
    cout << "Your score: " << scorePercentage << "%" << endl;

    // ตัดสินแพ้ชนะ
    if (scorePercentage >= 70.0) {
        cout << "Congratulations! You win!" << endl;
    } else {
        cout << "You lose. Try again!" << endl;
    }
    return 0;
}
