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
    int Killmobs;
};


void saveGame(Data data) {                         //сохранение
    ofstream saveFile("savegame.txt");
    if (saveFile.is_open()) {
        saveFile << data.name << endl;
        saveFile << data.hp << endl;
        saveFile << data.gold << endl;
        saveFile << data.Killmobs << endl;
        saveFile << data.gun << endl;
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
        saveFile >> data.Killmobs;
        saveFile >> data.gun;
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
    cout << "Убито монстров: " << data.Killmobs << endl;

    switch (data.gun) {
    case 0:
        cout << "Без оружия" << endl;
        break;
    case 1:
        cout << "Лук" << endl;
        break;
    case 2:
        cout << "Меч" << endl;
        break;
    }

}

void battle(Data& data) {
    int mobsHP = rand() % 50 + 30;
    string mobs[6] = { "Слизень","Оборотень","Огр","Орк","Скелет","призрак" };
    string mob = mobs[rand() % 6];
    cout << "На тебя напал " << mob << endl;

    while (mobsHP > 0 && data.hp > 0) {
        cout << "Твое здоровье: " << data.hp << endl;
        cout << "Здоровье врага: " << mobsHP << endl;
        cout << "1.Атаковать" << endl;
        cout << "2.Сбежать(шанс 50%)" << endl;
        cout << "3.Выйти и сохранить" << endl;
    }

    int var;
    cin >> var;
    if (var == 3) {
        saveGame(data);
        return;
    }
    if (var == 1) {
        int damage;

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
        system("cls");
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