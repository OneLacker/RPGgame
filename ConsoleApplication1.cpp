#include <iostream>
#include <string>
#include <map>

using namespace std;

bool NewGame(map<string, string>& game) {

    cout << "Придумайте имя персонажа: " << endl;

}


void PrintMenu(){
    cout << "|===========МЕНЮ===========|" << endl;
    cout << "|1.Новая игра              |" << endl;
    cout << "|2.Продолжить              |" << endl;
    cout << "|3.Выход                   |" << endl;
    cout << "|==========================|" << endl;
    cout << "Выберите пункт меню: " << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    string user;
    map<string, string>game;
    game[user] = "this";
    int num=0;
    while (true) {
        system("clear");
        PrintMenu();
        cin >> num;
        switch (num) {
        case 1: {

            break;
        }
        case 2: {
            cout << "go" << endl;
            break;
        }
        case 3: {
            cout << "Exit" << endl;
            break;
        }
        default:
            cout << "ошибка, такого пункта меню не существует" << endl;

        }

    }
}