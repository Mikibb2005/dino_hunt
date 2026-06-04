#include "../include/player.h"
#include "../include/map.h"
#include "../include/enemy.h"
#include <math.h>

#include <cstdio>

void Player::update_player(const EnemyManager& enemies, const Map& map/*, const DinoManager& dinos*/)
{
    (void)enemies; // Silenciar warnings hasta reimplementar colisiones
    (void)map;
    //(void)dinos;

    //update arma
    m_guns[m_active_gun].update_gun(GetFrameTime());

    //TODO: update_collision();


    Vector2 mouse_delta = GetMouseDelta();
    
    float sensitivity = 0.003f;
    m_angle += mouse_delta.x * sensitivity;
    m_pitch -= mouse_delta.y * sensitivity;

    if (IsGamepadAvailable(0)) 
        {
        float rx = GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_X);
        float ry = GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_Y);
        if (std::fabs(rx) > 0.15f)
        {
            m_angle += rx * 3.0f * GetFrameTime();
        }
        if (std::fabs(ry) > 0.15f) 
        {
            m_pitch -= ry * 3.0f * GetFrameTime();
        }
    }

    const float max_pitch = 85.0f * DEG2RAD; 
    if (m_pitch > max_pitch)
    {
        m_pitch = max_pitch;
    } 
    if (m_pitch < -max_pitch)
    {
        m_pitch = -max_pitch;
    }

    float move_forward = 0.0f;
    float move_strafe = 0.0f;

        
    // 1. Lectura del Teclado
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        move_forward += 1.0f;
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        move_forward -= 1.0f;
    }
    if (IsKeyDown(KEY_A))
    {
        move_strafe -= 1.0f;
    }
    if (IsKeyDown(KEY_D))
    {
        move_strafe += 1.0f;
    }

    // 2. Lectura del Mando (Stick Izquierdo)
    if (IsGamepadAvailable(0)) 
    {
        float stick_x = GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X);
        float stick_y = GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y);


        const float deadzone = 0.15f;
        if (std::fabs(stick_x) > deadzone)
        {
            move_strafe += stick_x;
        }
        if (std::fabs(stick_y) > deadzone)
        {
            move_forward -= stick_y;
        }
    }

    // Normalizar el vector de entrada
    float length = std::sqrt(move_forward * move_forward + move_strafe * move_strafe);
    if (length > 1.0f) 
    {
        move_forward /= length;
        move_strafe /= length;
    }

    float dt = GetFrameTime();
    float speed = m_velocity * 60.0f * dt; 

    Vector2 dir_forward = { std::cos(m_angle), std::sin(m_angle) };
    Vector2 dir_right   = { -std::sin(m_angle), std::cos(m_angle) };

    Vector2 velocity;
    velocity.x = (dir_forward.x * move_forward + dir_right.x * move_strafe) * speed;
    velocity.y = (dir_forward.y * move_forward + dir_right.y * move_strafe) * speed;


    m_position.x += velocity.x;
    m_position.y += velocity.y;

    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_2))
    {
        printf("Aprieta el gatillo...\n");
        if(m_guns[m_active_gun].can_fire())
        {
            m_guns[m_active_gun].attack();
            printf("Dispara!!\n");
        }
        else 
        {
            printf("FALLAAA!!\n");
        }
    }   
    if(IsKeyPressed(KEY_R) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_LEFT))
    {
        m_guns[m_active_gun].reload();
        printf("Recargando %d balas... \n", m_guns[m_active_gun].getChargerSize());
    }
}
