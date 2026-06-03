#include "../include/player.h"
#include "../include/map.h"

#include <cstdio>


void Player::draw_player()
{
    DrawRectangle(int(m_position.x),int(m_position.y), 64, 64, GREEN);
}

void Player::update_player(const EnemyManager& enemies)
{
    //update arma
    m_guns[m_active_gun].update_gun(GetFrameTime());

    // ------- VERSION ANTIGUA SIN COLISIONES -------
    /*if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT) || IsGamepadButtonPressed(0,GAMEPAD_BUTTON_LEFT_FACE_LEFT))
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
    }*/

    //comprovacion del eje X
    float new_x = m_position.x;

    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT))
    {
        new_x -= steeps;
    }
    if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT) || IsGamepadButtonPressed(0,GAMEPAD_BUTTON_LEFT_FACE_RIGHT))
    {
        new_x += steeps;
    }
    if (new_x < 0) new_x = 0;
    if (new_x + 64 > MAP_WIDTH) new_x = MAP_WIDTH - 64;

    Rectangle test_x = { new_x, m_position.y, 64, 64 };

    bool block_x = false;
    for (const Enemy& e : enemies.getEnemies())
    {
        if (CheckCollisionRecs(test_x, e.getHitbox()))
        {
            block_x = true;
            break;
        }
    }
    if (!block_x) m_position.x = new_x;

    // Eje Y

    float new_y = m_position.y;
    if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP) || IsGamepadButtonPressed(0,GAMEPAD_BUTTON_LEFT_FACE_UP))
    {
        new_y -= steeps;
    }
    if(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN) || IsGamepadButtonPressed(0,GAMEPAD_BUTTON_LEFT_FACE_DOWN))
    {
        new_y += steeps;
    }
    if (new_y < 0) new_y = 0;
    if (new_y + 64 > MAP_HEIGHT) new_y = MAP_HEIGHT - 64;

    Rectangle test_y = { m_position.x, new_y, 64, 64 };
    bool block_y = false;
    for (const Enemy& e : enemies.getEnemies())
    {
        if (CheckCollisionRecs(test_y, e.getHitbox()))
        {
            block_y = true;
            break;
        }
    }
    if (!block_y) m_position.y = new_y;

    m_hitbox = { m_position.x, m_position.y, 64, 64 };



    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
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