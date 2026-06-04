#include "../include/enemy.h"
#include <cstddef>

void Enemy::enemy_update()
{

}
        
void Enemy::enemy_draw()
{
    DrawRectangle(int(m_position.x),int(m_position.y), ENEMY_SIZE, ENEMY_SIZE, RED);
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