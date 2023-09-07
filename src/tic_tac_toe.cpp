#include <iostream>

#include <windows.h>
#include <random>
#include <functional>

#include "game_field.h"

using namespace std;

void ClearScreen(const char fill = ' ') {
    constexpr COORD tl = { 0 , 0 };
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console , &s);
    DWORD written;
    const DWORD cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console , fill , cells , tl , &written);
    FillConsoleOutputAttribute(console , s.wAttributes , cells , tl , &written);
    SetConsoleCursorPosition(console , tl);
}

void UpdateScreen(const Field &field) {
    ClearScreen();
    cout << "\t\t\t\ttic_tac_toe game\n\n" << std::endl;
    cout << field.ToString() + "\n";
}

TurnResult Turn(Field& field, const std::function<TurnResult(Field&)>& factory) {

    TurnResult result = TurnResult::INVALID_COORDS;

    while (result == TurnResult::INVALID_COORDS) {
        result = factory(field);
    }

    return result;
}

TurnResult AiTurn(Field &field) {

    random_device rd;
    mt19937_64 gen(rd());

    uniform_int_distribution<int> rnd(0, field.dimension());

    return Turn(field, [&](Field &field) {
        return field.AddO(rnd(gen), rnd(gen));
    });
}

TurnResult PlayerTurn(Field &field) {

    return Turn(field, [](Field &field) {
        int x, y;
        cin >> x >> y;
        return field.AddX(x - 1, y - 1);
    });
}

int main() {
    const int kDimension = 3;
    Field field(kDimension);

    UpdateScreen(field);

    while(!field.IsSomeoneWin()) {

        if (PlayerTurn(field) == TurnResult::NO_TURNS_ALLOWED ||
                AiTurn(field) == TurnResult::NO_TURNS_ALLOWED)
            break;

        UpdateScreen(field);
    }

    UpdateScreen(field);

    cout << "\n\tGAME FINISHED!" << endl;

    return 0;
}
