#include "../include/enemy.h"
#include <cstddef>

void Enemy::enemy_update()
{

}
        
void Enemy::enemy_draw()
{
    //TODO: DrawBillboardRec();
    //   1. Calcular ángulo relativo jugador→enemigo vs m_facing_angle
    //   2. Seleccionar fila del spritesheet (frente/espalda/izq/der)
    //   3. Seleccionar columna según m_anim_frame
    //   4. DrawBillboardRec(camera, spritesheet, srcRect, pos3D, size, WHITE)
}

void Enemy::take_damage()
{

}

bool Enemy::is_dead()
{
    if(m_health <= 0)
    {
        return true;
    }
    return false;
}

void EnemyManager::update_all()
{
    for(size_t i = 0; i < m_enemies.size(); i++)
    {
        m_enemies[i].enemy_update();
    }
}
        
void EnemyManager::draw_all()
{
    for(size_t i = 0; i < m_enemies.size(); i++)
    {
        m_enemies[i].enemy_draw();
    }
}
        
void EnemyManager::check_hits()
{

} 
