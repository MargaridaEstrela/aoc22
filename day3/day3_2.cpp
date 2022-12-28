#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using string = std::string;


int get_priority(char item) {

    char A = 'A';
    char a = 'a';

    if (isupper(item)) {
        return item - A + 27;
    } else {
        return item - a + 1;
    }

    return 0;
}


int main() {

    std::ifstream file("day3.txt");
    int priorities_sum = 0;
    string elves[3] = {""};

    while(!file.eof()) {
        for (int i = 0; i < 3; i++) {
            string rucksack;
            std::getline(file, rucksack);
            elves[i] = rucksack;
        }

        char item = '\0';

        for (char c1 : elves[0]) {
            for (char c2 : elves[1]) {
                for (char c3 : elves[2]) {
                    if (c1 == c2 && c2 == c3) {
                        item = c1;
                        break;
                    }
                }
            }
        }

        priorities_sum += get_priority(item);

        for(int i = 0; i < 3; i++) {
            elves[i].clear();
        }
    }

    file.close();

    std::cout << "Sum = " << priorities_sum << std::endl;

    return 0;
}