#include "../raylib-6.0_linux_amd64/include/raylib.h"
#include <vector>
#include "guns.h"
enum EnemyState
{

};


class Enemy
{
    public:
        void enemy_update();
        void enemy_draw();
        void take_damage(); //para restar la vida, ademas de comprovar si muere
        bool is_dead(); //devuelve true si esta muerto

    private:
        Vector2 m_position;
        int m_health;
        float m_speed;
        float m_damage;
        Gun m_weapon;
        EnemyState m_state;
        Rectangle m_hitbox;
};

class EnemyManager
{
    public:
        void update_all();
        void draw_all();
        void check_hits(); 


    private:
        std::vector<Enemy> m_enemies;
};