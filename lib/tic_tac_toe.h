#pragma once

#include <array>
#include <limits>
#include <queue>
#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <stack>

#define USI_MAX std::numeric_limits<unsigned short int>::max()
#define board_array std::array<std::array<char, 3>, 3>
typedef unsigned short int usi;

template <typename T> bool all_equal(T first, std::initializer_list<T> values) { return std::all_of(values.begin(), values.end(), [first](T value) { return value == first; }); }

namespace helper_functions {
    bool is_winner(board_array board, char player_char);
    bool is_draw(board_array board);
    bool is_valid_move(board_array board, usi row, usi column);
    void print_board(board_array board);
}

class tic_tac_toe {
  board_array board;
  usi x_count{0}, o_count{0};

public:
  tic_tac_toe();

  void print_board();
  void update_board(usi row, usi column, char player_char);
  bool is_winner(char player_char);
  bool is_draw();
  bool is_valid_move(usi row, usi column);
  std::pair<usi, usi> dfs_ai_move(char player_char);
  std::pair<usi, usi> bfs_ai_move(char player_char);

  std::pair<usi, usi> iterative_deepening_ai_move(char player_char);
  std::pair<usi, usi> depth_limited_dfs(char player_char, usi max_depth);
  std::pair<usi, usi> ucs_ai_move(char player_char);
};
