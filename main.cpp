#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

void PrintMenu();

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

void Shop(Data& data) {
    int var;
        cout<<"Ты встретил на пути магазин"<<endl;
        cout<<"Торговец: привет путник, что желаешь приобрести?"<<endl;
        cout<<"1.Зелье восстановления здоровья"<<endl;
        cout<<"2.Мечь"<<endl;
        cout<<"3.Лук"<<endl;
        cout<<"4.Выход"<<endl;
        
        cin>>var;
     switch (var) {
        case 1:
            if(data.hp==100){
                cout<<"Ваше здоровье полное, нельзя восстановить"<<endl;
            }
            else if (data.hp!=100){
                data.hp=data.hp+20;
            }
            else if(data.hp > 100) {
                data.hp=100;
            }
             battle(<#Data &data#>);
             break;
        case 2:
            data.gun=2;
            cout<<"Ваше новое оружие-мечь"<<endl;
             battle(<#Data &data#>);
            break;
        case 3:
            data.gun=1;
            cout<<"Ваше новое оружие-лук(репчатый)"<<endl;
             battle(<#Data &data#>);
             break;
        case 4:
            if (rand() % 2 ==0) {
                battle(<#Data &data#>);
            } else {
                cout<<"КАК ТЫ ПОСМЕЛ НИЧЕГО НЕ КУПИТЬ?"<<endl;
                data.hp=1;
                cout<<"Продавец разозлился, ваше здоровье сниженно до 1"<<endl;
            } 
             battle(<#Data &data#>);
             break;
    }
}

void battle(Data& data) {
    int damage = 0;  // Инициализируй переменную
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
        switch (data.gun) {
        case 0:
            damage = rand() % 10 + 5;
            break;
        case 1:
            damage = rand() % 15 + 10;
            break;
        case 2:
            damage = rand() % 15 + 20;
            break;  // Добавь break и здесь!
        }

        mobsHP -= damage;
        cout << "Ты нанес " << damage << " урона" << endl;
    }

    else if (var == 2) {
        if (rand() % 2 == 0) {
            cout << "удалось сбежать" << endl;
            
        }
        else {
            cout << "не удалось сбежать, бой продолжается" << endl;
            int mobDamage = rand() % 20 + 10;
            data.hp -= mobDamage;
            cout << "Ты получил " << mobDamage << " урона" << endl;
        }
    }
    if (data.hp <= 0) {
        cout << "Смертельный урон, ты проиграл" << endl;
        cout << "1.Загрузить последнее сохранение" << endl;
        cout << "2.Выйти в главное меню" << endl;
        cin >> var;
        
        if (var == 1) {
            loadGame(data);
            cout << "Игра загруженна." << endl;
        }
        else {
            PrintMenu();
        }
    }
    else {
        cout << "Ты победил! " << endl;
        int revard = rand() % 50 + 10;
        data.gold += revard;
        data.Killmobs++;
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

void DialogMenu(){
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
        PrintMenu();
        system("clear");
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

//#include <iostream>
//#include <string>
//#include <fstream>
//#include <cstdlib> // для rand
//#include <ctime>   // для time
//
//using namespace std;
//
//class Character { // класс персонажа с стандартным набором характеристик
//public:
//    Character(const string& name = "", int hp = 100, int gold = 0, int gun = 0, int killmobs = 0)
//        : name(name), hp(hp), gold(gold), gun(gun), killmobs(killmobs) {}
//
//    void displayStats() const { // характеристики на экране
//        cout << "Имя: " << name << endl;
//        cout << "Здоровье: " << hp << endl;
//        cout << "Золото: " << gold << endl;
//        cout << "Уровень оружия: " << gun << endl;
//        cout << "Убито мобов: " << killmobs << endl;
//    }
//
//    string getName() const { return name; }
//    int getHp() const { return hp; }
//    int getGold() const { return gold; }
//    int getGun() const { return gun; }
//    int getKillmobs() const { return killmobs; }
//
//    void setHp(int newHp) { hp = newHp; }
//    void addGold(int amount) { gold += amount; }
//    void incrementKillmobs() { killmobs++; }
//
//    void saveToFile(const string& filename) const {
//        ofstream saveFile(filename);
//        if (saveFile.is_open()) {
//            saveFile << name << endl;
//            saveFile << hp << endl;
//            saveFile << gold << endl;
//            saveFile << killmobs << endl;
//            saveFile << gun << endl;
//            saveFile.close();
//            cout << "Игра была сохранена!" << endl;
//        }
//    }
//
//    bool loadFromFile(const string& filename) {
//        ifstream saveFile(filename);
//        if (saveFile.is_open()) {
//            getline(saveFile, name);
//            saveFile >> hp;
//            saveFile >> gold;
//            saveFile >> killmobs;
//            saveFile >> gun;
//            saveFile.close();
//            return true;
//        }
//        return false;
//    }
//
//private:
//    string name;
//    int hp;
//    int gold;
//    int gun;
//    int killmobs;
//};
//
//class Game {
//public:
//    Game() {
//        srand(static_cast<unsigned int>(time(nullptr))); // инициализация генератора случайных чисел
//        character = Character();
//    }
//
//    void start() {
//        int choice;
//        bool running = true;
//
//        while (running) {
//            printMenu();
//            cin >> choice;
//
//            switch (choice) {
//            case 1:
//                startNewGame();
//                break;
//            case 2:
//                continueGame();
//                break;
//            case 3:
//                running = false;
//                cout << "Выход из программы." << endl;
//                break;
//            default:
//                cout << "Ошибка: такого пункта меню не существует." << endl;
//            }
//        }
//    }
//
//private:
//    Character character;
//
//    void printMenu() {
//        cout << "|===========МЕНЮ===========|" << endl;
//        cout << "|1. Новая игра             |" << endl;
//        cout << "|2. Продолжить             |" << endl;
//        cout << "|3. Выход                  |" << endl;
//        cout << "|==========================|" << endl;
//        cout << "Выберите пункт меню: ";
//    }
//
//    void startNewGame() {
//        string name;
//        cout << "Введите имя персонажа: ";
//        cin >> name;
//        character = Character(name); // Сброс характеристик
//        character.displayStats();
//        cout << "Нажмите Enter, чтобы продолжить...";
//        cin.ignore();
//        cin.get();
//    }
//
//    void continueGame() {
//        if (character.loadFromFile("savegame.txt")) {
//            cout << "Игра загружена." << endl;
//            character.displayStats();
//            battle();
//        } else {
//            cout << "Не удалось загрузить играл, начните новую игру." << endl;
//        }
//    }
//
//    void battle() {
//        int damage;
//        int mobsHP = rand() % 50 + 30;
//        string mobs[6] = { "Слизень","Оборотень","Огр","Орк","Скелет","призрак" };
//        string mob = mobs[rand() % 6];
//        cout << "На тебя напал " << mob << endl;
//
//        while (mobsHP > 0 && character.getHp() > 0) {
//            cout << "Твое здоровье: " << character.getHp() << endl;
//            cout << "Здоровье врага: " << mobsHP << endl;
//            cout << "1. Атаковать" << endl;
//            cout << "2. Сбежать (шанс 50%)" << endl;
//            cout << "3. Выйти и сохранить" << endl;
//
//            int var;
//            cin >> var;
//            if (var == 3) {
//                character.saveToFile("savegame.txt");
//                return;
//            }
//
//            if (var == 1) {
//                damage = rand() % 10 + 5 + character.getGun() * 5; // Урон зависит от уровня оружия
//                mobsHP -= damage;
//                cout << "Ты нанес " << damage << " урона" << endl;
//            } else if (var == 2) {
//                if (rand() % 2 == 0) {
//                    cout << "Удалось сбежать!" << endl;
//                    return;
//                } else {
//                    cout << "Не удалось сбежать, бой продолжается." << endl;
//                    int mobDamage = rand() % 20 + 10;
//                    character.setHp(character.getHp() - mobDamage);
//                    cout << "Ты получил " << mobDamage << " урона" << endl;
//                }
//            }
//
//            if (character.getHp() <= 0) {
//                cout << "Смертельный урон, ты проиграл" << endl;
//                cout << "1. Загрузить последнее сохранение" << endl;
//                cout << "2. Выйти в главное меню" << endl;
//                cin >> var;
//                if (var == 1) {
//                    character.loadFromFile("savegame.txt");
//                    cout << "Игра загружена." << endl;
//                } else {
//                    printMenu();
//                }
//            } else if (mobsHP <= 0) {
//                cout << "Ты победил!" << endl;
//                int revard = rand() % 50 + 10;
//                character.addGold(revard);
//                character.incrementKillmobs();
//                cout << "Ты получил " << revard << " золота!" << endl;
//            }
//        }
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    Game game;
//    game.start();
//
//    return 0;
//}
