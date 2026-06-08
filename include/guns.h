#pragma once

enum Gun_type
{
    NO,
    MELEE,
    RANGED
};

typedef enum
{
    NONE,
    PISTOL,
    RIFLE,
    BAT,
    KNIFE,
}Gun_model;

typedef enum
{
    NOT,
    FIRE,
    ICE,
    ELECTRICITY,
    DARK_MAGIC
}Type_power;

typedef enum
{
    NONE_Muzzle,
    
}muzzle;

typedef enum
{
    NONE_barrel,
    
}barrel;

typedef enum
{
    NONE_scope,
    
}scope;

typedef enum
{
    NONE_stock,
    
}stock;

typedef enum
{
    NONE_grip,
    
}rear_grip;

typedef enum
{
    NONE_ammo,
    
}ammo;

typedef enum
{
    NONE_mount,
    
}mount;

typedef enum
{
    NONE_accesory,
    
}extra_accessory;


class Gun
{
    public:
        Gun()
        {
            m_damage = 0.0;
            m_cadence = 0.0f;
            m_dispersion = 0.0;
            m_recoil = 0.0;
            m_scope = 0;
            m_recharge_velocity = 0.0;
            m_charger_size = 0;
            m_weight = 0.0f;
            m_bullet_velocity = 0.0f;
            m_prob_critical = 0.0;
            m_power = NOT;
            m_type = NONE;
            m_current_ammo = 0;
            m_fire_timer = 0.0f;
            is_realoading = false;
            m_warning_timer = 0.0f;
            m_gun_type = NO;

            m_muzzle_accessory = NONE_Muzzle;
            m_barrel_accessory = NONE_barrel;
            m_scope_accessory = NONE_scope;
            m_stock_accessory = NONE_stock;
            m_rear_grip_accessory = NONE_grip;
            m_ammo_accessory = NONE_ammo;
            m_mount_accessory = NONE_mount;
            m_extra_accessory = NONE_accesory;
        }

        Gun(double damage, float cadence, double dispersion, double recoil, int scope_range,
            double recharge_velocity, int charger_size, float wheight, float bullet_velocity,
            double prob_critical, Type_power power, Gun_model type,
            muzzle muzzle_accesory, barrel barrel_accesory, scope scope_accesory, stock stock_accesory,
            rear_grip rear_grip_accesory, ammo ammo_accesory, mount mount_accesory, extra_accessory extra_accessory)
        {
            m_damage = damage;
            m_cadence = cadence;
            m_dispersion = dispersion;
            m_recoil = recoil;
            m_scope = scope_range;
            m_recharge_velocity = recharge_velocity;
            m_charger_size = charger_size;
            m_weight = wheight;
            m_bullet_velocity = bullet_velocity;
            m_prob_critical = prob_critical;
            m_power = power;
            m_type = type;
            m_current_ammo = 0;
            m_fire_timer = 0.0f;
            is_realoading = false;
            m_warning_timer = 0.0f;
            m_gun_type = NO;

            m_muzzle_accessory = muzzle_accesory;
            m_barrel_accessory = barrel_accesory;
            m_scope_accessory = scope_accesory;
            m_stock_accessory = stock_accesory;
            m_rear_grip_accessory = rear_grip_accesory;
            m_ammo_accessory = ammo_accesory;
            m_mount_accessory = mount_accesory;
            m_extra_accessory = extra_accessory;
        }

        ~Gun() = default;

        // ---- GETTTERS ----
        double getDamage() const { return m_damage; }
        float getCadence() const { return m_cadence; }
        double getDispersion() const { return m_dispersion; }
        double getRecoil() const { return m_recoil; }
        int getScope() const { return m_scope; }
        double getRechargeVelocity() const { return m_recharge_velocity; }
        int getChargerSize() const { return m_charger_size; }
        float getWeight() const { return m_weight; }
        float getBulletVelocity() const { return m_bullet_velocity; }
        double getProbCritical() const { return m_prob_critical; }
        Type_power getPower() const { return m_power; }
        Gun_model getType() const { return m_type; }

        muzzle getMuzzleAccessory() const { return m_muzzle_accessory; }
        barrel getBarrelAccessory() const { return m_barrel_accessory; }
        scope getScopeAccessory() const { return m_scope_accessory; }
        stock getStockAccessory() const { return m_stock_accessory; }
        rear_grip getRearGripAccessory() const { return m_rear_grip_accessory; }
        ammo getAmmoAccessory() const { return m_ammo_accessory; }
        mount getMountAccessory() const { return m_mount_accessory; }
        extra_accessory getExtraAccessory() const { return m_extra_accessory; }
        int getAmmo() { return m_current_ammo; }

        // ---- SETTERS ----
        void setDamage(double damage) { m_damage = damage; }
        void setCadence(float cadence) { m_cadence = cadence; }
        void setDispersion(double dispersion) { m_dispersion = dispersion; }
        void setRecoil(double recoil) { m_recoil = recoil; }
        void setScope(int scope_range) { m_scope = scope_range; }
        void setRechargeVelocity(double recharge_velocity) { m_recharge_velocity = recharge_velocity; }
        void setChargerSize(int charger_size) { m_charger_size = charger_size; }
        void setWeight(float weight) { m_weight = weight; }
        void setBulletVelocity(float bullet_velocity) { m_bullet_velocity = bullet_velocity; }
        void setProbCritical(double prob_critical) { m_prob_critical = prob_critical; }
        void setPower(Type_power power) { m_power = power; }
        void setType(Gun_model type) { m_type = type; }
        void setAmmo(int i) { m_current_ammo = i; }

        void setMuzzleAccessory(muzzle muzzle_accessory) { m_muzzle_accessory = muzzle_accessory; }
        void setBarrelAccessory(barrel barrel_accessory) { m_barrel_accessory = barrel_accessory; }
        void setScopeAccessory(scope scope_accessory) { m_scope_accessory = scope_accessory; }
        void setStockAccessory(stock stock_accessory) { m_stock_accessory = stock_accessory; }
        void setRearGripAccessory(rear_grip rear_grip_accessory) { m_rear_grip_accessory = rear_grip_accessory; }
        void setAmmoAccessory(ammo ammo_accessory) { m_ammo_accessory = ammo_accessory; }
        void setMountAccessory(mount mount_accessory) { m_mount_accessory = mount_accessory; }
        void setExtraAccessory(extra_accessory extra_accessory_value) { m_extra_accessory = extra_accessory_value; }


        void create_pistol();
        void create_rifle();
        void create_knife();
        void create_bat();
        bool can_fire();
        void attack();
        void reload();
        void update_gun(float delta);
    private:
        // ---- STATS ----
        double m_damage;
        float m_cadence;
        double m_dispersion;
        double m_recoil; // retroceso
        int m_scope; //alcance
        double m_recharge_velocity;
        int m_charger_size;
        int m_current_ammo;
        float m_weight;
        float m_bullet_velocity;
        double m_prob_critical;
        Type_power m_power;
        Gun_model m_type;
        bool is_realoading;
        float m_fire_timer;
        float m_warning_timer;
        Gun_type m_gun_type;

        // ---- ACCESORIES ----
        muzzle m_muzzle_accessory;
        barrel m_barrel_accessory;
        scope m_scope_accessory;
        stock m_stock_accessory;
        rear_grip m_rear_grip_accessory;
        ammo m_ammo_accessory;
        mount m_mount_accessory;
        extra_accessory m_extra_accessory;

};
