#include<stdio.h>
#include <ncurses.h>
#include "key.h"
#include <time.h>
#include "ball.h"
#include "air_hockey.h"
#include <stdlib.h>
#include <string.h>


// Main Game function
void air_hockey(){
    int zone_height, zone_width;
    struct timespec tim = {0,200000000};
    struct timespec tim_ret;
    int arrow, c;
    int slider_x_speed = 5, slider_y_speed = 5;
    int topPlayerScore = 0, bottomPlayerScore = 0;
    char pauseIn;
    int startedArrowKey, startedC, start = 0, pause = -1;
    initscr();
    getmaxyx(stdscr,zone_height, zone_width);
    zone_height-=1;
    zone_width-=1;
    zone_t *z = init_zone(0, 0, zone_width, zone_height);
    ball_t *b = init_ball(zone_width/2, zone_height/2, 2, 2);
    slider_t *top = init_slider(zone_width/2, 5, 'T');
    slider_t *bottom = init_slider(zone_width/2, zone_height-5, 'U');
    //menu where will come out of the loop if start is set to t aka t is pressed 
    while(!start){
    mvprintw((z->height)/2+2, (z->width)/5,"Welcome to Air Hockey !");
    mvprintw((z->height)/2 + 2, (z->width)/5,"Press (T/t) to Start Game\nInstructions:\n\nUse arrow keys for moving the bottom player  left, right, up, and down.\nUse w/W, a/A, s/S and d/D keys to move  the top player left, right, up and down.\npress p/p to pause the game\nPress q/q to quit the game");
    if ((startedArrowKey = read_escape(&startedC)) != NOCHAR){
      switch(startedArrowKey){
       // will change what t is set to 
        case t:
          start = 1;
          clear();
          refresh();
          break;
        default:
          start = 0;
          break;
        }
      }
    }
    draw_zone(z);
    draw_slider(top);
    draw_slider(bottom);
    draw_ball(b);
    refresh();
    nodelay(stdscr,TRUE);  // Do not wait for characters using getch.  
    noecho();
  while(1) {
       // Move the current piece 
    if ((arrow = read_escape(&c)) != NOCHAR) {
 
        switch (arrow) {

          // Functionality for Left Arrow Key that controls the bottom slider
          case LEFT:
            mvprintw(1, 5,"L");
            undraw_slider(bottom);
            moveSlider(bottom,bottom->upper_left_x-1,bottom->upper_left_y);
            draw_slider(bottom);
            break;
          // Functionality for Rigth Arrow Key that controls the bottom slider
          case RIGHT:
            mvprintw(1, 5,"R");
            undraw_slider(bottom);
            moveSlider(bottom,bottom->upper_left_x+1,bottom->upper_left_y);
            draw_slider(bottom);
            break;
         // functionality for going up bottom slider 
	  case UP:
            mvprintw(1, 5,"U");
            undraw_slider(bottom);
            moveSlider(bottom,bottom->upper_left_x,bottom->upper_left_y-1);
            draw_slider(bottom);
            break;
         // functionality for going down  bottom slider 
          case DOWN:
            mvprintw(1, 5,"D");
            undraw_slider(bottom);
            moveSlider(bottom,bottom->upper_left_x,bottom->upper_left_y+1);
            draw_slider(bottom);
            break;
          // Functionality for A Key that controls the top slider
          case A:
            mvprintw(1, 5,"A"); 
            undraw_slider(top);
            moveSlider(top,top->upper_left_x-1,top->upper_left_y);
            draw_slider(top);
            break; 
          case D:
          // Functionality for D Key that controls the top slider
            mvprintw(1, 5,"D");
            undraw_slider(top);
            moveSlider(top,top->upper_left_x+1,top->upper_left_y);
            draw_slider(top);
            
            break;
          case W:
            // Function Key w  that controls the top
            mvprintw(1, 5,"W");
            undraw_slider(top);
            moveSlider(top,top->upper_left_x,top->upper_left_y-1);
            draw_slider(top);
            break;
          case S:
            // Functionality for S Key that controls the top
            mvprintw(1, 5,"S");
            undraw_slider(top);
            moveSlider(top,top->upper_left_x,top->upper_left_y+1);
            draw_slider(top);
            break;
          case P:
          // Functionality for P  pauses the game
            pauseIn = fgetc(stdin);
            while(pauseIn != 'p'){
              pauseIn = fgetc(stdin);
              if(pauseIn == 'q'){
                mvprintw((z->height)/2, (z->width)/2,"Goodbye");
                refresh();
                sleep(5);
                endwin();
              }
            }
            break;
          case Q:
          // Functionality for Q Key that controls quitting the game
            mvprintw((z->height)/2, (z->width)/2,"Goodbye");
            refresh();
            sleep(5);
            endwin();
            return;
          case PLUS:
            undraw_zone(z);
            zone_width = (int) zone_width + (zone_width * .1);
            zone_height = (int) zone_height + (zone_height * .1);
            z = init_zone(0, 0, zone_width, zone_height);
            draw_zone(z);
            break;
          case MINUS:
            undraw_zone(z);
     	    zone_width = (int) zone_width - (zone_width * .1);
       	    zone_height = (int) zone_height - (zone_height * .1);
            z = init_zone(0, 0, zone_width, zone_height);
       	    draw_zone(z);
       	    break;
          default:
            mvprintw(1, 5,"%c", c);
            break;
          
        }
      } 
    refresh();
    undraw_zone(z);
    draw_zone(z);
    undraw_ball(b);
    moveBall(b);
    checkCollisionSlider(bottom, b);
    checkCollisionSlider(top, b);
    checkCollisionWithZone(b, z);
    // collision with goal checker for later
    if(checkCollisionTopGoalZone(b,z)){
      topPlayerScore++;
    }else if(checkCollisionBottomGoalZone(b,z)){
      bottomPlayerScore++;
    }else{
      draw_ball(b);
    }
    draw_ball(b);
    // prints the score later on 
    mvprintw(1,10,"Top Player Score:   %d\n  Bottom Player Score:   %d", topPlayerScore,bottomPlayerScore);
    refresh();
    // usleep(200000);
    nanosleep(&tim, &tim_ret);
  }

    
}
