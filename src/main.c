/******************************************************************************

                            	Fantasy Lied
                             by Pedro Ivo, 2024

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h> // Biblioteca PDCurses (curses pra windows)

// Variavéis
char currentRoom[10];      	    // Index da room atual
char player_move[10];           // Input do movimento do jogador
int player_hp = 10;             // Pontos de vida do jogador, se chegar a 0 ele morre
char name[9];                   // Nome do jogador

// Protótipos de função
void displayPlayerStats();
void handleMovement();
void generateCharacter();
void chapterOne();

int main(void) {
    // Inicializa PDCurses
    initscr();               // Inicia a tela
    cbreak();                // Desabilita line buffering
    keypad(stdscr, TRUE);    // Habilita caracteres especiais
    //noecho();              // Desativa a exibição de teclas pressionadas
	
	int input;
    do {
		curs_set(0);  // Esconde o cursor
		resize_term(40, 80);  // Muda o tamanho da janela, tem que estar acompanhado de um refresh()
        clear();
        mvprintw(0, 0, "********************************************************************************");
        mvprintw(1, 34, "Fantasy Lied");
        mvprintw(2, 31, "by Pedro Ivo, 2024");
        mvprintw(20, 36, "1) Play");
        mvprintw(21, 36, "2) Exit");
        mvprintw(39, 0, "********************************************************************************\n");
		refresh();  // Atualiza a tela

        // Recebe o input do jogador
        input = getch();

        if (input == '1') {
			curs_set(1);
            generateCharacter();
			
            do {
				printw("\n%s is in %s  |  HP: %d\n", name, currentRoom, player_hp);
				chapterOne();  // Capitulo 1
                refresh();
				if (player_hp <= 0) {
					mvprintw(20, 0, "YOU'RE DEAD. GAME OVER");
					refresh();
					napms(2000);
					break;
				}
            } while (strcasecmp(player_move, "exit") != 0);
        }
    } while (input != '2');
    mvprintw(14, 0, "\nExiting.");
    refresh();
    endwin();
    return 0;
}

// Criação de personagem e pequeno lore dump
void generateCharacter() {
    clear();
    mvprintw(0, 0, "Tell me, what's your name?");
	mvprintw(1, 0, "> ");
    refresh();
    scanw("%9s", name); 

    mvprintw(3, 0, "For millennia there existed a rich and prosperous land, some say it was the\n"
					"cradle of humanity and magic, however, with the attack and cruel regime of a\n"
					"thousand years of the Traitor Hero Matin'ornom, the archipelago of Solerania\n"
					"has disappeared.\n");
	
	mvprintw(7, 0, "It is said that whoever finds the Lost Realm can become King and possess what\n"
					"mages and scholars would kill to have: all the knowledge of Mundia.");
	
	mvprintw(10, 0, "Leaving his humble village, %s embarks on a journey to the Lost Realm.", name);
	refresh();
	mvprintw(13, 0, "Press Enter to continue.");
    refresh();
    getch();
}

// Capitulo 1
void chapterOne() {
	printw("You find yourself in the shore of a beach. The day is cloudy.\n");
	printw("You can hear the waves behind you, and in front of you there's two paths.\n");
	printw("Left or right?\n");
	
	while (1) {
        printw("> ");
        scanf("%9s", player_move);

        if (strcmp(player_move, "right") == 0) {
            printf("You choose right.\n");
            break; // Valid choice, exit the loop
        } else if (strcmp(player_move, "left") == 0) {
            printf("You choose left.\n");
            break; // Valid choice, exit the loop
        } else {
            printf("Invalid choice, try again.\n");
        }
    }
}
