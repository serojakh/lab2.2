/*There is a cute little cat sitting on the windowsill, watching the birds and an orange cat outside. 
His fur is soft and fluffy, perfect for snuggling with on a chilly evening. 
I love how the cat purrs contentedly when I scratch behind its ears. 
Sometimes, the cat likes to play with another cat or a ball of yarn, swatting at it with its paws. 
I often find the cat curled up in a sunny spot, basking in the warmth. 
My heart melts every time I see the his big green eyes looking up at me.*/



#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void count_divide_count(const char *text, const char *word) {
    int amountOL = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            amountOL++;
        }
    }

    char **sentences = new char *[amountOL];
    int sentenceIndex = 0;
    int start = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            int length = i - start + 1;
            sentences[sentenceIndex] = new char[length + 1];
            strncpy(sentences[sentenceIndex], text + start, length);
            sentences[sentenceIndex][length] = '\0';
            sentenceIndex++;
            start = i + 1;
        }
    }

    for (int i = 0; i < amountOL; i++) {
        cout << endl << "Sentence #" << i + 1 << ": " << sentences[i] << endl;
        int count = 0;

        char *sentence = sentences[i];
        char *token = strtok(sentence, " ,.;!?\n");
        while (token != nullptr) {
            if (strcmp(token, word) == 0) {
                count++;
            }
            token = strtok(nullptr, " ,.;!?\n");
        }

        cout << "The word '" << word << "' appears " << count << " time(s)." << endl;
    }

    for (int i = 0; i < amountOL; i++) {
        delete[] sentences[i];
    }
    delete[] sentences;
}

int main() {
    cout << "Enter the filename: ";
    string filename;
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open the file " << filename << endl;
        return 1;
    }

    cout << "The text below was extracted from file " << filename << ":" << endl;

    const int MAX_TEXT_SIZE = 1000;
    char *text = new char[MAX_TEXT_SIZE];
    file.getline(text, MAX_TEXT_SIZE, '\0');
    file.close();

    cout << "----TEXT----" << endl;
    cout << text << endl;

    cout << "Enter the word to search for: ";
    char word[100];
    cin >> word;

    count_divide_count(text, word);

    delete[] text;

    return 0;
}
