#include<stdio.h>
#include<string>
#include<iostream>

int test() {
    FILE* p;
    p = fopen("test.txt", "r");
    if (p == NULL) {
        printf("Error in opening file\n");
        p = fopen("test.txt", "w");
        std::cout << "File opened successfully\n";
        std::cout << "what you want to write ? ";
        std::string str;
        std::getline(std::cin, str);
        size_t len = str.length();
        fwrite(&len, sizeof(len), 1, p);
        fwrite(str.c_str(), sizeof(char), len, p);
        fclose(p);
        return 0;
    };
    size_t len{};
    fread(&len, sizeof(len), 1, p);
    char* buffer = new char[len + 1];
    fread(buffer, sizeof(char), len, p);
    buffer[len] = '\0';
    std::string str = buffer;
    std::cout << str << "\n";
    fclose(p);
    return 0;
}

