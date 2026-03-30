#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

struct Data {
    string name;
    int hp=100;
    int gold=30;
    int gun=0;
    int Killmobs=0;
};

struct Location {
    string name;
    string description;
    vector<string> enemies;
};

enum LocationType {
    FOREST,
    CAVE,
    SWAMP,
    RUINS,
    MOUNT,
    COUNT
};

enum BattleResult {
    BATTLE_FINISHED,
    BACK_TO_MENU
};

map<LocationType, Location> locations;

void initLocations() {
    locations[FOREST] = {
        "Лес",
        "Густой лес с высокими деревьями и таинственными звуками",
        {"Лесной тролль", "Оборотень", "Гоблин", "Паук-гигант"}
    };

    locations[CAVE] = {
        "Пещера",
        "Темная и сырая пещера с капающей водой",
        {"Летучая мышь", "Гоблин", "Каменный голем", "Подземный червь"}
    };

    locations[SWAMP] = {
        "Болото",
        "Гнилостное болото с туманом и странными огоньками",
        {"Болотный тролль", "Гигантская пиявка", "Болотный дух", "Крокодил"}
    };

    locations[RUINS] = {
        "Руины",
        "Древние руины когда-то великого города",
        {"Скелет", "Призрак", "Архитектор руин", "Древний страж"}
    };

    locations[MOUNT] = {
        "Горы",
        "Высокие заснеженные горы с опасными тропами",
        {"Снежный йети", "Горный тролль", "Хищный орел", "Ледяной элементаль"}
    };
}

LocationType getRandomLocation() {
    return static_cast<LocationType>(rand() % COUNT);
}

string getRandomEnemy(LocationType location) {
    const vector<string>& enemies = locations[location].enemies;
    return enemies[rand() % enemies.size()];
}

void saveGame(Data& data) {
    ofstream saveFile("savegame.json");

    if (saveFile.is_open()) {
        saveFile << data.name << endl;
        saveFile << data.hp << endl;
        saveFile << data.gold << endl;
        saveFile << data.Killmobs << endl;
        saveFile << data.gun << endl;
        saveFile.close();
        cout << "Игра была сохранена!" << endl;
    }
    else {
        cout << "Ошибка сохранения игры!" << endl;
    }
}

bool loadGame(Data& data) {
    ifstream saveFile("savegame.json");

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
    cout << endl;

    switch (data.Killmobs) {
    case 0:
        cout << "Твое первое задание - убить 5 монстров" << endl;
        break;
    case 5:
        cout << "Ты выполнил первое задание!" << endl;
        cout << "Новое задание - убить 10 монстров" << endl;
        break;
    case 10:
        cout << "Ты выполнил второе задание!" << endl;
        cout << "Новое задание - убить 15 монстров" << endl;
        break;
    case 15:
        cout << "Ты молодец, потратил время впустую и прошел игру!" << endl;
        saveGame(data);
        break;
    }

    cout << "Выбери направление, куда хочешь пойти:" << endl;
    cout << "1. Пойти налево" << endl;
    cout << "2. Пойти направо" << endl;
}

void Kvest(Data& data) {
    switch (data.Killmobs) {
    case 5:
    case 10:
    case 15:
        NPC(data);
        break;
    }
}

void Status(const Data& data) {
    cout << "============== СТАТУС ==============" << endl;
    cout << "Персонаж: " << data.name << endl;
    cout << "Здоровье: " << data.hp << endl;
    cout << "Золото: " << data.gold << endl;
    cout << "Убито монстров: " << data.Killmobs << endl;

    switch (data.gun) {
    case 0:
        cout << "Оружие: Без оружия" << endl;
        break;
    case 1:
        cout << "Оружие: Лук" << endl;
        break;
    case 2:
        cout << "Оружие: Меч" << endl;
        break;
    default:
        cout << "Оружие: Неизвестно" << endl;
        break;
    }

    cout << "====================================" << endl;
}

void What() {
    cout << "\n======================================" << endl;
    cout << "Куда дальше?" << endl;
    cout << "1. Проверить статус" << endl;
    cout << "2. Пойти дальше (новая случайная локация)" << endl;
    cout << "3. Зайти в магазин" << endl;
    cout << "4. Сохранить и выйти в главное меню" << endl;
    cout << "======================================" << endl;
}

void PrintMenu() {
    cout << "|=========== МЕНЮ ===========|" << endl;
    cout << "|1. Новая игра               |" << endl;
    cout << "|2. Продолжить               |" << endl;
    cout << "|3. Выход                    |" << endl;
    cout << "|============================|" << endl;
    cout << "Выберите пункт меню: ";
}

// функция возвращает BattleResult что бы можно было нормально выйти в меню
BattleResult battle(Data& data, LocationType locationType) {
    const Location& location = locations[locationType];

    cout << "\n======================================" << endl;
    cout << "Вы прибыли в локацию: " << location.name << endl;
    cout << location.description << endl;
    cout << "======================================\n" << endl;

    int damage = 0;
    int mobsHP = rand() % 50 + 30;
    string mob = getRandomEnemy(locationType);

    cout << "На тебя напал " << mob << "!" << endl;

    while (mobsHP > 0 && data.hp > 0) {
        cout << "\nТвое здоровье: " << data.hp
            << " | Здоровье врага: " << mobsHP << endl;
        cout << "1. Атаковать" << endl;
        cout << "2. Сбежать (шанс 50%)" << endl;
        cout << "3. Выйти и сохранить" << endl;

        int var;
        cin >> var;

        if (var == 3) {
            saveGame(data);
            return BACK_TO_MENU;
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
                cout << "Ошибка: неизвестное оружие!" << endl;
                continue;
            }
            if (data.hp > 0) {
                saveGame(data);
            }

            mobsHP -= damage;
            cout << "Ты нанес " << damage << " урона." << endl;

            if (mobsHP <= 0) {
                cout << "Ты победил врага в локации " << location.name << "!" << endl;
                int reward = rand() % 50 + 10;
                data.gold += reward;
                data.Killmobs++;
                cout << "Ты получил " << reward << " золота!" << endl;
                Kvest(data);
                return BATTLE_FINISHED;
            }

            int mobDamage = rand() % 10 + 10;
            data.hp -= mobDamage;
            cout << mob << " атаковал и нанес " << mobDamage << " урона." << endl;

            if (data.hp <= 0) {
                data.hp = 0;
                cout << "Смертельный урон, ты проиграл в локации " << location.name << endl;
                cout << "1. Загрузить последнее сохранение" << endl;
                cout << "2. Выйти в главное меню" << endl;
                cin >> var;

                if (var == 1) {
                    if (loadGame(data)) {
                        cout << "Игра загружена." << endl;
                    }
                    else {
                        cout << "Сохранение не найдено!" << endl;
                    }
                    return BATTLE_FINISHED;
                }
                else {
                    return BACK_TO_MENU;
                }
            }
        }
        else if (var == 2) {
            if (rand() % 2 == 0) {
                cout << "Удалось сбежать из " << location.name << endl;
                return BATTLE_FINISHED;
            }
            else {
                cout << "Не удалось сбежать из " << location.name << ", бой продолжается." << endl;
                int mobDamage = rand() % 20 + 10;
                data.hp -= mobDamage;
                cout << "Ты получил " << mobDamage << " урона." << endl;

                if (data.hp <= 0) {
                    cout << "Смертельный урон, ты проиграл в локации " << location.name << endl;
                    cout << "1. Загрузить последнее сохранение" << endl;
                    cout << "2. Выйти в главное меню" << endl;
                    cin >> var;

                    if (var == 1) {
                        if (loadGame(data)) {
                            cout << "Игра загружена." << endl;
                        }
                        else {
                            cout << "Сохранение не найдено!" << endl;
                        }
                        return BATTLE_FINISHED;
                    }
                    else {
                        return BACK_TO_MENU;
                    }
                }
            }
        }
        else {
            cout << "Ошибка, выберите существующий вариант действия." << endl;
        }
    }

    return BATTLE_FINISHED;
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
                cout << "Ваше здоровье полное, нельзя восстановить." << endl;
            }
            else {
                data.hp = min(100, data.hp + 20);
                data.gold -= 30;
                cout << "Вы выпили зелье здоровья. Теперь у вас " << data.hp << " HP." << endl;
            }
        }
        else {
            cout << "Недостаточно золота! Нужно 30 золота." << endl;
            BattleResult battle(Data & data, LocationType locationType);
        }
        break;

    case 2:
        if (data.gold >= 100) {
            data.gun = 2;
            data.gold -= 100;
            cout << "Вы купили меч! Теперь ваше оружие - меч." << endl;
        }
        else {
            cout << "Недостаточно золота! Нужно 100 золота." << endl;
            BattleResult battle(Data & data, LocationType locationType);
        }
        break;

    case 3:
        if (data.gold >= 70) {
            data.gun = 1;
            data.gold -= 70;
            cout << "Вы купили лук! Теперь ваше оружие - лук." << endl;
        }
        else {
            cout << "Недостаточно золота! Нужно 70 золота." << endl;
            BattleResult battle(Data & data, LocationType locationType);
        }
        break;

    case 4:
        cout << "Вы вышли из магазина." << endl;
        return;

    default:
        cout << "Ошибка, выберите существующий вариант действия." << endl;
        return;
    }
}

void gameLoop(Data& playerData) {
    bool backToMainMenu = false;

    while (!backToMainMenu) {
        What();

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            Status(playerData);
            break;

        case 2: {
            LocationType randomLocation = getRandomLocation();
            BattleResult result = battle(playerData, randomLocation);

            if (result == BACK_TO_MENU) {
                backToMainMenu = true;
            }
            break;
        }

        case 3:
            Shop(playerData);
            break;

        case 4:
            saveGame(playerData);
            backToMainMenu = true;
            break;

        default:
            cout << "Неверный выбор." << endl;
            break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned int>(time(0)));
    initLocations();

    int num = 0;
    Data playerData;

    while (true) {
        system("cls");
        //system("clear");
        PrintMenu();
        cin >> num;
        //while (!(cin >> num)) {
        //    cout << "Введите число!" << endl;
        //    cin.clear();

        //    cin.ignore(numeric_limits<streamsize>::max());
        //}
        switch (num) {
        case 1: {
            cout << "Придумай имя персонажа: ";
            cin >> playerData.name;

            playerData.hp = 100;
            playerData.gold = 10;
            playerData.Killmobs = 0;
            playerData.gun = 0;

            NPC(playerData);

            int doroga;
            cin >> doroga;

            if (doroga == 1 || doroga == 2) {
                LocationType randomLocation = getRandomLocation();
                BattleResult result = battle(playerData, randomLocation);

                if (result == BACK_TO_MENU) {
                    break;
                }

                gameLoop(playerData);
            }
            else {
                cout << "Есть только две дороги!" << endl;
            }

            break;
        }

        case 2: {
            if (loadGame(playerData)) {
                cout << "Игра загружена!" << endl;
                gameLoop(playerData);
            }
            else {
                cout << "Сохранение не найдено!" << endl;
            }
            break;
        }

        case 3: {
            cout << "Выход из игры..." << endl;
            return 0;
        }

        default:
            cout << "Ошибка, такого пункта меню не существует." << endl;
            break;
        }
    }

    return 0;
}

