#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> // для rand
#include <ctime>   // для time

using namespace std;

class Character { // класс персонажа с стандартным набором характеристик
public:
    Character(const string& name = "", int hp = 100, int gold = 0, int gun = 0, int killmobs = 0)
        : name(name), hp(hp), gold(gold), gun(gun), killmobs(killmobs) {}

    void displayStats() const { // характеристики на экране
        cout << "Имя: " << name << endl;
        cout << "Здоровье: " << hp << endl;
        cout << "Золото: " << gold << endl;
        cout << "Уровень оружия: " << gun << endl;
        cout << "Убито мобов: " << killmobs << endl;
    }

    string getName() const { return name; }
    int getHp() const { return hp; }
    int getGold() const { return gold; }
    int getGun() const { return gun; }
    int getKillmobs() const { return killmobs; }

    void setHp(int newHp) { hp = newHp; }
    void addGold(int amount) { gold += amount; }
    void incrementKillmobs() { killmobs++; }

    void saveToFile(const string& filename) const {
        ofstream saveFile(filename);
        if (saveFile.is_open()) {
            saveFile << name << endl;
            saveFile << hp << endl;
            saveFile << gold << endl;
            saveFile << killmobs << endl;
            saveFile << gun << endl;
            saveFile.close();
            cout << "Игра была сохранена!" << endl;
        }
    }

    bool loadFromFile(const string& filename) {
        ifstream saveFile(filename);
        if (saveFile.is_open()) {
            getline(saveFile, name);
            saveFile >> hp;
            saveFile >> gold;
            saveFile >> killmobs;
            saveFile >> gun;
            saveFile.close();
            return true;
        }
        return false;
    }

private:
    string name;
    int hp;
    int gold;
    int gun;
    int killmobs;
};

class Game {
public:
    Game() {
        srand(static_cast<unsigned int>(time(nullptr))); // инициализация генератора случайных чисел
        character = Character();
    }

    void start() {
        int choice;
        bool running = true;

        while (running) {
            printMenu();
            cin >> choice;

            switch (choice) {
            case 1:
                startNewGame();
                break;
            case 2:
                continueGame();
                break;
            case 3:
                running = false;
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Ошибка: такого пункта меню не существует." << endl;
            }
        }
    }

private:
    Character character;

    void printMenu() {
        cout << "|===========МЕНЮ===========|" << endl;
        cout << "|1. Новая игра             |" << endl;
        cout << "|2. Продолжить             |" << endl;
        cout << "|3. Выход                  |" << endl;
        cout << "|==========================|" << endl;
        cout << "Выберите пункт меню: ";
    }

    void startNewGame() {
        string name;
        cout << "Введите имя персонажа: ";
        cin >> name;
        character = Character(name); // Сброс характеристик
        character.displayStats();
        cout << "Нажмите Enter, чтобы продолжить...";
        cin.ignore();
        cin.get();
    }

    void continueGame() {
        if (character.loadFromFile("savegame.txt")) {
            cout << "Игра загружена." << endl;
            character.displayStats();
            battle();
        } else {
            cout << "Не удалось загрузить играл, начните новую игру." << endl;
        }
    }

    void battle() {
        int damage;
        int mobsHP = rand() % 50 + 30;
        string mobs[6] = { "Слизень","Оборотень","Огр","Орк","Скелет","призрак" };
        string mob = mobs[rand() % 6];
        cout << "На тебя напал " << mob << endl;

        while (mobsHP > 0 && character.getHp() > 0) {
            cout << "Твое здоровье: " << character.getHp() << endl;
            cout << "Здоровье врага: " << mobsHP << endl;
            cout << "1. Атаковать" << endl;
            cout << "2. Сбежать (шанс 50%)" << endl;
            cout << "3. Выйти и сохранить" << endl;

            int var;
            cin >> var;
            if (var == 3) {
                character.saveToFile("savegame.txt");
                return;
            }

            if (var == 1) {
                damage = rand() % 10 + 5 + character.getGun() * 5; // Урон зависит от уровня оружия
                mobsHP -= damage;
                cout << "Ты нанес " << damage << " урона" << endl;
            } else if (var == 2) {
                if (rand() % 2 == 0) {
                    cout << "Удалось сбежать!" << endl;
                    return;
                } else {
                    cout << "Не удалось сбежать, бой продолжается." << endl;
                    int mobDamage = rand() % 20 + 10;
                    character.setHp(character.getHp() - mobDamage);
                    cout << "Ты получил " << mobDamage << " урона" << endl;
                }
            }

            if (character.getHp() <= 0) {
                cout << "Смертельный урон, ты проиграл" << endl;
                cout << "1. Загрузить последнее сохранение" << endl;
                cout << "2. Выйти в главное меню" << endl;
                cin >> var;
                if (var == 1) {
                    character.loadFromFile("savegame.txt");
                    cout << "Игра загружена." << endl;
                } else {
                    printMenu();
                }
            } else if (mobsHP <= 0) {
                cout << "Ты победил!" << endl;
                int revard = rand() % 50 + 10;
                character.addGold(revard);
                character.incrementKillmobs();
                cout << "Ты получил " << revard << " золота!" << endl;
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Game game;
    game.start();

    return 0;
}
