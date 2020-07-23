#include"bat.h"

///////////////////-Constructor-//////////////////
//this constructor is called when object Bat is created
Bat::Bat(float startX,float startY)
{   
    //set shape(width,height)
    this->batShape.setSize(sf::Vector2f(60,10));

    //set initial Position
    this->position.x=startX;
    this->position.y=startY;
    this->batShape.setPosition(this->position);

    //set speed 
    this->batSpeed=0.6f;
};


///////////////////-Methods of bat-//////////////////
void Bat::moveLeft()
{   
    this->position.x -= this->batSpeed;
}

void Bat::moveRight()
{
    this->position.x += this->batSpeed;
}

///////////////////-Getters-//////////////////
sf::FloatRect Bat::getPosition()
{
     return this->batShape.getGlobalBounds();
}

sf::RectangleShape Bat::getShape()
{
     return this->batShape;
}

void Bat::increaseSpeed(float mult)
{
    this->batSpeed *= mult;
}
void Bat::increaseSize(float mult)
{
    this->batShape.setSize(sf::Vector2f(this->batShape.getSize().x*mult,this->batShape.getSize().y));
}

void Bat::bringItOnLeft()
{
    this->position.x=0;
}

void Bat::bringItOnRight()
{
    this->position.x=1024-60;
}
////////////////-Update-///////////////////
void Bat::update()
{
    this->batShape.setPosition(this->position);
}