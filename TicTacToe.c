#include <stdio.h>
#include <stdlib.h>

char tile[10] = {'x','1','2','3','4','5','6','7','8','9'}; //Stores tile memory
int win = 0;    //sets win condition    


int board();    //displays graphical reprentation of board
int game();     //assigns appropriate mark to chosen tile based on turn, and handles invalid choices
int score();    //measures tile array against list of win conditions and adjusts int 'win' accordingly

int main(){
        printf("\n\t\t  WELCOME\n");
        board();
        printf("\n\n\t#############################\n\n");
        do{     //loops game until a win condition is met
        game();
        board();
        win = score();
        }

        while(win == 0);
        printf("\n\t\t GAME END!\n\n");
        return 0;
}
int game(){
        char choice[3];         //takes tile choice in first element
        char ch;                //stores first element to check respective tile state   
        int ch2;                //matches tile selection char to tile index
        char *ptr;
        static int i = 1;       //Keeps track of turn so that the appropriate tile selection mark is left.
        printf("\nEnter number of tile you want to claim: ");
        fgets(choice,3,stdin);
        ch = choice[0];
        ch2 = strtol(choice, &ptr, 10);
        if(ch2 < 1 | ch2 > 9){
                printf("\nNot a valid tile");
                char choice[3] = {0,0,0};
                return 0;}

        if ((ch == '1' | ch == '2' | ch == '3' | ch == '4' | ch == '5' | ch == '6' | ch == '7' | ch == '8' | ch == '9') && (*(tile + ch2) != 'X' && *(tile + ch2) != 'O'))
        {
                if(i % 2 == 0){                 //measures turn by parity of 'i', and assigns X and O to even and odd turns respectively.
                *(tile + ch2)  = 'X';}
                else *(tile + ch2) = 'O';
                i++;
                return 0;}
        else printf("\ninvalid af\n");
                return 0;
}
int score(){

        if (*(tile+1) == *(tile +2) && *(tile + 2) == *(tile +3)){
        return 1;
        }
        else if(*(tile+4) == *(tile +5) && *(tile +5) == *(tile +6)){
        return 1;
        }
        else if(*(tile +7) == *(tile +8) && *(tile +8) == *(tile +9)){
        return 1;
        }
        else if(*(tile +7) == *(tile +4) && *(tile +4) == *(tile +1)){
        return 1;
        }
        else if(*(tile +8) == *(tile +5) && *(tile +5) == *(tile + 2)){
        return 1;
        }
        else if(*(tile +9) == *(tile +6) && *(tile +6) == *(tile + 3)){
        return 1;
        }
        else if(*(tile +7) == *(tile +5) && *(tile +5) == *(tile +3)){
        return 1;
        }
        else if(*(tile +1) == *(tile +5) && *(tile +5) == *(tile +9)){
        return 1;
        }
        else
        return 0;
}

int board(){

        printf("\n\n");
        printf("\t\tTic Tac Toe\n\n");
        printf("\t\t %c | %c | %c ",*(tile+7),*(tile+8),*(tile+9));
        printf("\n");
        printf("\t\t-----------");
        printf("\n");
        printf("\t\t %c | %c | %c ",*(tile+4),*(tile+5),*(tile+6));
        printf("\n");
        printf("\t\t-----------");
        printf("\n");
        printf("\t\t %c | %c | %c \n\n\n",*(tile+1),*(tile+2),*(tile+3));

        return 0;
}
