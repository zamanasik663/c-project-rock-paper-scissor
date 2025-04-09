#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int game(char you, char computer);  // function to implement the game

int main(){

    int n;  //random number stored
    char you,computer,result;
    
    srand(time(NULL));  //random number generate every time
    n = rand() % 100;   //random number generate at 0 - 99

    if(n < 33){
      
      computer = 's'; // if random number less than 33, computer variable stored stone(s)

    }else if(n > 33 && n < 66){
        computer = 'p';   // if random number 33 < n < 66, computer variable stored paper(p)
    }else{
        computer = 'z'; // if random number greater than 66, computer variable stored scissors(z)
    }
    
    //user input
    printf("\n\n\t\t\tEnter s for stone,p for paper,z for scissors:\n\n\t\t\t\t\t");
    scanf("%c",&you);

    //function call to play the game
    result = game(you,computer);

    if(result == -1){
       printf("\t\t\t\tGame Draw.\n");
    }else if(result == 1){
       printf("\t\t\t\tCongratulation!! You Won\n");
    }else{
        printf("\t\t\t\tYou lost\n");
    }

    printf("\t\t\t\tYou Choose %c and Computer choose %c\n",you,computer);

  return 0;
}

int game(char you, char computer)
{
    //if both the user and computer has choose the same thing
    if(you == computer){
       
       return -1;
    }

    // if user choose the stone(s) and computer choose the paper(p),computer win
    if(you == 's' & computer == 'p'){
      return 0;
    } else if(you == 'p' & computer == 's'){   // if user choose the paper(p) and computer    choose the stone(s),user win
        return 1;
    }

    // if user choose the stone(s) and computer choose the scissor(z),user win
    if(you == 's' & computer == 'z'){
      return 1;
    } else if(you == 'z' & computer == 's'){   // if user choose the scissor(z) and computer    choose the stone(s),computer win
        return 0;
    }

    // if user choose the paper(p) and computer choose the scissor(z),user win
    if(you == 'p' & computer == 'z'){
      return 0;
    } else if(you == 'z' & computer == 'p'){   // if user choose the scissor(z) and computer    choose the paper(p),user win
        return 1;
    }

}