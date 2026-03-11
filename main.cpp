#include <iostream>
#include <string>

using namespace std;

class Character {
public:
    Character(int xp = 100, int money = 50, int weapon = 1)
        : xp(xp), money(money), weapon(weapon) {}

    void displayStats() const {
        cout << "XP: " << xp << endl;
        cout << "Money: " << money << endl;
        cout << "Weapon: " << weaponToString() << endl;
    }

private:
    int xp;
    int money;
    int weapon;

    string weaponToString() const {
        switch (weapon) {
            case 1: return "Ничего";
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
            player = Character();
            player.displayStats();
            break;
        }
        case 2: {
            player.displayStats();
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
