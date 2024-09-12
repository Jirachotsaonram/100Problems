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
};

// ฟังก์ชันที่ใช้สุ่มคำถาม
void shuffleQuestions(vector<Question>& questions) {
    srand(time(0)); // ตั้งค่าการสุ่มด้วยเวลา
    random_shuffle(questions.begin(), questions.end());
}

// ฟังก์ชันหลักของโปรแกรม
int main() {
    vector<Question> questions = {
        {"I am learning to ______ in C++.", "code", "The correct word is 'code'."},
        {"The sun rises in the ______.", "east", "The sun rises in the east."},
        {"An apple a day keeps the ______ away.", "doctor", "An apple a day keeps the doctor away."},
    };

    shuffleQuestions(questions);

    int correct = 0, incorrect = 0;
    vector<Question> wrongQuestions;

    for (Question q : questions) {
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

    cout << "You answered " << correct << " correct and " << incorrect << " incorrect." << endl;

    if (!wrongQuestions.empty()) {
        char choice;
        cout << "Do you want to try the wrong questions again? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            for (Question q : wrongQuestions) {
                string userAnswer;
                cout << q.question << endl;
                cout << "Your answer: ";
                cin >> userAnswer;

                transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), ::tolower);
                string correctAnswer = q.answer;
                transform(correctAnswer.begin(), correctAnswer.end(), correctAnswer.begin(), ::tolower);

                if (userAnswer == correctAnswer) {
                    cout << "Correct!" << endl;
                    correct++;
                } else {
                    cout << "Incorrect again. " << q.explanation << endl;
                    incorrect++;
                }
            }
        }
    }

    cout << "Final score: " << correct << " correct, " << incorrect << " incorrect." << endl;
    return 0;
}
