    #include "guns.h"
    #include "../raylib-5.5_linux_amd64/include/raylib.h"


    class Player
    {
        public:
            Player()
                : m_health(100),
                m_endurance(100.0f),
                m_stamina(100),
                m_velocity(5.0f),
                m_aim_direction({1.0f, 0.0f}),
                m_position({0.0f, 0.0f})
            { }

            Player(int health, float endurance, int stamina, float velocity, Vector2 aim_direction, Vector2 position)
            {
                m_health = health;
                m_endurance = endurance;
                m_stamina = stamina;
                m_velocity = velocity;
                m_aim_direction = aim_direction;
                m_position = position;
            }

            ~Player() = default;

            int getHealth() const { return m_health; }
            float getEndurance() const { return m_endurance; }
            int getStamina() const { return m_stamina; }
            float getVelocity() const { return m_velocity; }
            Vector2 getAimDirection() const { return m_aim_direction; }
            Vector2 getPosition() const { return m_position; }
            Gun* getGuns() { return m_guns; } // array de 3 armas

            void setHealth(int health) { m_health = health; }
            void setEndurance(float endurance) { m_endurance = endurance; }
            void setStamina(int stamina) { m_stamina = stamina; }
            void setVelocity(float velocity) { m_velocity = velocity; }

            void setAimDirection(Vector2 dir) { m_aim_direction = dir; }
            void setPosition(Vector2 pos) { m_position = pos; }

            void setPosition(float x, float y)
            {
                m_position = { x, y };
            }
            //void setGun(Gun g) {  }

            void draw_player();
            void update_player();

        private:
            int m_health;
            float m_endurance;
            int m_stamina;
            float m_velocity;
            Gun m_guns[3];
            Vector2 m_aim_direction;
            Vector2 m_position;
    };