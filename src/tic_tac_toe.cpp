#include <iostream>

#include <windows.h>
#include <random>

#include "Field.h"

using namespace std;

void clear_screen(const char fill = ' '){
    constexpr COORD tl = {0, 0};
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written;
    const DWORD cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

void ai_turn(const int field_width, Field& field){
    random_device rd;
    mt19937_64 gen(rd());

    uniform_int_distribution<int> rnd(0, field_width);

    bool success = false;
    
    while (!success)
        success = field.add_0(rnd(gen), rnd(gen));
}

void player_turn(Field& field){
    bool success = false;
    
    while (!success)
    {
        int x, y;

        cin >> x >> y;
        success = field.add_x(x - 1, y - 1);
    }
}

void tick(Field& field){
    clear_screen();
    cout << "\t\t\t\ttic_tac_toe game\n\n" << std::endl;
    cout << field.to_string() + "\n";
}

int main(){
    constexpr int field_width = 3;
    Field field(field_width);

    tick(field);

    while (!field.is_someone_win()){
        player_turn(field);
        ai_turn(field_width, field);

        tick(field);
    }

    return 0;
}
