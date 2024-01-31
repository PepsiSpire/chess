#include "player.h"

Player::Player(int clr, Board* board) : color(clr), board(board) {}
void Player::GenerateMoves(){
    board->GenerateMoves(color);
}

int Player::getColor(){
    return color;
}

void Player::Move(){}

Player::~Player(){}
