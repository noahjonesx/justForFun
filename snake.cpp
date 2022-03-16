#include <iostream> 
#include <cstdlib>
#include <stdlib.h>
#include <conio.h> //functionality to get characters from console window (keypresses etc.)
#include <windows.h> //provides functionalitity of sleep() function_
#include <time.h> //functionality to improve random function 


using namespace std;
//global variable end of game
bool gameOver;
//set game dimensions variables
const int width = 20;
const int height = 20;
//head position (x,y)
int x, y;
//fruit position (x,y)
int fruitX, fruitY;
//variable to keep track of score
int score;
//change direction of snake
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN} ;
//keep track of direction of snake
eDirection dir;
//create tail 
int tailX[100];
int tailY[100];
int nTail;

void setup(){
//set game variable to false to begin game 
gameOver = false;
dir = STOP;
//center snake on map to begin game
x = width / 2;
y = height / 2;
//spawn fruit at random location
fruitX = rand() % width;
fruitY = rand() % height;
//start score at zero 
score = 0;
}

void draw(){
    //clear screen
   system("cls;"); //system("clear") ~ for linux
    //display top border of map
   for (int i = 0; i < width; i++)
        cout << "$";
   cout << endl;

        //print left wall
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                //if right side of map
            if (j == 0)
                //print right wall
                cout << "$";
            //print snake head
            if (i == y && j == x)
                cout << "0";
            //print fruit
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else {
            bool print = false;

                //loop thru snake
                for (int k = 0; k < nTail; k++) {
                    //if current spot = j,i
                    //draw tail
                    if (tailX[k] == j && tailY[k] == i) {
                        //print body segment
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                cout << " ";
                
            }
            
            //if reaches other side of map
            if (j == width - 1)
                //print wall
                cout << "$";
            }
                cout << endl;
        }
    //display bottom border of map
    for (int i = 0; i < width; i++)
        cout << "$";
    cout << endl;
    //print score 
    cout << "Score: " << score << endl;
    
}

void input(){
    //function from conio.h library
    //if keyboard is pressed
    if (_kbhit()) {
        //return ASCII value of key pressed
        //handles player controls (WASD)
        switch (_getch()) {

            //left arrow
            case 'a':
                dir = LEFT;
                break;
            //right arrow
            case 'd':
                dir = RIGHT;
                break;
            //up arrow
            case 'w':
                dir = UP;
                break;
            //down arrow 
            case 's':
                dir = DOWN;
                break;
            //end game with x
            case 'x':
                gameOver = true;
                break;
        }
    }
}
void logic(){
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2x;
    int prev2y;
    tailX[0] = x;
    tailY[0] = y;
    //add segments
//start at slot begind head 
    for (int i = 1; i < nTail; i++) {
        prev2x = tailX[i];
        prev2y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2x;
        prevY = prev2y;
    }
    switch(dir) {
        case STOP:
            break;
        case LEFT:
            //decrease x coordinate of snake
            x--;
            break;
        case RIGHT:
        //increase x coordinate of snake
            x++;
            break;
        case UP:
        //increase y coordinate of snake
            y--;
            break;
        case DOWN:
        //decrease  y coordinate of snake
            y++;
            break;
        default:
            break;
    }
    //terminate game upon going out of bounds
    if (x > width || x < 0 || y > height || y < 0) 
        gameOver = true;
        //if head hits tail, end game
        //loop thrhough tail 
        for (int i = 0; i < nTail; i++) 
            if (tailX[i] == x && tailY[i] == y) 
                gameOver = true;
    //if fruit is reached, eat it and increase tail
    if (x == fruitX && y == fruitY) {
    //increase score
    score += 10;
    //respawn fruit 
    fruitX = rand() % width;
    fruitY = rand() % height;
    nTail++;
    }
}
int main() {
    //reset fruit spawn location 
    srand(time(NULL));
    //begin game 
    setup();
    //while gameOver = false
    while (!gameOver) {
        draw();
        input();
        logic();
        //Sleep(10);
        //linux = sleep(10);
        //improve speed and wall stability - source Youtube Comment @lalo24681
        if (dir == LEFT || dir == RIGHT) {
            //change speed of snake
            Sleep(25);
            }

        if (dir == UP || dir == DOWN) {
       //change speed of snake
            Sleep(25);
        }
    }
 return 0;   
}