#include "simple_shape.h"

void Rectangle::setpos(float left, float top, float right, float bottom){
    this->left=left;
    this->top=top;
    this->right=right;
    this->bottom=bottom;
}

void Circle::setpos(float x, float y, float radius){
    this->x=x;
    this->y=y;
    this->radius=radius;
}

float Rectangle::getarea(){
    return (top-bottom)*(right-left);
}

float Rectangle::getperimeter(){
    return 2*(top-bottom+right-left);
}

float Circle::getarea(){
    return PI*radius*radius;
}

float Circle::getperimeter(){
    return 2*PI*radius;
}
