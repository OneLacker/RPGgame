#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>

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

void NPC(Data& data) {
    cout << "....." << endl;
    switch (data.Killmobs) {
        case 0 :
            cout<<"Твое первое задание - убить 5 монстров"<<endl;
            break;
        case 5 :
            cout<<"Твое первое задание - убить 10 монстров"<<endl;
            break;
        case 10 :
            cout<<"Твое первое задание - убить 15 монстров"<<endl;
            break;
        case 15 :
            cout<<"Ты молодец, потратил время впустую и прошел игру!"<<endl;
            saveGame(<#Data data#>);
            system("clear");
    }
//    cout << "ты должен выполнить несколько заданий, первое из них - убить 10 монстров" << endl;
    cout << "выбери направление, куда хочешь пойти: " << endl;
    cout << "1.пойти налево" << endl;
    cout << "2.пойти направо" << endl;
}

void Kvest(Data& data) {
    switch (data.Killmobs) {
        case 5 :
            cout<<"Ты выполнил первый квест! "<<endl;
            NPC(<#Data &data#>)
            break;
        case 10 :
            cout<<"Ты выполнил второй квест! "<<endl;
            NPC(<#Data &data#>)
            break;
        case 15 :
            cout<<"Ты выполнил третий квест! "<<endl;
            NPC(<#Data &data#>)
            break;
    }
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

void PrintMenu(){
    cout << "|===========МЕНЮ===========|" << endl;
    cout << "|1.Новая игра              |" << endl;
    cout << "|2.Продолжить              |" << endl;
    cout << "|3.Выход                   |" << endl;
    cout << "|==========================|" << endl;
    cout << "Выберите пункт меню: ";
}

void battle(Data& data) {
    int damage=0;
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

        int var;
        cin >> var;
        
        if (var == 3) {
            saveGame(data);
            return;
        }
        
        if (var == 1) {
            switch (data.gun) {
                case 0:
                    damage = rand() % 10 + 5;
                    break;
                case 1:
                    damage = rand() % 15 + 10;
                    break;
                case 2:
                    damage = rand() % 15 + 20;
                    break;
            }
            
            mobsHP -= damage;
            cout << "Ты нанес " << damage << " урона" << endl;
            
            // моб умер с одной атаки
            if (mobsHP <= 0) {
                cout << "Ты победил! " << endl;
                int reward = rand() % 50 + 10;
                data.gold += reward;
                data.Killmobs++;
                cout << "Ты получил " << reward << " золота!" << endl;
                return;  // выход из функции после победы
            }
            
            // атака моба если он жив
            int mobDamage = rand() % 10 + 10;
            data.hp -= mobDamage;
            cout << "Моб атаковал и нанес " << mobDamage << " урона" << endl;
            
            // смерть игрока
            if (data.hp <= 0) {
                cout << "Смертельный урон, ты проиграл" << endl;
                cout << "1.Загрузить последнее сохранение" << endl;
                cout << "2.Выйти в главное меню" << endl;
                cin >> var;
                
                if (var == 1) {
                    loadGame(data);
                    cout << "Игра загруженна." << endl;
                    return;
                }
                else {
                    return;  //в главное меню
                }
            }
        }
        else if (var == 2) {
            if (rand() % 2 == 0) {
                cout << "Удалось сбежать" << endl;
                return;
            }
            else {
                cout << "Не удалось сбежать, бой продолжается" << endl;
                int mobDamage = rand() % 20 + 10;
                data.hp -= mobDamage;
                cout << "Ты получил " << mobDamage << " урона" << endl;
                
                if (data.hp <= 0) {
                    cout << "Смертельный урон, ты проиграл" << endl;
                    cout << "1.Загрузить последнее сохранение" << endl;
                    cout << "2.Выйти в главное меню" << endl;
                    cin >> var;
                    
                    if (var == 1) {
                        loadGame(data);
                        cout << "Игра загруженна." << endl;
                        return;
                    }
                    else {
                        return;
                    }
                }
            }
        }
    }
}


void Shop(Data& data) {
    int var;
    cout << "Ты встретил на пути магазин" << endl;
    cout << "Торговец: привет путник, что желаешь приобрести?" << endl;
    cout << "1.Зелье восстановления здоровья" << endl;
    cout << "2.Мечь" << endl;
    cout << "3.Лук" << endl;
    cout << "4.Выход" << endl;


    
    cin >> var;
    switch (var) {
    case 1:
        if (data.hp == 100) {
            cout << "Ваше здоровье полное, нельзя восстановить" << endl;
        }
        else if (data.hp != 100) {
            data.hp = data.hp + 20;
        }
        else if (data.hp > 100) {
            data.hp = 100;
        }
        battle(data);
        break;
    case 2:
        data.gun = 2;
        cout << "Ваше новое оружие-мечь" << endl;
        battle(data);
        break;
    case 3:
        data.gun = 1;
        cout << "Ваше новое оружие-лук(репчатый)" << endl;
        battle(data);
        break;
    case 4:
        if (rand() % 2 == 0) {
            battle(data);
        }
        else {
            cout << "КАК ТЫ ПОСМЕЛ НИЧЕГО НЕ КУПИТЬ?" << endl;
            data.hp = 1;
            cout << "Продавец разозлился, ваше здоровье сниженно до 1" << endl;
        }
        battle(data);
        break;
    }
}

//void Kvest(Data& data) {
//    switch (data.Killmobs) {
//        case 5 :
//            cout<<"Ты выполнил первый квест! "<<endl;
//            NPC();
//            break;
//        case 10 :
//            cout<<"Ты выполнил второй квест! "<<endl;
//            NPC();
//            break;
//        case 15 :
//            cout<<"Ты выполнил третий квест! "<<endl;
//            NPC();
//            break;
//    }
//}

//void PrintMenu(){
//    cout << "|===========МЕНЮ===========|" << endl;
//    cout << "|1.Новая игра              |" << endl;
//    cout << "|2.Продолжить              |" << endl;
//    cout << "|3.Выход                   |" << endl;
//    cout << "|==========================|" << endl;
//    cout << "Выберите пункт меню: ";
//}

//void NPC() {
//    cout << "....." << endl;
//    cout << "ты должен выполнить несколько заданий, первое из них - убить 10 монстров" << endl;
//    cout << "выбери направление, куда хочешь пойти: " << endl;
//    cout << "1.пойти налево" << endl;
//    cout << "2.пойти направо" << endl;
//}

int main() {


    setlocale(LC_ALL, "ru");
    int num=0;
    int doroga=0;
    Data playerData;
    while (true) {
        system("cls");
        PrintMenu();
        cin >> num;
        switch (num) {
        case 1: {
            cout << "Придумай имя персонажа: ";
            cin >> playerData.name;
            playerData.hp = 100;
            playerData.gold = 0;
            playerData.Killmobs = 0;
            playerData.gun = 0;

            NPC(<#Data &data#>);
            cin >> doroga;
            if (doroga == 1) {
                battle(playerData);
            }
            else if (doroga == 2) {
                battle(playerData);
            }
            else {
                cout << "есть только две дороги!" << endl;
            }
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
