#include <tic_tac_toe.h>

void dfs_game() {
  tic_tac_toe game = tic_tac_toe();
  char current_player {'X'};
  usi row{0}, column{0};
  while (true) {
    if (current_player == 'X') {
      game.print_board();
      std::cout <<"Enter row number: ", std::cin >>row;
      std::cout <<"Enter column number: ", std::cin >>column;
    } else {
      std::cout <<"Player O (AI) is making a move...\n";
      std::pair<usi, usi> ai_move = game.dfs_ai_move('O');
      if (ai_move != std::pair(USI_MAX, USI_MAX)) row = ai_move.first, column = ai_move.second;
    }
    if (game.is_valid_move(row, column)) {
      game.update_board(row, column, current_player);
      if (game.is_winner(current_player)) {
        game.print_board();
        std::cout <<"player " <<current_player <<" won!\n";
        return;
      }
      if (game.is_draw()) std::cout <<"It's a draw\n";
      current_player == 'X'? current_player = 'O' : current_player = 'X';
    } else std::cout <<"Invalid move. Please try again.\n";
  }
}

void bfs_game() {
  tic_tac_toe game = tic_tac_toe();
  char current_player {'X'};
  usi row{0}, column{0};
  while (true) {
    if (current_player == 'X') {
      game.print_board();
      std::cout <<"Enter row number: ", std::cin >>row;
      std::cout <<"Enter column number: ", std::cin >>column;
    } else {
      std::cout <<"Player O (AI) is making a move...\n";
      std::pair<usi, usi> ai_move = game.bfs_ai_move('O');
      if (ai_move != std::pair(USI_MAX, USI_MAX)) row = ai_move.first, column = ai_move.second;
    }
    if (game.is_valid_move(row, column)) {
      game.update_board(row, column, current_player);
      if (game.is_winner(current_player)) {
        game.print_board();
        std::cout <<"player " <<current_player <<" won!\n";
        return;
      }
      if (game.is_draw()) std::cout <<"It's a draw\n";
      current_player == 'X'? current_player = 'O' : current_player = 'X';
    } else std::cout <<"Invalid move. Please try again.\n";
  }
}

void depth_limited_game() {
  tic_tac_toe game = tic_tac_toe();
  char current_player {'X'};
  usi row{0}, column{0};
  while (true) {
    if (current_player == 'X') {
      game.print_board();
      std::cout <<"Enter row number: ", std::cin >>row;
      std::cout <<"Enter column number: ", std::cin >>column;
    } else {
      std::cout <<"Player O (AI) is making a move...\n";
      std::pair<usi, usi> ai_move = game.depth_limited_dfs('O', 3);
      if (ai_move != std::pair(USI_MAX, USI_MAX)) row = ai_move.first, column = ai_move.second;
    }
    if (game.is_valid_move(row, column)) {
      game.update_board(row, column, current_player);
      if (game.is_winner(current_player)) {
        game.print_board();
        std::cout <<"player " <<current_player <<" won!\n";
        return;
      }
      if (game.is_draw()) std::cout <<"It's a draw\n";
      current_player == 'X'? current_player = 'O' : current_player = 'X';
    } else std::cout <<"Invalid move. Please try again.\n";
  }
}

void iterative_deepening_game() {
  tic_tac_toe game = tic_tac_toe();
  char current_player {'X'};
  usi row{0}, column{0};
  while (true) {
    if (current_player == 'X') {
      game.print_board();
      std::cout <<"Enter row number: ", std::cin >>row;
      std::cout <<"Enter column number: ", std::cin >>column;
    } else {
      std::cout <<"Player O (AI) is making a move...\n";
      std::pair<usi, usi> ai_move = game.iterative_deepening_ai_move('O');
      if (ai_move != std::pair(USI_MAX, USI_MAX)) row = ai_move.first, column = ai_move.second;
    }
    if (game.is_valid_move(row, column)) {
      game.update_board(row, column, current_player);
      if (game.is_winner(current_player)) {
        game.print_board();
        std::cout <<"player " <<current_player <<" won!\n";
        return;
      }
      if (game.is_draw()) std::cout <<"It's a draw\n";
      current_player == 'X'? current_player = 'O' : current_player = 'X';
    } else std::cout <<"Invalid move. Please try again.\n";
  }
}

void ucs_game() {
  tic_tac_toe game = tic_tac_toe();
  char current_player {'X'};
  usi row{0}, column{0};
  while (true) {
    if (current_player == 'X') {
      game.print_board();
      std::cout <<"Enter row number: ", std::cin >>row;
      std::cout <<"Enter column number: ", std::cin >>column;
    } else {
      std::cout <<"Player O (AI) is making a move...\n";
      std::pair<usi, usi> ai_move = game.ucs_ai_move('O');
      if (ai_move != std::pair(USI_MAX, USI_MAX)) row = ai_move.first, column = ai_move.second;
    }
    if (game.is_valid_move(row, column)) {
      game.update_board(row, column, current_player);
      if (game.is_winner(current_player)) {
        game.print_board();
        std::cout <<"player " <<current_player <<" won!\n";
        return;
      }
      if (game.is_draw()) std::cout <<"It's a draw\n";
      current_player == 'X'? current_player = 'O' : current_player = 'X';
    } else std::cout <<"Invalid move. Please try again.\n";
  }
}

int main(int argc, char *argv[]) {
  dfs_game();
  /*bfs_game();*/
  /*depth_limited_game();*/
  /*iterative_deepening_game();*/
  /*ucs_game();*/
  return 0;
}
