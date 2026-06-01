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
    m_current_ammo = 0;
    m_fire_timer = 0.0f;
    is_realoading = false;
    m_gun_type = MELEE;
}

void Gun::create_bat()
{
    m_type = BAT;

    m_damage = 10;
    m_cadence = 0.5; // 0.5cuchilladas/s --> 2 seg x cuchillada
    m_dispersion = 0;
    m_recoil = 0;
    m_scope = 2;
    m_recharge_velocity = 0;
    m_charger_size = 0;
    m_bullet_velocity = 0; 
    m_weight = 5;
    m_prob_critical = 0.1;
    m_power = NOT;
    m_current_ammo = 0;
    m_fire_timer = 0.0f;
    is_realoading = false;
    m_gun_type = MELEE;
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
    m_current_ammo = 12;
    m_fire_timer = 0.0f;
    is_realoading = false;
    m_gun_type = RANGED;
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
    m_current_ammo = 20;
    m_fire_timer = 0.0f;
    is_realoading = false;
    m_gun_type = RANGED;
}

void Gun::attack()
{
    if(m_gun_type == RANGED)
    {
        m_current_ammo--;
        m_fire_timer = 1.0f / m_cadence;
    }
    else if(m_gun_type == MELEE)
    {
        m_fire_timer = 1.0f / m_cadence;
    }
}


void Gun::reload()
{
    if(m_gun_type == RANGED)
    {
        is_realoading = true;
        m_fire_timer = m_recharge_velocity;
    }
}

bool Gun::can_fire()
{
    if (m_gun_type == MELEE)
    {
        return m_fire_timer <= 0.0f;
    }
    else
    {
        return m_current_ammo > 0 && m_fire_timer <= 0.0f && !is_realoading;
    }
}

void Gun::update_gun(float delta)
{
    if (m_fire_timer > 0.0f)
    {
        m_fire_timer -= delta;
    }

    if (is_realoading && m_fire_timer <= 0.0f)
    {
        m_current_ammo = m_charger_size;
        is_realoading = false;
    }
}