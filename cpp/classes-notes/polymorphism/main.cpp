#include <iostream> 

class Enemy {
    protected: 
        int attackPower;
    public:
        void setAttackPower(int power) { attackPower = power;}
        virtual void attack(){}
    
};

class Ninja : public Enemy {
    public:
        void attack()
        {
            std::cout << "Ninja Attack With Power " << attackPower << std::endl;
        }
};

class Monster : public Enemy {
    public:
        void attack()
        {
            std::cout << "Monster Attack With Power " << attackPower << std::endl;
        }
};

int main()
{
    Ninja ninja;
    Monster zombie;
    Enemy *enemy1 = &ninja;
    Enemy *enemy2 = &zombie;
    enemy1 -> setAttackPower(25);
    enemy1 -> attack();

    enemy2 -> setAttackPower(34);
    enemy2 -> attack();

    return 0;
}