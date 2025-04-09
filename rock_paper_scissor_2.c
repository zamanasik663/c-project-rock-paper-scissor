#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//function to implement the game
int game(char you,char computer);

int main(){


    int n; //random number declaration variable
    char you,computer,result;
    char ch = 'c';
   
        srand(time(NULL));  //random number generation
        n = rand() % 100;   // random number stored

        if(n < 33){  // if n is less than,computer stored stone(s)
            computer = 's';
        }else if(n > 33 && n < 66){
            computer = 'p';    //if 33 < n < 66, computer stored (p)
        }else{
            computer = 'z'; 
        } 
    

    while(ch != 'q'){

        //user input
        printf("\n\n\t\t\t\tEnter s for stone,p for paper,z for scissors: \n\n\t\t\t\t\t\t\t");
        scanf(" %c",&you);

        //calling the function to play the game
        result = game(you,computer);

        if(result == -1){
            printf("\t\t\t\t\tGame Draw.\n");
         }else if(result == 1){
            printf("\t\t\t\t\tCongratulation!! You Won\n");
         }else{
             printf("\t\t\t\t\tYou lost\n");
         }
     
         printf("\t\t\t\tYou Choose %c and Computer choose %c\n\n",you,computer);
         
         printf("\t\t\t\tif you continue game type(c),and if you quit game type(q):");
         scanf(" %c",&ch);

    }
    printf("\t\t\t\tThank you! for partcipate the game\n");



    return 0;
}

int game(char you,char computer)
{
    if(you == computer){  //user & computer as the same thing so that game is drawn
        return -1;
    }
    
    if(you == 's' && computer == 'p'){
      return 0; //if user chosse the stone(s) and computer choose the paper(p),so that computer is won
    }else if(you == 'p' && computer == 's'){
        return 1; //if user chosse the paper(p) and computer choose the stone(s),so that user won
    }


    if(you == 's' && computer == 'z'){
      return 1; //if user chosse the stone(s) and computer choose the scissors(z),so that user won
    }else if(you == 'z' && computer == 's'){
        return 0; //if user chosse the scissor(z) and computer choose the stone(s),so that computer won
    }


    if(you == 'p' && computer == 'z'){
      return 0; //if user chosse the paper(p) and computer choose the scissor(z),so that computer is won
    }else if(you == 'z' && computer == 'p'){
        return 1; //if user chosse the scissor(z) and computer choose the paper(p),so that user won
    }


}