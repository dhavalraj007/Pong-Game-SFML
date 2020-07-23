#include<iostream>
#include<ctime>
#include<vector>
#include<SFML/Graphics.hpp>
#include"bat.h"
#include<sstream>
#include"ball.h"

using namespace sf;


    int main()
    {
        srand(static_cast<unsigned int>(time(NULL)));
        int windowWidth=1024;
        int windowHeight=768;
        
        int score = 1;
        int lives = 10;

        //create a Window
        RenderWindow window(VideoMode(windowWidth,windowHeight),"Pong!");
        //create a bat
        Bat bat(windowWidth/2,windowHeight-20);
        //create a ball vector
        std::vector<Ball> ball={Ball()};

        //text for hud
        Text hud;
        //text for Game Over
        Text gameover;
        //font
        Font font;
        font.loadFromFile("DS-DIGIT.ttf");
        //text settings
        hud.setFont(font);
        hud.setCharacterSize(75);
        hud.setFillColor(sf::Color::White);
        //text settings
        gameover.setFont(font);
        gameover.setPosition(windowWidth/2-200,windowHeight/2-200);
        gameover.setCharacterSize(70);
        gameover.setFillColor(sf::Color::White);
        gameover.setString("Game Over!\n play again?\n Y or N");
        bool wantToPlay=true;
        bool donePushing=false;

        while (window.isOpen())
        {
            /*
                Handle the player input
                *********************************************************************
            */
            Event event;
            while (window.pollEvent(event))
            {
                switch(event.type)
                {				
                    case Event::Closed:
                    window.close();
                }
            }

            if(wantToPlay==true)        //if wanToPlay==false movement of bat,ball , ball rebound , HUDtext is off
            {   
                if(score%4==0 && donePushing==false)
                {
                    ball.push_back(Ball());
                    bat.increaseSize(1.1);
                    bat.increaseSpeed(1.04);
                    donePushing=true;
                }
                else if(ball.size()==0)
                {
                    ball.push_back(Ball());
                }
                if(Keyboard::isKeyPressed(Keyboard::Left))
                {   
                    bat.moveLeft();
                }
                if( bat.getPosition().left+60 < 0)
                {
                    bat.bringItOnRight();
                }
                if(Keyboard::isKeyPressed(Keyboard::Right) )
                {
                    bat.moveRight();
                }
                if(bat.getPosition().left > windowWidth)
                {
                    bat.bringItOnLeft();                    
                }
                if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                window.close();
                }
                /*
                Update the frame
                *********************************************************************
                */
    
                // Handle ball hitting the top
                for(auto b=ball.begin(); b<ball.end();b++)
                {
                if(b->getPosition().top < 0)
                {
                    b->reboundBatOrTop();
                    score++;
                    donePushing=false;
                }
                // Handle ball hitting the bottom
                if(b->getPosition().top > windowHeight)
                {
                    b->hitBottom();
                    ball.erase(b);
                    //decrease life
                    lives--;
                }
                // Handle ball hitting the size
                if(b->getPosition().left < 0 || b->getPosition().left+10 > windowWidth)
                {
                    b->reboundSides();
                }
                // Has the ball hit the bat?
                if(b->getPosition().intersects(bat.getPosition()))
                {
                    b->reboundBatOrTop();
                }

                b->update();
                }
                bat.update();
                // Update the HUD text
                std::stringstream ss;
                ss<<"Score:"<<score<<"   Lives:"<<lives;
                hud.setString(ss.str());

            }//end of if
            //Game Win condition
            if(bat.getShape().getSize().x > windowWidth*0.85)
            {
                break;
            }
            //Game over condition
            if(lives < 1)           
            {   
                wantToPlay=false;
                if(Keyboard::isKeyPressed(Keyboard::Y))
                {
                    lives=10;    //reset lives
                    score=0;    //reset score
                    ball.resize(1);
                    wantToPlay=true;
                }
                else if(Keyboard::isKeyPressed(Keyboard::N))
                {
                    window.close();
                }
            }
             /*
            Draw the frame
            *********************************************************************
            */
    
            // Clear everything from the last frame
            window.clear(Color(255,53,94,255));

            if(wantToPlay==true)
            {
                window.draw(bat.getShape());
                for(auto &b:ball)
                window.draw(b.getShape());
                // Draw our hud
                window.draw(hud);
            }
            else
            {
                window.draw(gameover);
            }
    
            // Show everything we just drew
            window.display();

        }
        return 0;
    }