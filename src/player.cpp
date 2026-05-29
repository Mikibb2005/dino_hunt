#include "../include/player.h"


void Player::draw_player()
{
    DrawRectangle(int(m_position.x),int(m_position.y), 64, 64, RED);
}