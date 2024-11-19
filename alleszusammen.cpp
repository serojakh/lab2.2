/*Кот сидел на окне и смотрел на кота, который сидел на другом окне. 
Этот кот был серым, а тот кот — белым. 
Белый кот, заметив серого кота, запрыгнул к нему на окно: два кота сидели на одном окне и смотрели на улицу. 
Мимо прошёл ещё один кот. 
Этот кот был рыжим? Рыжий кот посмотрел на двух котов на окне и пошёл дальше. 
Теперь на улице было три кота (серый кот, белый кот и рыжий кот). 
Все коты любили сидеть на окне!*/



#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void count_divide_count (string text, string word)
{
    int amountOL = 0;
    for (char c : text)
    {
        if (c == '.' || c == '?' || c == '!')
        {
            amountOL++;
        }
    }

    char** sentences = new char*[amountOL];

    int sentenceIndex = 0;
    int start = 0;
    for (int i = 0; i < text.length(); i++) 
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') 
        {
            int length = i - start + 1;
            sentences[sentenceIndex] = new char[length + 1];
            strncpy(sentences[sentenceIndex], text.c_str() + start, length);
            sentences[sentenceIndex][length] = '\0';
            sentenceIndex++;
            start = i + 1;
        }
    }
    

    for (int i = 0; i < amountOL; i++)
    {
        cout << "Предложение №" << i + 1 << ": " << sentences[i];
        // вот здесь должнен проивзодиться подсчет вхождения заданного слова, а затем вывод цифры
    }

}


int main()
{
    string filename;
    cout << "Введите имя файла, информацию из которого хотите считать: ";
    cin >> filename;

    ifstream file (filename);
    if (file.is_open() == 0)
    {
        cout << "Ошибка! Файл " << filename << " не был открыт." << endl;
        return 1;
    }

    string text;
    string line;
    while (getline(file, line)) 
    {
        text += line + "\n"; 
    }

    file.close();

    cout << "----ИНФОРМАЦИЯ ИЗ ФАЙЛА----" << endl << endl;
    cout << text << endl;

    string word;
    cout << "Введите слово: ";
    cin >> word;
    count_divide_count(text, word);

    return 0;
}