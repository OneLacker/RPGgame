#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

struct Data {
    string name;
    int hp;
    int gold;
    int gun;
    int mobs;
};


void saveGame(Data data) {                         //сохранение
    ofstream saveFile("savegame.txt");
    if (saveFile.is_open()) {
        saveFile << data.name << endl;
        saveFile << data.hp << endl;
        saveFile << data.gold << endl;
        saveFile << data.mobs << endl;

        saveFile.close();

        cout << "Игра была сохранена!" << endl;
    }
}

bool loadGame(Data &data) {                         //загрузка
    ifstream saveFile("savegame.txt");

    if (saveFile.is_open()) {
        getline(saveFile, data.name);
        saveFile >> data.hp;
        saveFile >> data.gold;
        saveFile >> data.mobs;

        saveFile.close();

        return true;

    }

    return false;
}   


void Status(Data data) {                                      //статус

    cout <<"==============СТАТУС==============" << endl;
    cout << "Персонаж: " << data.name << endl;
    cout << "Здоровье: " << data.hp << endl;
    cout << "Золото: " << data.gold << endl;
    cout << "Убито монстров: " << data.mobs << endl;

    switch (data.gun) {
    case 1:
        cout << "Без оружия" << endl;
        break;
    case 2:
        cout << "Лук" << endl;
        break;
    case 3:
        cout << "Меч" << endl;
        break;
    }

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
            
            break;
        }
        case 3: {

            break;
        }
        default:
            cout << "ошибка, такого пункта меню не существует" << endl;

        }

    }
}