# Документация к игре "RPGgame"
Это документация для игры написанной на C++. Эта игра позволяет игроку путешествовать по различным локациям, сражаться с монстрами, выполнять квесты, покупать предметы в магазине и сохранять свой прогресс. Документация предназначена для разработчиков и пользователей, желающих понять структуру и функциональность игры. 
## Оглавление
- Обзор игры
- Требования
- Установка и запуск
- Основные компоненты
- Структура данных
- Основные функции
- Игровой процесс
- Сохранение и загрузка
- Как внести изменения
- Лицензия
## Обзор игры
Игра представляет собой текстовую RPG, где игрок выбирает действия через консольный интерфейс.

Основные механики включают:
- Создание персонажа с уникальным именем.
- Исследование случайных локаций (лес, пещера, болото, руины, горы).
- Бои с монстрами с возможностью атаки или побега.
- Выполнение квестов от NPC (например, убить определенное количество монстров).
- Покупка оружия и зелий в магазине.
- Сохранение и загрузка прогресса.
- Цель игры — выполнить все квесты (убить 15 монстров) и выжить в опасном мире.

## Требования
1. Для запуска игры необходимы:
- Компилятор C++ (например, g++).
- Операционная система с поддержкой консольных приложений (Windows, Linux, macOS).
## Установка и запуск:
- Склонируйте репозиторий или скачайте исходный код.
- Скомпилируйте код с помощью компилятора C++:
- g++ game.cpp -o game

Запустите игру:

- На Windows: game.exe
- На Linux/macOS: ./game
- Следуйте инструкциям в консоли для выбора действий.

Примечание: Игра использует локализацию на русском языке, поэтому убедитесь, что ваша консоль поддерживает отображение кириллицы (setlocale(LC_ALL, "ru") в коде).

## Основные компоненты
Игра состоит из нескольких ключевых модулей:

- Меню: Главное меню для старта новой игры, продолжения или выхода.
- Локации: Различные зоны с уникальными врагами и описаниями.
- Боевая система: Сражения с монстрами с возможностью атаки или побега.
- Магазин: Покупка оружия и зелий за золото.
- Система сохранений: Сохранение и загрузка прогресса игрока.
- Квесты: Задания от NPC для продвижения по игре.
## Структура данных
1. Структура Data
Хранит информацию о персонаже игрока:
```cpp
struct Data {
    string name;        // Имя персонажа
    int hp;       // Здоровье (по умолчанию 100)
    int gold;      // Золото (валюта игры)
    int gun;        // Тип оружия (0 - без оружия, 1 - лук, 2 - меч, 3 - боевой топор)
    int Killmobs;   // Количество убитых монстров
};
```
2. Структура Location
Описывает локацию в игре:
```cpp
struct Location {
    string name;                // Название локации
    string description;         // Описание локации
    vector<string> enemies;     // Список возможных врагов
};
```
3. Перечисления
```cpp
LocationType: Типы локаций (FOREST, CAVE, SWAMP, RUINS, MOUNT).
BattleResult: Результат боя (BATTLE_FINISHED, BACK_TO_MENU).
```
## Основные функции
1. initLocations()
- Инициализирует все локации с их описаниями и списками врагов.

2. battle(Data& data, LocationType locationType)
Управляет боем с монстром в выбранной локации:

- Выводит информацию о локации и враге.
- Позволяет игроку атаковать или попытаться сбежать.
- Возвращает результат боя (продолжение игры или возврат в меню).
3. Shop(Data& data)
Открывает магазин:
``` cpp
void Shop(Data& data) {
    cout << "\n======================================" << endl;
    cout << "Ты встретил на пути магазин" << endl;
    cout << "Торговец: Привет путник, что желаешь приобрести?" << endl;
    cout << "======================================" << endl;
    cout << "У тебя есть " << data.gold << " золота." << endl;
    cout << "1. Большое зелье восстановления здоровья (35 HP) - 40g" << endl;
    cout << "2. Среднее зелье восстановления здоровья (25 HP) - 30g" << endl;
    cout << "3. Малое зелье восстановления здоровья (15 HP) - 20g " << endl;
    cout << "4. Боевой топор (урон: 30-40) - 120g" << endl;
    cout << "5. Меч (урон: 20-30) - 80g" << endl;
    cout << "6. Лук (урон: 10-15) - 50g" << endl;
    cout << "7. Выход" << endl;
```
4. saveGame(Data& data) и loadGame(Data& data)
Сохраняют и загружают прогресс игрока в файл savegame.txt.

5. gameLoop(Data& playerData)
Основной цикл игры, предоставляющий выбор действий:

- Проверка статуса.
- ереход в новую локацию.
- Посещение магазина.
- Сохранение и выход в меню.
6. NPC(Data& data) и Kvest(Data& data)
Управляют квестами, выдаваемыми NPC.
- Цель — убить 5, 10 и 15 монстров для завершения игры.

## Игровой процесс
1. Старт игры:
- Выберите "Новая игра" или "Продолжить" в главном меню.
- При новой игре введите имя персонажа.
2. Исследование:
- Игрок выбирает направление (налево или направо) и попадает в случайную локацию.
- В локации может начаться бой с монстром.
3. Бой:
- Выберите "Атаковать" или "Сбежать" (шанс 50%).
- Урон зависит от оружия игрока.
- При победе игрок получает золото и прогресс в квесте.
4. Магазин и квесты:
- Покупайте предметы в магазине за золото.
- Выполняйте задания NPC, чтобы завершить игру.
5. Сохранение и выход:
- Сохраняйте прогресс в любой момент и возвращайтесь в меню.
- Сохранение и загрузка
- Сохранение записывает данные персонажа (имя, здоровье, золото, оружие, убитые монстры) в файл savegame.txt.
- Загрузка восстанавливает данные из файла. Если файл отсутствует, игроку предлагается начать новую игру.

Важно: Убедитесь, что файл сохранения находится в той же директории, что и исполняемый файл игры.

## Над проектом трудились:
- [KAVINSKII](https://github.com/OneLacker) - Программист, разработал систему локаций, а также часть боевой системы. Также учавствовал в остальном процессе разработки.
- [vlozx](https://github.com/vlozxxx) - Программист, разработал большую часть боевой системы, сохранений и загрузки сохранений. Также учавствовал в остальном процессе разработки.
- [toormann](https://github.com/toormann-code) - Главный тестировщик, проводил тесты на протяжении всего создания проекта. Также учавствовал в остальном процессе разработки и корректировал логику кода.

### Лицензия
**Этот проект распространяется под лицензией MIT. Вы можете свободно использовать, модифицировать и распространять код при условии указания авторства.**

Если у вас есть вопросы или предложения, создайте issue в репозитории или свяжитесь с автором.

Спасибо за интерес к игре! Путешествуйте, сражайтесь и побеждайте! 





Конечно! Я помогу вам превратить вашу консольную игру в приложение с графическим интерфейсом. Для простоты я буду использовать WinAPI (только для Windows), так как это минимальные изменения вашего кода.

Полный код игры с графическим интерфейсом

```cpp
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <windows.h>  // Для работы с окнами

using namespace std;

// ============== СТРУКТУРЫ ДАННЫХ (ваш код, почти без изменений) ==============

struct Data {
    string name;
    int hp = 100;
    int gold = 30;
    int gun = 0;
    int Killmobs = 0;
};

struct Location {
    string name;
    string description;
    vector<string> enemies;
};

enum LocationType {
    FOREST, CAVE, SWAMP, RUINS, MOUNT, COUNT
};

enum BattleResult {
    BATTLE_FINISHED, BACK_TO_MENU
};

map<LocationType, Location> locations;
Data playerData;

// ID элементов управления (кнопок, текстовых полей и т.д.)
#define ID_NEW_GAME    1001
#define ID_CONTINUE    1002
#define ID_EXIT        1003
#define ID_STATUS      1004
#define ID_GO_FIGHT    1005
#define ID_GO_SHOP     1006
#define ID_SAVE_EXIT   1007
#define ID_ATTACK      1008
#define ID_RUN         1009
#define ID_EXIT_BATTLE 1010
#define ID_SHOP_BUY1   1011
#define ID_SHOP_BUY2   1012
#define ID_SHOP_BUY3   1013
#define ID_SHOP_EXIT   1014
#define ID_NPC_LEFT    1015
#define ID_NPC_RIGHT   1016
#define ID_NAME_INPUT  1017
#define ID_NPC_CONFIRM 1018

// Глобальные переменные для состояния игры
HWND mainWindow;           // Главное окно
HWND currentDialog;        // Текущее диалоговое окно
HWND nameEdit;             // Поле ввода имени
LocationType currentLocation;  // Текущая локация
string currentEnemy;       // Текущий враг
int currentMobHP;          // Здоровье текущего врага
bool inBattle = false;     // В бою ли игрок

// ============== ФУНКЦИИ ИГРЫ (ваш код, адаптированный) ==============

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

void saveGame() {
    ofstream saveFile("savegame.json");
    if (saveFile.is_open()) {
        saveFile << playerData.name << endl;
        saveFile << playerData.hp << endl;
        saveFile << playerData.gold << endl;
        saveFile << playerData.Killmobs << endl;
        saveFile << playerData.gun << endl;
        saveFile.close();
        MessageBox(mainWindow, "Игра сохранена!", "Сохранение", MB_OK);
    }
    else {
        MessageBox(mainWindow, "Ошибка сохранения!", "Ошибка", MB_OK);
    }
}

bool loadGame() {
    ifstream saveFile("savegame.json");
    if (saveFile.is_open()) {
        getline(saveFile, playerData.name);
        saveFile >> playerData.hp;
        saveFile >> playerData.gold;
        saveFile >> playerData.Killmobs;
        saveFile >> playerData.gun;
        saveFile.close();
        return true;
    }
    return false;
}

string getNPCQuestText() {
    switch (playerData.Killmobs) {
    case 0:
        return "Твое первое задание - убить 5 монстров";
    case 5:
        return "Ты выполнил первое задание!\nНовое задание - убить 10 монстров";
    case 10:
        return "Ты выполнил второе задание!\nНовое задание - убить 15 монстров";
    case 15:
        return "Ты молодец, потратил время впустую и прошел игру!";
    default:
        return "Иди, убивай монстров!";
    }
}

string getStatusText() {
    string status = "Персонаж: " + playerData.name + "\n";
    status += "Здоровье: " + to_string(playerData.hp) + "\n";
    status += "Золото: " + to_string(playerData.gold) + "\n";
    status += "Убито монстров: " + to_string(playerData.Killmobs) + "\n";
    
    switch (playerData.gun) {
    case 0: status += "Оружие: Без оружия"; break;
    case 1: status += "Оружие: Лук"; break;
    case 2: status += "Оружие: Меч"; break;
    default: status += "Оружие: Неизвестно";
    }
    return status;
}

// ============== ФУНКЦИИ ДЛЯ СОЗДАНИЯ ОКОН ==============

// Функция для добавления текста в окно
void AddText(HWND hWnd, const string& text, int x, int y, int width, int height, int id) {
    CreateWindow("STATIC", text.c_str(), WS_VISIBLE | WS_CHILD,
                 x, y, width, height, hWnd, (HMENU)(INT_PTR)id, NULL, NULL);
}

// Функция для добавления кнопки
void AddButton(HWND hWnd, const string& text, int x, int y, int width, int height, int id) {
    CreateWindow("BUTTON", text.c_str(), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                 x, y, width, height, hWnd, (HMENU)(INT_PTR)id, NULL, NULL);
}

// Главное меню (окно с 3 кнопками)
HWND CreateMainMenu(HWND parent) {
    HWND hWnd = CreateWindow("STATIC", "", WS_VISIBLE | WS_CHILD,
                             0, 0, 400, 300, parent, NULL, NULL, NULL);
    
    AddButton(hWnd, "Новая игра", 125, 50, 150, 40, ID_NEW_GAME);
    AddButton(hWnd, "Продолжить", 125, 120, 150, 40, ID_CONTINUE);
    AddButton(hWnd, "Выход", 125, 190, 150, 40, ID_EXIT);
    
    return hWnd;
}

// Окно диалога с NPC (начало игры)
HWND CreateNPCDialog(HWND parent) {
    HWND hWnd = CreateWindow("STATIC", "", WS_VISIBLE | WS_CHILD,
                             0, 0, 400, 300, parent, NULL, NULL, NULL);
    
    AddText(hWnd, "Старец: Приветствую тебя, путник!", 20, 20, 360, 25, -1);
    AddText(hWnd, "Как тебя зовут?", 20, 50, 360, 25, -1);
    
    // Поле для ввода имени
    nameEdit = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER,
                            20, 80, 200, 25, hWnd, (HMENU)(INT_PTR)ID_NAME_INPUT, NULL, NULL);
    
    AddButton(hWnd, "Продолжить", 250, 80, 100, 25, ID_NPC_CONFIRM);
    
    return hWnd;
}

// Окно с квестами и выбором пути
HWND CreateQuestDialog(HWND parent) {
    HWND hWnd = CreateWindow("STATIC", "", WS_VISIBLE | WS_CHILD,
                             0, 0, 400, 300, parent, NULL, NULL, NULL);
    
    string questText = getNPCQuestText();
    AddText(hWnd, "Старец:", 20, 20, 360, 25, -1);
    AddText(hWnd, questText, 20, 50, 360, 50, -1);
    
    AddText(hWnd, "Выбери направление:", 20, 120, 360, 25, -1);
    AddButton(hWnd, "Пойти налево", 50, 160, 120, 40, ID_NPC_LEFT);
    AddButton(hWnd, "Пойти направо", 200, 160, 120, 40, ID_NPC_RIGHT);
    
    return hWnd;
}

// Окно игрового процесса (статус + кнопки)
HWND CreateGameDialog(HWND parent) {
    HWND hWnd = CreateWindow("STATIC", "", WS_VISIBLE | WS_CHILD,
                             0, 0, 400, 350, parent, NULL, NULL, NULL);
    
    AddButton(hWnd, "Проверить статус", 20, 20, 160, 40, ID_STATUS);
    AddButton(hWnd, "Пойти в бой", 200, 20, 160, 40, ID_GO_FIGHT);
    AddButton(hWnd, "Магазин", 20, 80, 160, 40, ID_GO_SHOP);
    AddButton(hWnd, "Сохранить и выйти", 200, 80, 160, 40, ID_SAVE_EXIT);
    
    return hWnd;
}

// Окно боя
HWND CreateBattleDialog(HWND parent) {
    inBattle = true;
    
    HWND hWnd = CreateWindow("STATIC", "", WS_VISIBLE | WS_CHILD,
                             0, 0, 400, 350, parent, NULL, NULL, NULL);
    
    string battleText = "Локация: " + locations[currentLocation].name + "\n";
    battleText += locations[currentLocation].description + "\n\n";
    battleText += "На тебя напал " + currentEnemy + "!\n";
    battleText += "Твое здоровье: " + to_string(playerData.hp) + "\n";
    battleText += "Здоровье врага: " + to_string(currentMobHP);
    
    AddText(hWnd, battleText, 20, 20, 360, 150, -1);
    
    AddButton(hWnd, "Атаковать", 20, 200, 100, 40, ID_ATTACK);
    AddButton(hWnd, "Сбежать (50%)", 140, 200, 100, 40, ID_RUN);
    AddButton(hWnd, "Выйти и сохранить", 260, 200, 100, 40, ID_EXIT_BATTLE);
    
    return hWnd;
}

// Обновление текста в окне боя
void UpdateBattleDialog(HWND hWnd) {
    string battleText = "Локация: " + locations[currentLocation].name + "\n";
    battleText += locations[currentLocation].description + "\n\n";
    battleText += "На тебя напал " + currentEnemy + "!\n";
    battleText += "Твое здоровье: " + to_string(playerData.hp) + "\n";
    battleText += "Здоровье врага: " + to_string(currentMobHP);
    
    SetWindowText(GetDlgItem(hWnd, -1), battleText.c_str());
}

// Окно магазина
HWND CreateShopDialog(HWND parent) {
    HWND hWnd = CreateWindow("STATIC", "", WS_VISIBLE | WS_CHILD,
                             0, 0, 400, 300, parent, NULL, NULL, NULL);
    
    AddText(hWnd, "Торговец: Привет путник, что желаешь?", 20, 20, 360, 25, -1);
    AddText(hWnd, "Твое золото: " + to_string(playerData.gold), 20, 50, 360, 25, -1);
    
    AddButton(hWnd, "Зелье (20 HP) - 30g", 50, 90, 130, 40, ID_SHOP_BUY1);
    AddButton(hWnd, "Меч (20-40 урон) - 100g", 200, 90, 150, 40, ID_SHOP_BUY2);
    AddButton(hWnd, "Лук (10-35 урон) - 70g", 50, 150, 130, 40, ID_SHOP_BUY3);
    AddButton(hWnd, "Выход", 200, 150, 150, 40, ID_SHOP_EXIT);
    
    return hWnd;
}

// Обновление окна магазина
void UpdateShopDialog(HWND hWnd) {
    SetWindowText(GetDlgItem(hWnd, -1), ("Твое золото: " + to_string(playerData.gold)).c_str());
}

// ============== ЛОГИКА БОЯ ==============

void StartBattle(LocationType loc) {
    currentLocation = loc;
    currentEnemy = getRandomEnemy(loc);
    currentMobHP = rand() % 50 + 30;
    
    // Закрываем старое окно и открываем окно боя
    DestroyWindow(currentDialog);
    currentDialog = CreateBattleDialog(mainWindow);
}

void Attack() {
    int damage = 0;
    switch (playerData.gun) {
    case 0: damage = rand() % 14 + 5; break;
    case 1: damage = rand() % 25 + 10; break;
    case 2: damage = rand() % 20 + 20; break;
    }
    
    currentMobHP -= damage;
    
    if (currentMobHP <= 0) {
        // Победа
        int reward = rand() % 50 + 10;
        playerData.gold += reward;
        playerData.Killmobs++;
        
        MessageBox(mainWindow, ("Ты победил!\nПолучено " + to_string(reward) + " золота!").c_str(), "Победа", MB_OK);
        
        // Проверка на выполнение квеста
        if (playerData.Killmobs == 5 || playerData.Killmobs == 10 || playerData.Killmobs == 15) {
            if (playerData.Killmobs == 15) {
                MessageBox(mainWindow, "Поздравляю! Ты прошел игру!", "Победа", MB_OK);
                saveGame();
                DestroyWindow(currentDialog);
                currentDialog = CreateMainMenu(mainWindow);
                inBattle = false;
                return;
            }
            
            MessageBox(mainWindow, getNPCQuestText().c_str(), "Новое задание", MB_OK);
        }
        
        // Возвращаемся в игровое окно
        DestroyWindow(currentDialog);
        currentDialog = CreateGameDialog(mainWindow);
        inBattle = false;
        return;
    }
    
    // Атака врага
    int mobDamage = rand() % 10 + 10;
    playerData.hp -= mobDamage;
    
    if (playerData.hp <= 0) {
        // Смерть
        int result = MessageBox(mainWindow, "Ты погиб!\nЗагрузить последнее сохранение?", "Поражение", MB_YESNO);
        if (result == IDYES) {
            if (loadGame()) {
                MessageBox(mainWindow, "Игра загружена!", "Загрузка", MB_OK);
                DestroyWindow(currentDialog);
                currentDialog = CreateGameDialog(mainWindow);
                inBattle = false;
            } else {
                MessageBox(mainWindow, "Сохранение не найдено!", "Ошибка", MB_OK);
                DestroyWindow(currentDialog);
                currentDialog = CreateMainMenu(mainWindow);
                inBattle = false;
            }
        } else {
            DestroyWindow(currentDialog);
            currentDialog = CreateMainMenu(mainWindow);
            inBattle = false;
        }
        return;
    }
    
    // Обновляем окно боя
    UpdateBattleDialog(currentDialog);
}

void Run() {
    if (rand() % 2 == 0) {
        MessageBox(mainWindow, "Удалось сбежать!", "Побег", MB_OK);
        DestroyWindow(currentDialog);
        currentDialog = CreateGameDialog(mainWindow);
        inBattle = false;
    } else {
        // Неудачный побег - враг атакует
        int mobDamage = rand() % 20 + 10;
        playerData.hp -= mobDamage;
        
        if (playerData.hp <= 0) {
            int result = MessageBox(mainWindow, "При побеге ты погиб!\nЗагрузить сохранение?", "Поражение", MB_YESNO);
            if (result == IDYES) {
                if (loadGame()) {
                    MessageBox(mainWindow, "Игра загружена!", "Загрузка", MB_OK);
                    DestroyWindow(currentDialog);
                    currentDialog = CreateGameDialog(mainWindow);
                    inBattle = false;
                } else {
                    MessageBox(mainWindow, "Сохранение не найдено!", "Ошибка", MB_OK);
                    DestroyWindow(currentDialog);
                    currentDialog = CreateMainMenu(mainWindow);
                    inBattle = false;
                }
            } else {
                DestroyWindow(currentDialog);
                currentDialog = CreateMainMenu(mainWindow);
                inBattle = false;
            }
            return;
        }
        
        MessageBox(mainWindow, ("Не удалось сбежать! Враг нанес " + to_string(mobDamage) + " урона.").c_str(), "Побег не удался", MB_OK);
        UpdateBattleDialog(currentDialog);
    }
}

// ============== ОБРАБОТЧИК СООБЩЕНИЙ ОКНА ==============

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        // Главное меню
        case ID_NEW_GAME:
            DestroyWindow(currentDialog);
            currentDialog = CreateNPCDialog(hwnd);
            break;
            
        case ID_CONTINUE:
            if (loadGame()) {
                DestroyWindow(currentDialog);
                currentDialog = CreateGameDialog(hwnd);
                MessageBox(hwnd, "Игра загружена!", "Загрузка", MB_OK);
            } else {
                MessageBox(hwnd, "Сохранение не найдено!", "Ошибка", MB_OK);
            }
            break;
            
        case ID_EXIT:
            PostQuitMessage(0);
            break;
            
        // Диалог NPC (ввод имени)
        case ID_NPC_CONFIRM:
            {
                char name[100];
                GetWindowText(nameEdit, name, 100);
                if (strlen(name) > 0) {
                    playerData.name = name;
                    playerData.hp = 100;
                    playerData.gold = 10;
                    playerData.Killmobs = 0;
                    playerData.gun = 0;
                    
                    DestroyWindow(currentDialog);
                    currentDialog = CreateQuestDialog(hwnd);
                } else {
                    MessageBox(hwnd, "Введите имя!", "Ошибка", MB_OK);
                }
            }
            break;
            
        // Выбор пути у NPC
        case ID_NPC_LEFT:
        case ID_NPC_RIGHT:
            DestroyWindow(currentDialog);
            currentDialog = CreateGameDialog(hwnd);
            break;
            
        // Игровое окно
        case ID_STATUS:
            MessageBox(hwnd, getStatusText().c_str(), "Статус", MB_OK);
            break;
            
        case ID_GO_FIGHT:
            StartBattle(getRandomLocation());
            break;
            
        case ID_GO_SHOP:
            DestroyWindow(currentDialog);
            currentDialog = CreateShopDialog(hwnd);
            break;
            
        case ID_SAVE_EXIT:
            saveGame();
            DestroyWindow(currentDialog);
            currentDialog = CreateMainMenu(hwnd);
            break;
            
        // Окно боя
        case ID_ATTACK:
            Attack();
            break;
            
        case ID_RUN:
            Run();
            break;
            
        case ID_EXIT_BATTLE:
            saveGame();
            DestroyWindow(currentDialog);
            currentDialog = CreateMainMenu(hwnd);
            inBattle = false;
            break;
            
        // Магазин
        case ID_SHOP_BUY1:
            if (playerData.gold >= 30) {
                if (playerData.hp == 100) {
                    MessageBox(hwnd, "Здоровье уже полное!", "Магазин", MB_OK);
                } else {
                    playerData.hp = min(100, playerData.hp + 20);
                    playerData.gold -= 30;
                    UpdateShopDialog(currentDialog);
                    MessageBox(hwnd, "Вы выпили зелье!", "Магазин", MB_OK);
                }
            } else {
                MessageBox(hwnd, "Недостаточно золота!", "Магазин", MB_OK);
            }
            break;
            
        case ID_SHOP_BUY2:
            if (playerData.gold >= 100) {
                playerData.gun = 2;
                playerData.gold -= 100;
                UpdateShopDialog(currentDialog);
                MessageBox(hwnd, "Вы купили меч!", "Магазин", MB_OK);
            } else {
                MessageBox(hwnd, "Недостаточно золота!", "Магазин", MB_OK);
            }
            break;
            
        case ID_SHOP_BUY3:
            if (playerData.gold >= 70) {
                playerData.gun = 1;
                playerData.gold -= 70;
                UpdateShopDialog(currentDialog);
                MessageBox(hwnd, "Вы купили лук!", "Магазин", MB_OK);
            } else {
                MessageBox(hwnd, "Недостаточно золота!", "Магазин", MB_OK);
            }
            break;
            
        case ID_SHOP_EXIT:
            DestroyWindow(currentDialog);
            currentDialog = CreateGameDialog(hwnd);
            break;
        }
        break;
        
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// ============== ГЛАВНАЯ ФУНКЦИЯ ==============

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned int>(time(0)));
    initLocations();
    
    // Регистрируем класс окна
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;      // Функция обработки сообщений
    wc.hInstance = hInstance;          // Экземпляр приложения
    wc.lpszClassName = "GameWindow";   // Имя класса окна
    
    RegisterClass(&wc);
    
    // Создаем главное окно
    mainWindow = CreateWindow("GameWindow", "RPG Game",
                              WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                              100, 100, 420, 380,
                              NULL, NULL, hInstance, NULL);
    
    // Создаем начальное окно с меню
    currentDialog = CreateMainMenu(mainWindow);
    
    // Цикл обработки сообщений
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}
```

Объяснение нового синтаксиса и кода

1. Подключение Windows.h

```cpp
#include <windows.h>
```

Это библиотека для создания окон в Windows. Она содержит все функции для работы с графическим интерфейсом.

2. Идентификаторы (ID)

```cpp
#define ID_NEW_GAME 1001
```

Каждая кнопка получает уникальный номер. Когда пользователь нажимает кнопку, Windows сообщает этот номер, и мы понимаем, какая кнопка нажата.

3. HWND - Handle to Window (Дескриптор окна)

```cpp
HWND mainWindow;
HWND currentDialog;
```

Это "паспорт" окна. Каждое окно в Windows имеет такой номер, по которому мы к нему обращаемся.

4. CreateWindow - создание элемента

```cpp
CreateWindow("BUTTON", "Новая игра", WS_VISIBLE | WS_CHILD,
             125, 50, 150, 40, hWnd, (HMENU)ID_NEW_GAME, NULL, NULL);
```

Параметры:

· "BUTTON" - тип элемента (кнопка)
· "Новая игра" - текст на кнопке
· WS_VISIBLE | WS_CHILD - стили (видимая, дочернее окно)
· 125, 50 - координаты X, Y
· 150, 40 - ширина, высота
· hWnd - родительское окно
· ID_NEW_GAME - идентификатор кнопки

5. Message Loop (Цикл сообщений)

```cpp
MSG msg;
while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
```

Windows работает на событиях. Когда пользователь что-то делает (нажимает кнопку, двигает мышь), Windows отправляет сообщение. Этот цикл получает сообщения и передаёт их нашей функции WindowProc.

6. WindowProc - обработчик сообщений

```cpp
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
```

Эта функция вызывается для каждого события:

· uMsg - тип события (WM_COMMAND - нажатие кнопки, WM_DESTROY - закрытие окна)
· wParam - содержит ID нажатой кнопки

7. MessageBox - всплывающее окно

```cpp
MessageBox(hwnd, "Текст", "Заголовок", MB_OK);
```

Показывает маленькое окно с сообщением.

8. DestroyWindow - закрытие окна

```cpp
DestroyWindow(currentDialog);
```

Закрывает окно и освобождает память.

Как работает программа:

1. WinMain - точка входа в программу (вместо main для оконных приложений)
2. Регистрируем класс окна
3. Создаём главное окно
4. Создаём меню с 3 кнопками
5. Запускаем цикл обработки сообщений

При нажатии кнопок:

· Новая игра → окно ввода имени → NPC с квестом → игровое окно
· Продолжить → загружаем сохранение → игровое окно
· Выход → закрываем программу

В игровом окне:

· Проверить статус → показывает характеристики
· Пойти в бой → начинается сражение
· Магазин → покупка предметов
· Сохранить и выйти → сохранение и выход в меню

В бою:

· Атаковать → наносим урон, враг отвечает
· Сбежать → 50% шанс убежать
· Выйти и сохранить → сохранение и выход

Как скомпилировать:

Если используете g++ (MinGW):

```bash
g++ game.cpp -o game.exe -lgdi32 -mwindows
```

Флаг -mwindows говорит компилятору, что это оконное приложение (не будет появляться консоль).

Если используете Visual Studio: просто создайте проект Windows Desktop Application и вставьте код.
