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

int count_lines (string filename)
{
    int amountOL = 0;
    string content;

    ifstream file (filename);
    if (file.is_open() == 0)
    {
        cout << "Ошибка! Файл " << filename << " не был открыт." << endl;
    }

    else 
    {
        getline(file, content);
        cout << endl << " -- Информация из файла " << filename << " -- " << endl << content << endl;
        
        for (char c : content)
        {
            if (c == '.' || c == '?' || c == '!')
            {
                amountOL++;
            }
        }
        cout << endl << "Количество предложений: " << amountOL << endl;

        string *line = new string[amountOL];

        for (char c : content)
        {
            if (c == '.' || c == '?' || c == '!')
            {

            }
        }
    }
    file.close();

    return amountOL;
}

// может все в одну функцию запихнуть? типо сразу будем читать строку и при встрече конца предложения 
void divide(int amountOL)
{
    string *lines = new string[amountOL];

    for (int i = 0; i < amountOL; i++)
    {

    }

}




int main()
{
    string filename;
    cout << "Введите имя файла, информацию из которого хотите считать: ";
    cin >> filename;

    int amountOL = count_lines(filename);

    divide(amountOL);
    string word;
    cout << "Введите слово: ";
    cin >> word;


    

    return 0;
}