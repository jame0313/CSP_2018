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
}

void MinimalFighter::setStatus(){
    this->mStatus=(this->mHp>0)?Alive:Dead;
}

void MinimalFighter::hit(MinimalFighter *_enemy){
    if(this->status()==Alive && _enemy->status()==Alive){
        this->setHp(this->hp() - _enemy->power());
        _enemy->setHp(_enemy->hp() - this->power());
    }
    else{
        if(this->status() == Alive)
            _enemy->setHp(_enemy->hp() - this->power());
        if(_enemy->status() == Alive)
            this->setHp(this->hp() - _enemy->power());
    }
    this->setStatus();
    _enemy->setStatus();
}

void MinimalFighter::attack(MinimalFighter *_target){
    if(this->status() == Alive){
        _target->setHp(_target->hp() - this->power());
        this->mPower = 0;
    }
    _target->setStatus();
}

void MinimalFighter::fight(MinimalFighter *_enemy){
    this->hit(_enemy);
    if(this->status() == Alive && _enemy->status() == Alive){
        return this->fight(_enemy);
    }
}

