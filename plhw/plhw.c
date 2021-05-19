#include <stdio.h>
#include <stdlib.h>
typedef struct
{
 char *word; //word and corresponding hint
 char *clue;
 int x; //Starting x and y positions
 int y;
 char direction; //H for horizontal, V for vertical
 int f; //solved or not
} Word_t;
Word_t* loadTextFile(FILE* myFile, int nrWords );
void displayBoard(int rows, int cols, char** myBoard);
int isBoardFilled(int rows, int cols, char** myBoard);
char** createArray(int rows, int cols);
int findIndex(int arr[], int size, int val);
void playGame(char** myBoard, int words, Word_t *array, int x, int y, int countToFinish);
char** updateBoard(char** myBoard, Word_t *words, int solve);

void main()
{
    char name[40];
    int rows,cols,nrWords;
    printf("Enter name of the file: ");
    scanf("%s", &name);
    FILE* file = fopen(&name,"r");
    fscanf(file,"%i",&rows);
    fscanf(file,"%i",&cols);
    fscanf(file,"%i",&nrWords);
    Word_t *array = (Word_t*) malloc(sizeof(Word_t)*nrWords);
    array = loadTextFile(file, nrWords);
    int i =0;
    char **board = createArray(rows, cols);
    int countToFinish = 0;
    playGame(board, nrWords, array, cols, rows, countToFinish);
    return 0;
}

Word_t* loadTextFile(FILE* myFile, int nrWords )
{
    Word_t* temp;
    char x;
    temp = (Word_t*) malloc(sizeof(Word_t)*nrWords);
   for(int i=0; i<nrWords; i++)
    {
        temp[i].word = (char*)malloc(sizeof(char)*255);
        temp[i].clue = (char*)malloc(sizeof(char)*255);
        //printf("()()()()()()()()()()()\n");
        fscanf(myFile," %c %d %d %s %[^\n]\n", &temp[i].direction, &temp[i].x, &temp[i].y,temp[i].word, temp[i].clue);
        temp[i].f = 0;
    }
    return temp;

}
char** createArray(int rows, int cols)
{
    int j,i;
    //printf("ğ\n");
    printf("%i %i",rows, cols);
    char** p;
    p =(char**) malloc(rows*sizeof(char*));
    for(i=0; i<rows; i++)
    {
        p[i] = (char*) malloc(sizeof(char)*cols);
        //printf("\n44");
    }
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            p[i][j] = '#';
        }
    }
    return p;
}
void displayBoard(int rows, int cols, char** myBoard)
{
    printf("        ");
    for(int i=0; i<cols; i++)
    {
        printf("  %i",i+1);
    }
    printf("\n");
    printf("        ");
    for(int i=0; i<cols; i++)
    {
        printf(" --");
    }
    for(int i=0; i<rows; i++)
    {
        printf("\n");
        printf("%i      |",i+1);
        for(int j=0; j<cols; j++)
        {
            printf("  %c",myBoard[i][j]);
        }
    }
}
int isBoardFilled(int rows, int cols, char** myBoard)
{
    for(int i=0;i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(myBoard[i][j]=='_') return 0;
        }
    }
    return 1;
}
char** updateBoard(char** myBoard, Word_t *words, int solve)
{
    int y = words[solve].x;
    int x = words[solve].y;
    if(words[solve].f == 0){
    int i;
    int len = strlen(words[solve].word);
    if(words[solve].direction == 'H'){
        for(i = 0; i<len; i++){
            myBoard[y-1][x -1 + i] = '_';
        }
    }
    else{
        for(i = 0; i<len; i++){
            myBoard[y - 1 + i][x - 1] = '_';
        }
    }
    }
    else
    {
    if(words[solve].direction == 'H')
        {
            for(int i=0; i<strlen(words[solve].word); i++)
            {
                myBoard[y-1][x -1 + i] = words[solve].word[i];
            }
        }
        else
        {
            for(int i=0; i<strlen(words[solve].word); i++)
            {
                myBoard[y - 1 + i][x - 1] = words[solve].word[i];
            }
        }
    }
    return myBoard;
}
void playGame(char** board, int words, Word_t *array, int x, int y, int countToFinish)
{
    char *dir;
    dir = (char*) malloc(sizeof(char)*15);
    char* ans = (char*) malloc(sizeof(char)*255);
    int val;
    for(int a=0; a<words; a++)
    {
        board = updateBoard(board,array,a);
    }
    printf("Game is %i rows x %i cols with %i words\nWords and clues are read!\n",y,x,words);
    while(countToFinish<words && 1 !=isBoardFilled(y,x,board))
    {
        printf("Current puzzle:\n");
        displayBoard(x,y,board);
        printf("\nAsk for hint:\n#  Direction   row   col\n-------------------------\n");
        for(int i=0; i<words;i++)
        {
            if(array[i].f==0)
            {
                //printf("%c",array[i].direction);
                //char* d= (char*) malloc(sizeof(char));
                //d = "H";
                if(array[i].direction == 'H') dir = "Horizontal";
                else dir = "Vertical  ";
                printf("%i: %s     %i     %i\n",i+1,dir,array[i].y, array[i].x);
            }
        }
        printf("Enter -1 to exit\nWhich word to solve next?: ");
        scanf("%d",&val);
        if(val==-1)exit(0);
        val = val - 1;
        printf("\nCurrent hint: %s\nEnter your solution: ",array[val].clue);
        scanf("%s",&ans);
        if(0==strcmp(&ans,array[val].word))
        {
            printf("Correct!");
            countToFinish = countToFinish + 1;
            array[val].f=1;
            board = updateBoard(board,array,val);
        }
        else
        {
            printf("WRONG!\n");
        }

    }
    printf("Congratulations! You beat the puzzle!");
}

