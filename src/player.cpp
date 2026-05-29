#include "../include/player.h"


void Player::draw_player()
{
    DrawRectangle(int(m_position.x),int(m_position.y), 64, 64, RED);
}

void Player::update_player()
{
    //TODO: tengo que hacer bien las keys
    //if(IsKeyPressed(0) || IsGamepadButtonPressed(0,0))
}