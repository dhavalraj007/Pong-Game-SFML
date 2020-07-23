#include"ball.h"

Ball::Ball()
{
     //set shape
    ballShape.setSize(sf::Vector2f(10, 10));
    //set random color
    ballShape.setFillColor(sf::Color(rand()%255,255,rand()%255,255));
   //set position
    position.x = rand() % 1024;
    position.y = rand()% 500;
    ballShape.setPosition(position);

    //set velocities
    xVelocity=0.3f;
    yVelocity=0.3f;
}

Ball::Ball(float startX, float startY)
{
    //set shape
    ballShape.setSize(sf::Vector2f(10, 10));

   //set position
    position.x = startX;
    position.y = startY;
    ballShape.setPosition(position);

    //set velocities
    xVelocity=0.3f;
    yVelocity=0.3f;
}

//////////Getters//////////
sf::FloatRect Ball::getPosition()
{
    return this->ballShape.getGlobalBounds();
}
 
sf::RectangleShape Ball::getShape()
{
    return this->ballShape;
}
 
float Ball::getXVelocity()
{
    return this->xVelocity;
}
//////////methods////////////

void Ball::reboundSides()
{
    xVelocity = -xVelocity;
}
void Ball::reboundBatOrTop()
{
    position.y -= (yVelocity * 30);
    yVelocity = -yVelocity;
 
}
void Ball::hitBottom()
{
    position.y = 1;
    position.x = 500;
}
///////////Update////////////
void Ball::update()
{
    // Update the ball position variables
    this->position.y += this->yVelocity;
    this->position.x += this->xVelocity;
    
    // Move the ball 
    this->ballShape.setPosition(this->position);
}