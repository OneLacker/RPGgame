#include <iostream>
#include <string>

using namespace std;

class Character { // класс персонажа с стандартным набором характеристик
public:
    Character(int xp = 100, int money = 50, int weapon = 1)
        : xp(xp), money(money), weapon(weapon) {}

    void displayStats() const { // характеристики на экране
        cout << "XP: " << xp << endl;
        cout << "Money: " << money << endl;
        cout << "Weapon: " << weaponToString() << endl;
    }

    int getXp() const { return xp; }
    int getMoney() const { return money; }
    int getWeapon() const { return weapon; }
    string getWeaponToString() const {
        switch (weapon) {
            case 1: return "Без оружия";
            case 2: return "Лук";
            case 3: return "Меч";
            default: return "Неизвестно";
        }
    }

private:
    int xp;
    int money;
    int weapon;

    string weaponToString() const {
        switch (weapon) {
            case 1: return "Без оружия";
            case 2: return "Лук";
            case 3: return "Меч";
            default: return "Неизвестно";
        }
    }
};

void PrintMenu() {
    cout << "|===========МЕНЮ===========|" << endl;
    cout << "|1. Новая игра             |" << endl;
    cout << "|2. Продолжить             |" << endl;
    cout << "|3. Выход                  |" << endl;
    cout << "|==========================|" << endl;
    cout << "Выберите пункт меню: ";
}

void PrintDialog(const Character& player) {
    cout << "+--------------------------+--------------------------+" << endl;
    cout << "|      Диалог              |      Характиристики      |" << endl;
    cout << "|--------------------------|--------------------------|" << endl;
    cout << "| Вы начали новую игру!    | XP:      " << player.getXp() << "             |" << endl;
    cout << "|                          | Money:   " << player.getMoney() << "              |" << endl;
    cout << "|                          | Weapon:  " << player.getWeaponToString() << "          |" << endl;
    cout << "+--------------------------+--------------------------+" << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    Character player;
    int num = 0;

    while (true) {
        system("clear");
        PrintMenu();
        cin >> num;

        switch (num) {
        case 1: {
            PrintDialog(player); //окно диалогов
            cout << "Нажмите Enter, чтобы продолжить";
            cin.ignore();
            cin.get();
            break;
        }
        case 2: {
            PrintDialog(player);
            cout << "Нажмите Enter, чтобы продолжить";
            cin.ignore();
            cin.get();
            cout << "Вы продолжаете игру." << endl;
            break;
        }
        case 3: {
            cout << "Выход из программы." << endl;
            return 0;
        }
        default:
            cout << "Ошибка: такого пункта меню не существует." << endl;
        }
    }

    return 0;
}
