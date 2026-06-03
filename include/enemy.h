#pragma once

#include "../raylib-6.0_linux_amd64/include/raylib.h"
#include <vector>
#include "guns.h"
enum EnemyState
{
    STOPED,
    WALKING,
    SEARCHING,
    ATTACK,
};


class Enemy
{
    public:
        Enemy()
        {
            m_position = Vector2{0.0f, 0.0f};
            m_health = 100;
            m_speed = 1.0f;
            m_damage = 1.0f;
            Gun a;
            a.create_pistol();
            m_weapon = a;
            m_state = STOPED;
            m_hitbox = Rectangle{m_position.x, m_position.y, 64, 64};
        }

        Rectangle getHitbox() const { return m_hitbox; }



        void enemy_update();
        void enemy_draw();
        void take_damage(); //para restar la vida, ademas de comprovar si muere
        bool is_dead(); //devuelve true si esta muerto

    private:
        Vector2 m_position;
        int m_health;
        float m_speed;
        float m_damage; //multiplicador de daño (por el de la gun)
        Gun m_weapon;
        EnemyState m_state;
        Rectangle m_hitbox;
};

class EnemyManager
{
    public:
        const std::vector<Enemy>& getEnemies() const { return m_enemies; }



        void update_all();
        void draw_all();
        void check_hits(); 
        void add_enemy(Enemy a) { m_enemies.push_back(a); }


    private:
        std::vector<Enemy> m_enemies;
};