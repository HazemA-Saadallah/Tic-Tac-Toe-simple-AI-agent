#include "tic_tac_toe.h"

bool helper_functions::is_winner(board_array board, char player_char) {
  if (all_equal(player_char, {board[0][0], board[1][1], board[2][2]}) || all_equal(player_char, {board[0][2], board[1][1], board[2][0]})) return true;
  for (usi i = 0; i < 3; ++i) if (all_equal(player_char, {board[i][0], board[i][1], board[i][2]}) || all_equal(player_char, {board[0][i], board[1][i], board[2][i]})) return true;
  return false;
}

bool helper_functions::is_draw(board_array board) {
  for (usi i = 0; i < 3; ++i) for (usi j = 0; j < 3; ++j) if (board[i][j] == ' ') return false;
  return true;
}

bool helper_functions::is_valid_move(board_array board, usi row, usi column) { return (row >= 0 && row < 3) && (column >= 0 && column < 3) && board[row][column] == ' '; }

void helper_functions::print_board(board_array board) {
  std::cout << ' ' << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << '\n'
            << "-----------\n"
            << ' ' << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << '\n'
            << "-----------\n"
            << ' ' << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << '\n';
}

tic_tac_toe::tic_tac_toe() { std::for_each( this->board.begin(), this->board.end(), [](std::array<char, 3> &arr) { std::fill(arr.begin(), arr.end(), ' '); }); }
void tic_tac_toe::print_board() { helper_functions::print_board(this->board); }
void tic_tac_toe::update_board(usi row, usi column, char player_char) { this->board[row][column] = player_char; }
bool tic_tac_toe::is_winner(char player_char) { return helper_functions::is_winner(this->board, player_char); }
bool tic_tac_toe::is_draw() { return helper_functions::is_draw(this->board); }
bool tic_tac_toe::is_valid_move(usi row, usi column) { return helper_functions::is_valid_move(this->board, row, column); }

std::pair<usi, usi> tic_tac_toe::dfs_ai_move(char player_char) {
  std::stack<board_array> s;
  s.push(this->board);
  while (!s.empty()) {
    board_array current_board = s.top();
    s.pop();
    for (usi i{0}; i < 3; ++i) for (usi j{0}; j < 3; ++j) if (current_board[i][j] == ' ') {
      board_array new_board = current_board;
      new_board[i][j] = player_char;
      if (helper_functions::is_winner(new_board, player_char))  return std::pair(i, j);
      s.push(new_board);
    }
  }
  return std::pair(USI_MAX, USI_MAX);
}

std::pair<usi, usi> tic_tac_toe::bfs_ai_move(char player_char) {
  std::queue<board_array> q;
  q.push(this->board);
  while (!q.empty()) {
    board_array current_board = q.front();
    q.pop();
    for (usi i{0}; i < 3; ++i) for (usi j{0}; j < 3; ++j) if (current_board[i][j] == ' ') {
      board_array new_board = current_board;
      new_board[i][j] = player_char;
      if (helper_functions::is_winner(new_board, player_char))  return std::pair(i, j);
      q.push(new_board);
    }
  }
  return std::pair(USI_MAX, USI_MAX);
}

std::pair<usi, usi> tic_tac_toe::depth_limited_dfs(char player_char, usi max_depth) {
  std::stack<board_array> s;
  s.push(this->board);
  while (!s.empty() && max_depth) {
    board_array current_board = s.top();
    s.pop();
    for (usi i{0}; i < 3; ++i) for (usi j{0}; j < 3; ++j) if (current_board[i][j] == ' ') {
      board_array new_board = current_board;
      new_board[i][j] = player_char;
      if (helper_functions::is_winner(new_board, player_char))  return std::pair(i, j);
      s.push(new_board);
    }
    --max_depth;
  }
  return std::pair(USI_MAX, USI_MAX);
}

std::pair<usi, usi> tic_tac_toe::iterative_deepening_ai_move(char player_char) {
  std::pair<usi, usi> ai_move = std::pair(USI_MAX, USI_MAX);
  for (usi i{1}; i < 9; ++i) {
    ai_move = depth_limited_dfs(player_char, i);
    if (ai_move != std::pair(USI_MAX, USI_MAX)) return ai_move;
  }
  return ai_move;
}

std::pair<usi, usi> tic_tac_toe::ucs_ai_move(char player_char) {
  std::priority_queue<std::pair<usi, board_array>, std::vector<std::pair<usi, board_array>>, std::greater<>> pq; // Using `greater` for min-heap
  usi priority{0};
  pq.emplace(priority, this->board);
  while (!pq.empty()) {
    board_array current_board = pq.top().second;
    pq.pop();
    for (usi i{0}; i < 3; ++i) for (usi j{0}; j < 3; ++j) if (current_board[i][j] == ' ') {
      board_array new_board = current_board;
      new_board[i][j] = player_char;
      if (helper_functions::is_winner(new_board, player_char))  return std::pair(i, j);
      pq.emplace(priority, new_board);
    }
    ++priority;
  }
  return std::pair(USI_MAX, USI_MAX);
}
