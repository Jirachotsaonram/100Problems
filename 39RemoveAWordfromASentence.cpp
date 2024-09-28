#include <iostream>
#include <sstream>
using namespace std;

// Function to remove all occurrences of a word from a sentence
string remove_word(const string& sentence, const string& word_to_remove) {
    stringstream ss(sentence);
    string word, result;
    bool first_word = true;

    // Iterate over each word in the sentence
    while (ss >> word) {
        // Check if the current word is not equal to the word we want to remove
        if (word != word_to_remove) {
            // If this is not the first word in the result, add a space before the next word
            if(!first_word){
                result += " ";
            }
            result += word;  // Append the word to the result
            first_word = false;
        }
    }

    return result;
}

int main() {
    string sentence, word_to_remove;

    // Input sentence and the word to remove
    cout << "Enter a sentence: ";
    getline(cin, sentence);  // Read the full sentence including spaces

    cout << "Enter the word to remove: ";
    cin >> word_to_remove;  // Read the word to remove

    // Remove the word from the sentence
    string updated_sentence = remove_word(sentence, word_to_remove);

    // Output the result
    cout << "Updated Sentence: " << updated_sentence << endl;

    return 0;
}
