#include <curses.h>
#include <stdio.h>

int
main()
{
  char main_character = '@';

  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(2);

  int main_ch_pos_x = COLS / 2;
  int main_ch_pos_y = LINES / 2;
  
  
  for(;;){  
    mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
    move(main_ch_pos_y, main_ch_pos_x);
    int input = getch();

    /*movement*/
    if(input == KEY_LEFT){
      mvaddch(main_ch_pos_y, main_ch_pos_x, ' ');
      refresh();

      main_ch_pos_x -= 1;
      mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
      move(main_ch_pos_y, main_ch_pos_x);
    }

    if(input == KEY_RIGHT){
      mvaddch(main_ch_pos_y, main_ch_pos_x, ' ');
      refresh();

      main_ch_pos_x += 1;
      mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
      move(main_ch_pos_y, main_ch_pos_x);
    }

    if(input == KEY_UP){
      mvaddch(main_ch_pos_y, main_ch_pos_x, ' ');
      refresh();

      main_ch_pos_y -= 1;
      mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
       move(main_ch_pos_y, main_ch_pos_x);
    }
	
    if(input == KEY_DOWN){
      mvaddch(main_ch_pos_y, main_ch_pos_x, ' ');
      refresh();

      main_ch_pos_y += 1;
      
      mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
      move(main_ch_pos_y, main_ch_pos_x);
    }

    

    if(input == 27)
      break;
    
  }
  endwin();
  return 0;
}

