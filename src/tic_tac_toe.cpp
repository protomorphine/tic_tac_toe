#include <iostream>

#include <windows.h>
#include <random>

#include "game_field.h"

void ClearScreen(const char fill = ' ') {
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

void UpdateScreen(const game::Field& field) {
  ClearScreen();
  std::cout << "\t\t\t\ttic_tac_toe game\n\n" << std::endl;
  std::cout << field.ToString() + "\n";
}

template <typename Factory>
game::TurnResult Turn(game::Field& field, const Factory& factory) {
  game::TurnResult result = game::TurnResult::INVALID_COORDS;

  while (result == game::TurnResult::INVALID_COORDS) {
    result = factory(field);
  }

  return result;
}

game::TurnResult AiTurn(game::Field& field) {
  std::random_device rd;
  std::mt19937_64 gen(rd());

  std::uniform_int_distribution<int> rnd(0, field.dimension());

  return Turn(field, [&rnd, &gen](game::Field& f) { return f.AddO(rnd(gen), rnd(gen)); });
}

game::TurnResult PlayerTurn(game::Field& field) {
  return Turn(field, [](game::Field& f) {
    int x;
    int y;

    std::cin >> x >> y;
    return f.AddX(x - 1, y - 1);
  });
}

int main() {
  const int kDimension = 3;
  game::Field field(kDimension);

  UpdateScreen(field);

  while (!field.IsSomeoneWin()) {
    if (PlayerTurn(field) == game::TurnResult::NO_TURNS_ALLOWED ||
        AiTurn(field) == game::TurnResult::NO_TURNS_ALLOWED) {
      break;
    }
    UpdateScreen(field);
  }

  UpdateScreen(field);

  std::cout << "\n\tGAME FINISHED!" << std::endl;

  return 0;
}
