#include <iostream>
#include <fstream>

// A function that creates an is_even.cpp
void create_is_even_program() {
    const int MAX_DEPTH = 15000;

    std::ofstream file;
    file.open("is_even.cpp");
    file << "bool is_even(int x) {\n";
    file << "  switch (x) {\n";
    for (int i = 0; i <= MAX_DEPTH; i++) {
        file << "    case " << i << ":\n";
        if (i%2 == 0)
            file << "      return true;\n";
        else
            file << "      return false;\n";
    }
    file << "    default:\n";
    file << "      return (x&1) == 0;\n";
    file << "  }\n";
    file << "}\n";
    file.close();
}

int main() {
    create_is_even_program();
}