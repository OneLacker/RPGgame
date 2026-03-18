#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Data {
    string name;
    int hp;
    int gold;
    int gun;
    int Killmobs;
};

struct Location {
    string name;
    string description;
    vector<string> enemies; // мобы в локации
};

enum LocationType {
    FOREST,
    CAVE,
    SWAMP,
    RUINS,
    MOUNT,
    COUNT  //количество лок
};

map<LocationType, Location> locations;

void initLocations() {
    locations[FOREST] = {"Лес", "Густой лес с высокими деревьями и таинственными звуками",
                         {"Лесной тролль", "Волк", "Гоблин", "Паук-гигант"}};
    locations[CAVE] = {"Пещера", "Темная и сырая пещера с капающей водой",
                       {"Летучая мышь", "Гоблин", "Каменный голем", "Подземный червь"}};
    locations[SWAMP] = {"Болото", "Гнилостное болото с туманом и странными огоньками",
                        {"Болотный тролль", "Гигантская пиявка", "Болотный дух", "Крокодил"}};
    locations[RUINS] = {"Руины", "Древние руины когда-то великого города",
                        {"Скелет", "Призрак", "Архитектор руин", "Древний страж"}};
    locations[MOUNT] = {"Горы", "Высокие заснеженные горы с опасными тропами",
                            {"Снежный йети", "Горный тролль", "Орел-хищник", "Ледяной элементаль"}};
}

LocationType getRandomLocation() {
    return static_cast<LocationType>(rand() % COUNT);
}

string getRandomEnemy(LocationType location) {
    const vector<string>& enemies = locations[location].enemies;
    return enemies[rand() % enemies.size()];
}

void saveGame(Data data) {
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

bool loadGame(Data &data) {
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
        case 0:
            cout << "Твое первое задание - убить 5 монстров" << endl;
            break;
        case 5:
            cout << "Твое первое задание - убить 10 монстров" << endl;
            break;
        case 10:
            cout << "Твое первое задание - убить 15 монстров" << endl;
            break;
        case 15:
            cout << "Ты молодец, потратил время впустую и прошел игру!" << endl;
            saveGame(data);
            system("clear");
    }
    cout << "выбери направление, куда хочешь пойти: " << endl;
    cout << "1. пойти налево" << endl;
    cout << "2. пойти направо" << endl;
}

void Kvest(Data& data) {
    switch (data.Killmobs) {
        case 5:
            cout << "Ты выполнил первый квест! " << endl;
            NPC(data);
            break;
        case 10:
            cout << "Ты выполнил второй квест! " << endl;
            NPC(data);
            break;
        case 15:
            cout << "Ты выполнил третий квест! " << endl;
            NPC(data);
            break;
    }
}

void Status(Data data) {
    cout << "==============СТАТУС==============" << endl;
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
    cout << "|1. Новая игра             |" << endl;
    cout << "|2. Продолжить             |" << endl;
    cout << "|3. Выход                  |" << endl;
    cout << "|==========================|" << endl;
    cout << "Выберите пункт меню: ";
}

// Модифицированная функция битвы с учетом локаций
void battle(Data& data, LocationType locationType) {
    const Location& location = locations[locationType];
    
    cout << "\n======================================" << endl;
    cout << "Вы прибыли в локацию: " << location.name << endl;
    cout << location.description << endl;
    cout << "======================================\n" << endl;

    int damage = 0;
    int mobsHP = rand() % 50 + 30;
    string mob = getRandomEnemy(locationType);
    cout << "На тебя напал " << mob << " из локации " << location.name << "!" << endl;

    while (mobsHP > 0 && data.hp > 0) {
        cout << "Твое здоровье: " << data.hp << "               " << "Здоровье врага: " << mobsHP <<endl;
        cout << "" << endl;
        cout << "1. Атаковать" << endl;
        cout << "2. Сбежать (шанс 50%)" << endl;
        cout << "3. Выйти и сохранить" << endl;

        int var;
        cin >> var;
        
        if (var == 3) {
            saveGame(data);
            return;
        }
        
        if (var == 1) {
            switch (data.gun) {
                case 0:
                    damage = rand() % 14 + 5;
                    break;
                case 1:
                    damage = rand() % 25 + 10;
                    break;
                case 2:
                    damage = rand() % 20 + 20;
                    break;
                default:
                    cout << "Ошибка, выберите существующий вариант действия" << endl;
                    continue;  // возврат на начало цикла
            }
            
            mobsHP -= damage;
            cout << "Ты нанес " << damage << " урона" << endl;
            
            if (mobsHP <= 0) {
                cout << "Ты победил врага в локации " << location.name << "!" << endl;
                int reward = rand() % 50 + 10;
                data.gold += reward;
                data.Killmobs++;
                cout << "Ты получил " << reward << " золота!" << endl;
                Kvest(data); // проверка квеста
                return;
            }
            
            int mobDamage = rand() % 10 + 10;
            data.hp -= mobDamage;
            cout << mob << " атаковал и нанес " << mobDamage << " урона" << endl;
            
            if (data.hp <= 0) {
                cout << "Смертельный урон, ты проиграл в локации " << location.name << endl;
                cout << "1. Загрузить последнее сохранение" << endl;
                cout << "2. Выйти в главное меню" << endl;
                cin >> var;
                
                if (var == 1) {
                    loadGame(data);
                    cout << "Игра загружена." << endl;
                    return;
                } else {
                    return;
                }
            }
        } else if (var == 2) {
            if (rand() % 2 == 0) {
                cout << "Удалось сбежать из " << location.name << endl;
                return;
            } else {
                cout << "Не удалось сбежать из " << location.name << ", бой продолжается" << endl;
                int mobDamage = rand() % 20 + 10;
                data.hp -= mobDamage;
                cout << "Ты получил " << mobDamage << " урона" << endl;
                
                if (data.hp <= 0) {
                    cout << "Смертельный урон, ты проиграл в локации " << location.name << endl;
                    cout << "1. Загрузить последнее сохранение" << endl;
                    cout << "2. Выйти в главное меню" << endl;
                    cin >> var;
                    
                    if (var == 1) {
                        loadGame(data);
                        cout << "Игра загружена." << endl;
                        return;
                    } else {
                        return;
                    }
                }
            }
        }
    }
}

void Shop(Data& data) {
    cout << "\n======================================" << endl;
    cout << "Ты встретил на пути магазин" << endl;
    cout << "Торговец: Привет путник, что желаешь приобрести?" << endl;
    cout << "======================================" << endl;
    cout << "1. Зелье восстановления здоровья (20 HP) - 30g" << endl;
    cout << "2. Меч (урон: 20-40) - 100g" << endl;
    cout << "3. Лук (урон: 10-35) - 70g" << endl;
    cout << "4. Выход" << endl;

    int var;
    cin >> var;

    switch (var) {
        case 1:
            if (data.gold >= 30) {
                if (data.hp == 100) {
                    cout << "Ваше здоровье полное, нельзя восстановить" << endl;
                } else {
                    data.hp = min(100, data.hp + 20);
                    data.gold -= 30;
                    cout << "Вы выпили зелье здоровья. Теперь у вас " << data.hp << " HP" << endl;
                }
            } else {
                cout << "Недостаточно золота! Нужно 30 золота." << endl;
            }
            break;
        case 2:
            if (data.gold >= 100) {
                data.gun = 2;
                data.gold -= 100;
                cout << "Вы купили меч! Теперь ваше оружие - меч" << endl;
            } else {
                cout << "Недостаточно золота! Нужно 100 золота." << endl;
            }
            break;
        case 3:
            if (data.gold >= 70) {
                data.gun = 1;
                data.gold -= 70;
                cout << "Вы купили лук! Теперь ваше оружие - лук" << endl;
            } else {
                cout << "Недостаточно золота! Нужно 70 золота." << endl;
            }
            break;
        case 4:
            cout << "Вы вышли из магазина." << endl;
            return;
        default:
            cout << "Ошибка, выберите существующий вариант действия" << endl;
            Shop(data);
            return;
    }
    
    // выбор локи после магаза
    LocationType randomLoc = getRandomLocation();
    battle(data, randomLoc);
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned int>(time(0))); //рандомайзер чисел
    initLocations();

    int num = 0;
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
                playerData.gold = 50;
                playerData.Killmobs = 0;
                playerData.gun = 0;

                NPC(playerData);
                int doroga;
                cin >> doroga;
                
                if (doroga == 1 || doroga == 2) {
                    LocationType randomLocation = getRandomLocation();
                    battle(playerData, randomLocation);
                } else {
                    cout << "Есть только две дороги!" << endl;
                }
                break;
            }
            case 2: {
                
            }
            case 3: {
                cout << "Выход из игры..." << endl;
                return 0;
            }
            default:
                cout << "Ошибка, такого пункта меню не существует" << endl;
                break;
        }

        // окно выбора после битвы
        cout << "\n======================================" << endl;
        int choice;
        cout << "Куда дальше?" << endl;
        cout << "1. Проверить статус" << endl;
        cout << "2. Пойти дальше (новая случайная локация)" << endl;
        cout << "3. Зайти в магазин" << endl;
        cout << "4. Сохранить и выйти в главное меню" << endl;
        cout << "======================================" << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                Status(playerData);
                break;
            case 2: {
                // нова я рандом лока
                LocationType randomLocation = getRandomLocation();
                battle(playerData, randomLocation);
                break;
            }
            case 3:
                Shop(playerData);
                break;
            case 4:
                saveGame(playerData);
                continue; //главное меню
            default:
                cout << "Неверный выбор" << endl;
        }
    }

    return 0;
}
