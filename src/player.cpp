#include "../include/player.h"
#include "../include/map.h"
#include "../include/enemy.h"

#include <cstdio>

void Player::update_player(const EnemyManager& enemies, const Map& map)
{
    (void)enemies; // Silenciar warnings hasta reimplementar colisiones
    (void)map;

    //update arma
    m_guns[m_active_gun].update_gun(GetFrameTime());

    //TODO: update_collision();
    
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
