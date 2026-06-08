#pragma once

#include "../raylib-6.0_linux_amd64/include/raylib.h"
#include "guns.h"
#include <vector>

enum EnemyState {
  STOPED,
  WALKING,
  SEARCHING,
  ATTACK,
};

const int ENEMY_SIZE = 64;

class Enemy {
public:
  Enemy() {
    m_position = Vector2{0.0f, 0.0f};
    m_health = 100;
    m_speed = 1.0f;
    m_damage = 1.0f;
    Gun a;
    a.create_pistol();
    m_weapon = a;
    m_state = STOPED;
    m_facing_angle = 0.0f;
    m_current_anim = 0;
    m_anim_frame = 0;
    m_anim_timer = 0.0f;
  }

  // TODO:Hacer el getHitbox() con colisión esférica/cilíndrica

  void enemy_update(float deltaTime, ModelAnimation *anims, int animCount);
  void enemy_draw(Model &model, ModelAnimation *anims, int animCount);
  void take_damage(); // para restar la vida, ademas de comprovar si muere
  bool is_dead();     // devuelve true si esta muerto

private:
  Vector2 m_position;
  int m_health;
  float m_speed;
  float m_damage; // multiplicador de daño (por el de la gun)
  Gun m_weapon;
  EnemyState m_state;

  // TODO: poner el colsion en 3D

  float m_facing_angle; // direccion del enemigo

  // Control de animaciones 3D
  int m_current_anim;
  int m_anim_frame;
  float m_anim_timer;
};

class EnemyManager {
public:
  EnemyManager() : m_enemy_anims(nullptr), m_anim_count(0) {}
  const std::vector<Enemy> &getEnemies() const { return m_enemies; }

  void load_resources();
  void unload_resources();

  void update_all(float deltaTime);
  void draw_all();
  void check_hits();
  void add_enemy(Enemy a) { m_enemies.push_back(a); }

private:
  std::vector<Enemy> m_enemies;
  Model m_enemy_model;
  ModelAnimation *m_enemy_anims;
  int m_anim_count;
};
