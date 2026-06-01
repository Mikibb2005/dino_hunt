#include "../include/player.h"
#include <cstdio>


void Player::draw_player()
{
    DrawRectangle(int(m_position.x),int(m_position.y), 64, 64, RED);
}

void Player::update_player()
{
    //update arma
    m_guns[m_active_gun].update_gun(GetFrameTime());


    if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT) || IsGamepadButtonPressed(0,GAMEPAD_BUTTON_LEFT_FACE_LEFT))
    {
        m_position.x = m_position.x - steeps;
    }
    if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT) || IsGamepadButtonPressed(0,GAMEPAD_BUTTON_LEFT_FACE_RIGHT))
    {
        m_position.x = m_position.x + steeps;
    }
    if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP) || IsGamepadButtonPressed(0,GAMEPAD_BUTTON_LEFT_FACE_UP))
    {
        m_position.y = m_position.y - steeps;
    }
    if(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN) || IsGamepadButtonPressed(0,GAMEPAD_BUTTON_LEFT_FACE_DOWN))
    {
        m_position.y = m_position.y + steeps;
    }
    if(IsKeyDown(MOUSE_BUTTON_LEFT))
    {
        if(m_guns[m_active_gun].can_fire())
        {
            m_guns[m_active_gun].attack();
        }
    }   
    if(IsKeyPressed(KEY_R))
    {
        m_guns[m_active_gun].reload();
        printf("Recargando %d balas... \n", m_guns[m_active_gun].getChargerSize());
    }
    
}