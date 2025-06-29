#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

const std::string FILE_NAME = "save.bin";

struct MathVector {
    int x = 0;
    int y = 0;
};

struct Person {
    std::string name = "unknown";
    int health = 0;
    int armor = 0;
    int damage = 0;
    MathVector mathVector;
    bool isPlayer = false;
};

void initialization(char array[][20]) {
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 20; ++j)
            array[i][j] =  '.';
}

void print(const char map[][20]) {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j)
            std::cout << map[i][j] << " ";
        std::cout << std::endl;
    }
}

void save_person(std::ofstream& file, Person& person) {
    int len = person.name.length();
    file.write(reinterpret_cast<char*>(&len), sizeof(len));
    file.write(person.name.c_str(), len);

    file.write(reinterpret_cast<char*>(&person.health), sizeof(person.health));
    file.write(reinterpret_cast<char*>(&person.armor), sizeof(person.armor));
    file.write(reinterpret_cast<char*>(&person.damage), sizeof(person.damage));
    file.write(reinterpret_cast<char*>(&person.mathVector.x), sizeof(person.mathVector.x));
    file.write(reinterpret_cast<char*>(&person.mathVector.y), sizeof(person.mathVector.y));
}

void load_person(std::ifstream& file, Person& person) {
    int len = person.name.length();
    file.read(reinterpret_cast<char*>(&len), sizeof(len));
    person.name.resize(len);
    //file.read(reinterpret_cast<char*>(person.name.c_str()), len);
    file.read((char*)person.name.c_str(), len);

    file.read(reinterpret_cast<char*>(&person.health), sizeof(person.health));
    file.read(reinterpret_cast<char*>(&person.armor), sizeof(person.armor));
    file.read(reinterpret_cast<char*>(&person.damage), sizeof(person.damage));
    file.read(reinterpret_cast<char*>(&person.mathVector.x), sizeof(person.mathVector.x));
    file.read(reinterpret_cast<char*>(&person.mathVector.y), sizeof(person.mathVector.y));
}

void take_damage(Person& person, int damage) {
    std::cout << std::endl;
    std::cout << person.name << " took damage: - " << damage << std::endl;
    person.armor -= damage;
    if (person.armor < 0) {
        person.health += person.armor;
        person.armor = 0;
    }
    std::cout << "armor: " << person.armor << std::endl;
    std::cout << "health: " << person.health << std::endl;
}

void checking_territory(char mapVisual[][20], Person& player, Person enemies[5]) {
    if (mapVisual[player.mathVector.x][player.mathVector.y] == 'E') {
        for (int i = 0; i < 5; ++i) {
            if (player.mathVector.x == enemies[i].mathVector.x &&
                player.mathVector.y == enemies[i].mathVector.y) {
                    take_damage(enemies[i], player.damage);
                    if (enemies[i].health <= 0) {
                        std::cout << enemies[i].name << " defeated!\n";
                        enemies[i].mathVector.x = -50;
                        enemies[i].mathVector.y = -50;
                        mapVisual[player.mathVector.x][player.mathVector.y] = 'P';
                    } else {
                        enemies[i].mathVector.x++;
                        mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] = 'E';
                        mapVisual[player.mathVector.x][player.mathVector.y] = 'P';
                    }
            }
        }
        
    } else if (mapVisual[player.mathVector.x][player.mathVector.y] == '.')
        mapVisual[player.mathVector.x][player.mathVector.y] = 'P';
}

void enemy_movement(Person enemies[5], char mapVisual[][20], Person& player) {
    for (int i = 0; i < 5; ++i) {
        if (enemies[i].mathVector.x == -50) i++;
        else if (enemies[i].mathVector.x < 0 || enemies[i].mathVector.x > 19 ||
                 enemies[i].mathVector.y < 0 || enemies[i].mathVector.y > 19) {
                    i++;
        } else {
            int direction = (std::rand() % 3) + 1;
            if (direction == 1) {
                mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] = '.';
                enemies[i].mathVector.y--;
                if (mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] == 'E')
                    continue;
                else if (mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] == 'P')
                    take_damage(player, enemies[i].damage);
                else
                    mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] = 'E';

            } else if (direction == 2) {
                mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] = '.';                
                enemies[i].mathVector.x++;
                if (mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] == 'E')
                    continue;
                else if (mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] == 'P')
                    take_damage(player, enemies[i].damage);
                else
                    mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] = 'E';
            
            } else if (direction == 3) {
                mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] = '.';                
                enemies[i].mathVector.y++;
                if (mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] == 'E')
                    continue;
                else if (mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] == 'P')
                    take_damage(player, enemies[i].damage);
                else
                    mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] = 'E';
            
            } else {
                mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] = '.';                
                enemies[i].mathVector.x--;
                if (mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] == 'E')
                    continue;
                else if (mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] == 'P')
                    take_damage(player, enemies[i].damage);
                else
                    mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] = 'E';
            }
        }
    }
}

int main() {
    std::cout << "\t\t********************************\n"
              << "\t\t* Turn-based role-playing game *\n"
              << "\t\t********************************\n";

    std::srand(std::time(nullptr));
    
    Person player;
    Person enemies[5];
    char mapVisual[20][20];

    initialization(mapVisual);

    for (int i = 0; i < 5; ++i) {
        enemies[i].name = "Enemy # " + std::to_string(i + 1);
        enemies[i].health = (std::rand() % 100) + 50;
        enemies[i].armor = (std::rand() % 50) + 0;
        enemies[i].damage = (std::rand() % 15) + 15;
        enemies[i].mathVector.x = (std::rand() % 19) + 0;
        enemies[i].mathVector.y = (std::rand() % 19) + 0;
    }

    for (int i = 0; i < 5; ++i)
        for (int j = 1; j < 5; ++j)
            if (enemies[i].mathVector.x == enemies[j].mathVector.x &&
                enemies[i].mathVector.y == enemies[j].mathVector.y) {
                    enemies[j].mathVector.x = (std::rand() % 19) + 0;
                    enemies[j].mathVector.y = (std::rand() % 19) + 0;
            }

    std::cout << "Character creation\n";
    std::cout << "Name: ";
    std::cin >> player.name;
    std::cout << "Health: ";
    std::cin >> player.health;
    std::cout << "Armor: ";
    std::cin >> player.armor;
    std::cout << "Damage: ";
    std::cin >> player.damage;
    std::cout << "Coordinates on the map (from 0 to 19): ";
    std::cin >> player.mathVector.x >> player.mathVector.y;
    player.isPlayer = true;

    while (player.mathVector.x < 0 || player.mathVector.x > 19 ||
           player.mathVector.y < 0 || player.mathVector.y > 19) {
            std::cout << "Incorrect coordinates. Enter again: ";
            std::cin >> player.mathVector.x >> player.mathVector.y;
    }

    while (mapVisual[player.mathVector.x][player.mathVector.y] != '.') {
        std::cout << "This place is occupied, enter another location: ";
        std::cin >> player.mathVector.x >> player.mathVector.y;
    }

    for (int i = 0; i < 5; ++i)
        mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] = 'E';

        mapVisual[player.mathVector.x][player.mathVector.y] = 'P';
            
    print(mapVisual);

    std::string command;

    while (player.health > 0) {
        std::cout << "Your move!\n";
        std::cout << "\"Up\" - U\n\"Down\" - D\n\"Left\" - L\n\"Right\" - R\n";
        std::cout << "Enter command: ";
        std::cin >> command;

        while (command != "U" && command != "D" && command != "L" && command != "R" &&
               command != "save" && command != "load") {
                std::cout << "Incorrect input. Enter again: \n";
                std::cin >> command;
        }

        if (command == "save") {
            std::ofstream file(FILE_NAME, std::ios::binary);
            if (file.is_open()) {
                for (int i = 0; i < 5; ++i)
                    save_person(file, enemies[i]);
                save_person(file, player);

                break;
                
            } else std::cerr << "File opening error!\n";
            file.close();
        
        } else if (command == "load") {
            std::ifstream in_file(FILE_NAME, std::ios::binary);
            if (in_file.is_open()) {
                for (int i = 0; i < 5; ++i)
                    load_person(in_file, enemies[i]);
                load_person(in_file, player);

                initialization(mapVisual);

                for (int i = 0; i < 5; ++i)
                    mapVisual[enemies[i].mathVector.x][enemies[i].mathVector.y] = 'E';

                mapVisual[player.mathVector.x][player.mathVector.y] = 'P';

                std::cout << "\nLast game:\n";
                print(mapVisual);
                    
            } else std::cout << "Game has never been saved yet\n\n";
            in_file.close();

        } else if (command == "U") {
            mapVisual[player.mathVector.x][player.mathVector.y] = '.';
            player.mathVector.x--;
            if (player.mathVector.x < 0) {
                std::cout << "You can not go beyond the boundaries of the map.\n";
                player.mathVector.x++;
            }
            checking_territory(mapVisual, player, enemies);
            
        } else if (command == "D") {
            mapVisual[player.mathVector.x][player.mathVector.y] = '.';
            player.mathVector.x++;
            if (player.mathVector.x > 19) {
                std::cout << "You can not go beyond the boundaries of the map.\n";
                player.mathVector.x--;
            }
            checking_territory(mapVisual, player, enemies);

        } else if (command == "L") {
            mapVisual[player.mathVector.x][player.mathVector.y] = '.';            
            player.mathVector.y--;
            if (player.mathVector.y < 0) {
                std::cout << "You can not go beyond the boundaries of the map.\n";
                player.mathVector.y++;
            }
            checking_territory(mapVisual, player, enemies);

        } else {
            mapVisual[player.mathVector.x][player.mathVector.y] = '.';                        
            player.mathVector.y++;
            if (player.mathVector.y > 19) {
                std::cout << "You can not go beyond the boundaries of the map.\n";
                player.mathVector.y--;
            }
            checking_territory(mapVisual, player, enemies);
        }

        std::cout << "\nEnemies make a move:\n";
        enemy_movement(enemies, mapVisual, player);

        print(mapVisual);
            
        int defeatedEnemies = 0;
        for (int i = 0; i < 5; ++i)
            if (enemies[i].mathVector.x == -50)
                defeatedEnemies++;

        if (defeatedEnemies == 5) {
            std::cout << "You won!\n";
            break;
        }
    }

    if (player.health <= 0)
        std::cout << "You lost...\n";
    else if (command == "save")
        std::cout << "Game is saved\n";
}