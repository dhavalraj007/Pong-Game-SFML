#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Ball
{
    private:
            /* Properties of Bat (i.e What defines a Ball) */
            sf::Vector2f position;       // x,y position
            sf::RectangleShape ballShape;    // holds shape (width,height)
            // amount of change in postion(pixels) of ball in one frame
            float xVelocity;    
            float yVelocity;
 public:    
            Ball();
            Ball(float startX, float startY);    //Constructor

            /* Methods of Ball (i.e What can Ball do) */
            /* 
                What happens when the ball hits the side of the screen?
                What happens when the ball hits the bat or the top of the screen?
                What happens when the ball hits the bottom of the screen?
             */
            void reboundSides();
            void reboundBatOrTop(); 
            void hitBottom();
            void update();          //updates ball properites as needed

            //getters
            sf::RectangleShape getShape();      //returns shape in order to draw
            sf::FloatRect getPosition();        //returns bounds of ball in order to detect collision 
            float getXVelocity();               //returns x velocity


};