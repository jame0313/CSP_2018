#include "minimal_fighter.h"

int MinimalFighter::hp() const{
    return this->mHp;
}

int MinimalFighter::power() const{
    return this->mPower;
}

FighterStatus MinimalFighter::status() const{
    return this->mStatus;
}

void MinimalFighter::setHp(int _hp){
    this->mHp=_hp;
    this->setStatus();
}

void MinimalFighter::setStatus(){
    this->mStatus=(this->mHp>0)?Alive:Dead;
}

void MinimalFighter::hit(MinimalFighter *_enemy){
    bool isplayeralive=this->status()==Alive;
    bool isenemyalive=_enemy->status()==Alive;
    if(isenemyalive){
        int cnt_hp=this->hp()-_enemy->power();
        this->setHp(cnt_hp);
    }
    if(isplayeralive){
        int cnt_hp=_enemy->hp()-this->power();
        _enemy->setHp(cnt_hp);
    }
}

void MinimalFighter::attack(MinimalFighter *_target){
    if(this->status() == Alive){
        int cnt_hp=_target->hp()-this->power();
        _target->setHp(cnt_hp);
        this->mPower = 0;
    }
}

void MinimalFighter::fight(MinimalFighter *_enemy){
    while(this->status() == Alive && _enemy->status() == Alive)
        this->hit(_enemy);
}

