#include "../include/guns.h"

void Gun::create_knife()
{
    m_type = KNIFE;

    m_damage = 15;
    m_cadence = 0.75; // 0.75cuchilladas/s
    m_dispersion = 0;
    m_recoil = 0;
    m_scope = 1;
    m_recharge_velocity = 0;
    m_charger_size = 0;
    m_bullet_velocity = 0;
    m_weight = 2;
    m_prob_critical = 0.075;
    m_power = NOT;
}

void Gun::create_bat()
{
    m_type = BAT;

    m_damage = 10;
    m_cadence = 0.5; // 0.5cuchilladas/s
    m_dispersion = 0;
    m_recoil = 0;
    m_scope = 2;
    m_recharge_velocity = 0;
    m_charger_size = 0;
    m_bullet_velocity = 0; 
    m_weight = 5;
    m_prob_critical = 0.1;
    m_power = NOT;
}

void Gun::create_pistol()
{
    m_type = PISTOL;

    m_damage = 20;
    m_cadence = 3; // 3balas/s
    m_dispersion = 0;
    m_recoil = 0.5;
    m_scope = 10;
    m_recharge_velocity = 3;
    m_charger_size = 12;
    m_bullet_velocity = 5; // 5coords/s
    m_weight = 3;
    m_prob_critical = 0.15;
    m_power = NOT;
}

void Gun::create_rifle()
{
    m_type = RIFLE;

    m_damage = 35;
    m_cadence = 5; // 5balas/s
    m_dispersion = 0;
    m_recoil = 0.7;
    m_scope = 20;
    m_recharge_velocity = 3;
    m_charger_size = 20;
    m_bullet_velocity = 7; // 7coords/s
    m_weight = 5;
    m_prob_critical = 0.15;
    m_power = NOT;
}