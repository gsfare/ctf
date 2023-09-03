#include <stdio.h>
#include <string.h>

const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int num_characters = sizeof(characters) - 1;
int count = 0;

void print_combinations(char* str, int index, int length) {


    if (index == length) {
        count++;
        if(count == 10000) {
            printf("%s\n", str);
            count = 0;
        }

        return;
    }

    for (int i = 0; i < num_characters; i++) {
        str[index] = characters[i];
        print_combinations(str, index + 1, length);
    }
}

int main() {
    const int str_length = 8;
    char combination[str_length + 1];
    combination[str_length] = '\0';

    print_combinations(combination, 0, str_length);

    return 0;
}