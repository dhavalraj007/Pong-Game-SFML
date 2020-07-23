#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>



class Bat
{
    private:
            /* Properties of Bat (i.e What defines a Bat) */
            sf::Vector2f position;      // x,y position
            sf::RectangleShape batShape;    // holds shape (width,height)
            //as bat moves only in x direction we define speed as spped in x direction only
            float batSpeed;                 // amount of change in postion(pixels) of bat in one frame 
    public:
            Bat(float startX, float startY);    //Constructor

            /* Methods of Bat (i.e What can Bat do) */
            //as bat can move only in one dimension that is x we define move left and right only
            void moveLeft();        //moves bat to left
            void moveRight();       //moves bat to right
            void bringItOnLeft();
            void bringItOnRight();
            void increaseSpeed(float mult);
            void increaseSize(float mult);
            void update();          //updates bat properites as needed
            //getters
            sf::RectangleShape getShape();      //returns shape in order to draw
            sf::FloatRect getPosition();        //returns bounds of bat in order to detect collision with ball

};


