#pragma once

#include "../raylib-6.0_linux_amd64/include/raylib.h"
#include "guns.h"

class EnemyManager;
class Map;

const int steeps = 5;
const int PLAYER_SIZE = 64;

class Player {
public:
  Player()
      : m_health(100), m_endurance(100.0f), m_stamina(100), m_velocity(5.0f),
        m_position({0.0f, 0.0f}), num_bullets(0),
        m_active_gun(0), m_angle(0.0f), m_pitch(0.0f) {}

  Player(int health, float endurance, int stamina, float velocity, Vector2 position, int bullets, float angle, float pitch) 
  {
    m_health = health;
    m_endurance = endurance;
    m_stamina = stamina;
    m_velocity = velocity;
    m_position = position;
    num_bullets = bullets;
    m_active_gun = 0;
    m_angle = angle;
    m_pitch = pitch;
  }

  ~Player() = default;

  int getHealth() const { return m_health; }
  float getEndurance() const { return m_endurance; }
  int getStamina() const { return m_stamina; }
  float getVelocity() const { return m_velocity; }
  Vector2 getPosition() const { return m_position; }
  Gun *getGuns() { return m_guns; } // array de 3 armas
  int getNumBullets() { return num_bullets; }
  float getAngle() { return m_angle; }
  float getPitch() { return m_pitch; }
  Gun getActiveGun() {return m_guns[m_active_gun];}

  void setHealth(int health) { m_health = health; }
  void setEndurance(float endurance) { m_endurance = endurance; }
  void setStamina(int stamina) { m_stamina = stamina; }
  void setVelocity(float velocity) { m_velocity = velocity; }
  void setGun(int i, Gun g) { m_guns[i] = g; }

  void setPosition(Vector2 pos) { m_position = pos; }
  void setPosition(float x, float y) { m_position = {x, y}; }
  void setNumBullets(int i) { num_bullets = i; }

  // TODO: void update_player() → reescribir movimiento con ángulo + ratón (Camera3D)
  // TODO: void update_collision() → reescribir colisiones para 3D (plano XZ)

  void update_player(const EnemyManager& enemies, const Map& map);

private:
  int m_health;
  float m_endurance;
  int m_stamina;
  float m_velocity;
  Gun m_guns[3];
  Vector2 m_position;
  int num_bullets;
  int m_active_gun;

  float m_angle; //angulo horizontal
  float m_pitch; //inclinacion vertical
};
