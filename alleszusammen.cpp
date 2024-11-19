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

int count_lines (string text)
{
    int amountOL = 0;
    for (char c : text)
        {
            if (c == '.' || c == '?' || c == '!')
            {
                amountOL++;
            }
        }
    return amountOL;
}

//

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

    cout << count_lines(text);

    return 0;
}