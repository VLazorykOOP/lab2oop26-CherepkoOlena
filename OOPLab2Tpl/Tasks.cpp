#include <iostream>
#include <string>
#include <cstdint>
#include <iomanip>
#include "Tasks.h"
using namespace std;



void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Calculation of expressions using bitwise operations  \n";
    cout << "    2.  Data encryption using bitwise operations \n";
    cout << "    3.  Data encryption using structures with bit fields \n";
    cout << "    4.  Exit \n";
}
void task1() {

    int a;
    int b;
    int c;
    int d;

    cout << " Input A:";
    cin >> a;

    cout << " Input B:";
    cin >> b;

    cout << " Input C:";
    cin >> c;

    cout << " Input D:";
    cin >> d;

    int a15 = (a<<4)-a;
    int b312 = (b<<8)+(b<<6)-(b<<3);

    int division = (a15+b312)>>6;

    int c120 = (c<<7)-(c<<3);
    int d121 = (d<<7)-(d<<3)+d;

    int result = division-c120+d121;
    cout << result;
}

void task2()
{
    std::string lines[4] = {
        "Algorithmization",
        "C++ Programming",
        "Variables and Data Types",
        "Bitwise operations"
    };

    uint16_t encrypted_text[4][32];


    for (int row = 0; row < 4; ++row) {
        while (lines[row].length() < 32) {
            lines[row] += ' ';
        }
        if (lines[row].length() > 32) {
            lines[row] = lines[row].substr(0, 32);
        }

        std::cout << "Row " << row << " (" << lines[row] << "):\n";

        for (int pos = 0; pos < 32; ++pos) {
            char c = lines[row][pos];

            // Змінна для 2-байтового результату (16 біт)
            uint16_t encrypted_char = 0;

            // Біти 0-1: номер рядка (2 біти, маска 0x03 або 3)
            encrypted_char |= (row & 3);

            // Біти 2-6: позиція символу (5 біт, маска 0x1F або 31), зсуваємо на 2 біти вліво
            encrypted_char |= ((pos & 31) << 2);

            // Біти 7-14: ASCII-код (8 біт, маска 0xFF або 255), зсуваємо на 7 біт вліво
            encrypted_char |= ((c & 255) << 7);


            int ones_count = 0;
            for (int i = 0; i < 15; ++i) {
                if ((encrypted_char >> i) & 1) {
                    ones_count++;
                }
            }

            if (ones_count % 2 != 0) {
                encrypted_char |= (1 << 15);
            }

            encrypted_text[row][pos] = encrypted_char;

            std::cout << std::hex << std::setw(4) << std::setfill('0') << encrypted_char << " ";
        }
        std::cout << "\n\n";
    }


}
void task3() {
 union EncryptedChar {
    struct {
        uint16_t row    : 2; // Біти 0-1: номер рядка (2 біти)
        uint16_t pos    : 5; // Біти 2-6: позиція в рядку (5 біт)
        uint16_t ascii  : 8; // Біти 7-14: ASCII-код символу (8 біт)
        uint16_t parity : 1; // Біт 15: біт парності (1 біт)
    } bits;

    uint16_t full_value; // Змінна для доступу до всіх 16 бітів одночасно
};

    std::string lines[4] = {
        "Algorithmization",
        "Data structures",
        "Bit fields logic",
        "Programming in C++"
    };

    EncryptedChar encrypted_text[4][32];

    for (int row = 0; row < 4; ++row) {

        while (lines[row].length() < 32) lines[row] += ' ';
        if (lines[row].length() > 32) lines[row] = lines[row].substr(0, 32);

        std::cout << "Row " << row << ":\n";

        for (int pos = 0; pos < 32; ++pos) {
            EncryptedChar data;
            data.full_value = 0; // Очищуємо пам'ять перед записом

            // Записуємо дані у відповідні бітові поля
            data.bits.row = row;
            data.bits.pos = pos;
            data.bits.ascii = lines[row][pos];

            int ones_count = 0;
            for (int i = 0; i < 15; ++i) {
                if ((data.full_value >> i) & 1) {
                    ones_count++;
                }
            }

            if (ones_count % 2 != 0) {
                data.bits.parity = 1;
            } else {
                data.bits.parity = 0;
            }

            encrypted_text[row][pos] = data;

            std::cout << std::hex << std::setw(4) << std::setfill('0') << data.full_value << " ";
        }
        std::cout << "\n\n";
    }

}


