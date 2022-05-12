#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Wall.h"
#include "Collider.h"
#include "Box.h"
#include "Switch.h"
#include <vector>

using namespace sf;
using namespace std;

//Walls will get in your way!
vector<Wall> WallMethod(int level)
{
    vector<Wall> wallList;
    //Standard Walls
    Wall topWall = Wall(Vector2f(800, 50), Vector2f(1600, 100));
    Wall leftWall = Wall(Vector2f(50, 800), Vector2f(100, 1600));
    Wall bottomWall = Wall(Vector2f(800, 1550), Vector2f(1600, 100));
    wallList.push_back(topWall);
    wallList.push_back(leftWall);
    wallList.push_back(bottomWall);

    //Level Specific walls
    //NOTE - The barrier wall will always be the last wall in the vector!

    if (level == 1)
    {
        Wall rightWall = Wall(Vector2f(1550, 200), Vector2f(100, 350));
        Wall rightWall2 = Wall(Vector2f(1550, 1100), Vector2f(100, 850));
        Wall barrier = Wall(Vector2f(1550, 525.0f), Vector2f(100, 300));
        Wall wall = Wall(Vector2f(800, 1000), Vector2f(1600, 100));
        Wall wall2 = Wall(Vector2f(800, 800), Vector2f(300, 100));
        Wall wall3 = Wall(Vector2f(700, 625), Vector2f(100, 450));
        Wall wall4 = Wall(Vector2f(900, 625), Vector2f(100, 450));
        Wall wall5 = Wall(Vector2f(800, 250), Vector2f(700, 100));
        
        wallList.push_back(rightWall);
        wallList.push_back(rightWall2);
        wallList.push_back(wall);
        wallList.push_back(wall2);
        wallList.push_back(wall3);
        wallList.push_back(wall4);
        wallList.push_back(wall5);
        wallList.push_back(barrier);
    }
    if (level == 2)
    {
        Wall rightWall1 = Wall(Vector2f(1550, 400), Vector2f(100, 600));
        Wall rightWall2 = Wall(Vector2f(1550, 1200), Vector2f(100, 600));
        Wall topLeft1 = Wall(Vector2f(400, 650), Vector2f(600, 100));
        Wall topLeft2 = Wall(Vector2f(650, 400), Vector2f(100, 600));
        Wall topRight1 = Wall(Vector2f(950, 400), Vector2f(100, 600));
        Wall topRight2 = Wall(Vector2f(1250, 650), Vector2f(600, 100));
        Wall bottomLeft1 = Wall(Vector2f(400, 950), Vector2f(600, 100));
        Wall bottomLeft2 = Wall(Vector2f(650, 1250), Vector2f(100,600));
        Wall bottomRight1 = Wall(Vector2f(1250, 950), Vector2f(600, 100));
        Wall bottomRight2 = Wall(Vector2f(950, 1200), Vector2f(100, 600));

        //Wall marker1 = Wall(Vector2f(1450, 800), Vector2f(100, 200));
        //Wall marker2 = Wall(Vector2f(150, 800), Vector2f(100, 200));
        //Wall marker3 = Wall(Vector2f(800, 150), Vector2f(200, 100));
        //Wall marker4 = Wall(Vector2f(800, 1450), Vector2f(200, 100));

        wallList.push_back(rightWall1);
        wallList.push_back(rightWall2);
        wallList.push_back(topLeft1);
        wallList.push_back(topLeft2);
        wallList.push_back(topRight1);
        wallList.push_back(topRight2);
        wallList.push_back(bottomLeft1);
        wallList.push_back(bottomLeft2);
        wallList.push_back(bottomRight1);
        wallList.push_back(bottomRight2);
    }

    return wallList;
}

//Create boxes!!
vector<Box> BoxMethod(int level, Texture& texture)
{
    vector<Box> boxList;

    //NOTE! In final release, the cords are 800, 700!
    if (level == 1)
    {
        Box box = Box(Vector2f(800, 700), texture);
        boxList.push_back(box);
    }

    if (level == 2)
    {
        Box box = Box(Vector2f(150, 100), texture);
        boxList.push_back(box);
        Box box2 = Box(Vector2f(1450, 150), texture);
        boxList.push_back(box2);
        Box box3 = Box(Vector2f(150, 1450), texture);
        boxList.push_back(box3);
        Box box4 = Box(Vector2f(1450, 1450), texture);
        boxList.push_back(box4);
    }
    
    return boxList;
}

//Switches will be made!
vector<Switch> SwitchMethod(int level, Texture& texture)
{
    vector<Switch> switchList;
    
    if (level == 1)
    {
        Switch switch1 = Switch(Vector2f(800, 150), texture);
        switchList.push_back(switch1);
    }
    if (level == 2)
    {
        Switch switch1 = Switch(Vector2f(550, 550), texture);
        switchList.push_back(switch1);
        Switch switch2 = Switch(Vector2f(1050, 550), texture);
        switchList.push_back(switch2);
        Switch switch3 = Switch(Vector2f(550, 1050), texture);
        switchList.push_back(switch3);
        Switch switch4 = Switch(Vector2f(1050, 1050), texture);
        switchList.push_back(switch4);
    }

    return switchList;
}

int main()
{
    RenderWindow window(sf::VideoMode(1600, 1600), "Maze Game");

    int level = 1;

    //Player texture
    Texture playerTexture;
    playerTexture.loadFromFile("morbius.jpg");

    //Box texture
    Texture boxTexture;
    boxTexture.loadFromFile("box.jpg");

    //Switch texture
    Texture switchTexture;
    switchTexture.loadFromFile("switch.jpg");
    
    Player player = Player(playerTexture);
    
    vector<Wall> wallList;
    wallList = WallMethod(level);

    vector<Box> boxList;
    boxList = BoxMethod(level, boxTexture);

    vector<Switch> switchList;
    switchList = SwitchMethod(level, switchTexture);

    bool openExit = false;
    bool openExit2 = true;

    float deltaTime = 0.0f;
    Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == Event::Closed)
                window.close();
        }

        window.clear();
        player.Update(deltaTime);
        
        //Wall collision
        for (int i = 0; i < wallList.size(); i++)
        {
            wallList[i].Draw(window);

            //Player running into wall
            wallList[i].GetCollider().CheckCollision(player.GetCollider(), 1.0f);

            for (int j = 0; j < boxList.size(); j++)
            {
                if (wallList[i].GetCollider().CheckCollision(boxList[j].GetCollider(), 1.0f))
                {
                    boxList[j].GetCollider().CheckCollision(player.GetCollider(), 1.0f);
                }
            }
        }
        
        //Player and box collision
        for (int i = 0; i < boxList.size(); i++)
        {
            boxList[i].Draw(window);
            //Box running into player
            player.GetCollider().CheckCollision(boxList[i].GetCollider(), 1.0f);

            //Player running into box
            boxList[i].GetCollider().CheckCollision(player.GetCollider(), 0.0f);
            
            player.Pulling(boxList[i], deltaTime);


            //Boxes colliding with each other
            for (int j = 0; j < boxList.size(); j++)
            {
                if (i != j)
                {
                    boxList[i].GetCollider().CheckCollision(boxList[j].GetCollider(), 0.0f);
                }
            }
        }

        //Switch collision
        for (int i = 0; i < switchList.size(); i++)
        {
            switchList[i].Draw(window);
            
            for (int j = 0; j < boxList.size(); j++)
            {
                //Check if the box is on the switch
                if (boxList[j].GetCollider().CheckCollision(switchList[i].GetCollider()))
                {
                    switchList[i].ChangeState(true);
                    break;
                }
                
                else
                {
                    switchList[i].ChangeState(false);
                }
            }
        }

        //Check if all the switches have been pressed
        int count = 0;

        for (int i = 0; i < switchList.size(); i++)
        {
            if (switchList[i].ReturnState() == true)
            {
                count += 1;
            }
        }

        if (count == switchList.size())
        {
            openExit = true;
        }
        else
        {
            openExit = false;
        }

        //Delete the barrier
        if (openExit == true && openExit2 == true)
        {
            wallList.pop_back();
            openExit2 = false;
        }

        //Bring the barrier back
        if (openExit == false && openExit2 == false)
        {
            if (level == 1)
            {
                wallList.push_back(Wall(Vector2f(1550, 525.0f), Vector2f(100, 300)));
            }

            else
            {
                wallList.push_back(Wall(Vector2f(1550, 800), Vector2f(100, 200)));
            }
            
            openExit2 = true;
        }

        //Go to the next level
        if (player.Finished())
        {
            player.MovePlayer(Vector2f(150, 800));

            level++;

            //Delete everything in the vectors
            wallList.clear();
            switchList.clear();
            boxList.clear();

            //Call the Methods to create new objects
            boxList = BoxMethod(level, boxTexture);
            wallList = WallMethod(level);
            switchList = SwitchMethod(level, switchTexture);
        }

        player.Draw(window);
        window.display();
    }
}
