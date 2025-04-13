#include <curses.h>
#include <stdio.h>

int
main()
{
  char main_character = '@';
  int cols, rows;

  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(2);

  int main_ch_pos_x = COLS / 2 / 2;
  int main_ch_pos_y = LINES / 2.5;

  getmaxyx(stdscr, rows, cols);
  char map[rows][cols];
  
  for(;;){       
    for(int y = 0; y < rows; y++){
      for(int x = 0; x < cols; x++){
	map[y][x] = '#';
	mvaddch(y, x, '#');
      }
    }
    
    for(int y = 11; y < rows / 2; y++){
      for(int x = 17; x < cols / 2; x++){
	map[y][x] = ' ';
	mvaddch(y, x, ' ');
      }
    }
    
    mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
    move(main_ch_pos_y, main_ch_pos_x);
    int input = getch();


    /*movement*/
    if(input == KEY_LEFT && map[main_ch_pos_y][main_ch_pos_x - 1] == ' '){
      mvaddch(main_ch_pos_y, main_ch_pos_x, ' ');
      refresh();

      main_ch_pos_x -= 1;
      mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
      move(main_ch_pos_y, main_ch_pos_x);
    }

    if(input == KEY_RIGHT && map[main_ch_pos_y][main_ch_pos_x + 1] == ' '){
      mvaddch(main_ch_pos_y, main_ch_pos_x, ' ');
      refresh();

      main_ch_pos_x += 1;
      mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
      move(main_ch_pos_y, main_ch_pos_x);
    }

    if(input == KEY_UP && map[main_ch_pos_y - 1][main_ch_pos_x] == ' '){
      mvaddch(main_ch_pos_y, main_ch_pos_x, ' ');
      refresh();

      main_ch_pos_y -= 1;
      mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
       move(main_ch_pos_y, main_ch_pos_x);
    }
	
    if(input == KEY_DOWN && map[main_ch_pos_y + 1][main_ch_pos_x] == ' '){
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
