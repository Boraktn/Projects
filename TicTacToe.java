import java.io.IOException;
import java.util.Scanner;

public class TicTacToe {

	public static void main(String[] args) throws IOException {
		Scanner reader = new Scanner(System.in);
		char[][] board = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };


		
		printBoard(board);
		
		
		int moveC = 0;
		int player = 1;
		while(moveC<9){
			
		System.out.print("Player " + player + "enter row number:");
		int row = reader.nextInt();
		System.out.print("Player " +player + "enter column number:");
		int col = reader.nextInt();
		if (row >0 && row <4 && col>0 && col<4 && board[row - 1][col - 1] == ' '){
		if(player == 1) board[row - 1][col - 1] = 'X';
		else board[row - 1][col - 1] = 'O';
		printBoard(board);
		boolean win = checkBoard(board, row - 1, col -1);
		if(win == true){
			System.out.println("Player "+ player + " has won the game");
			break;
		}
		if(player == 1) player++;
		else player = player - 1;
		moveC++;
		}
	}
	reader.close();
	}
	public static boolean checkBoard(char[][] board, int row, int col){
		
		char symbol = board[row][col];
		//boolean win = true;
		for(int i =0; i<3; i++){
			if(symbol != board[row][i]) break;
			if(i ==2) return true;
		}
		for(int i=0; i<3; i++){
			if(symbol != board[i][col]) break;
			if(i ==2) return true;
		}
		if(row == col){
		for(int i=0; i<3; i++){
			if(symbol != board[i][i]) break;
			if(i==2) return true;
		}}
		if(row + col == 2){
			for(int i=0;i<3;i++){
				if(symbol != board[i][2-i]) break;
				if(i==2) return true;
			}
		}
		return false;
	}
	public static void printBoard(char[][] board) {
		System.out.println("    1   2   3");
		System.out.println("   -----------");
		for (int row = 0; row < 3; ++row) {
			System.out.print(row + 1 + " ");
			for (int col = 0; col < 3; ++col) {
				System.out.print("|");
				System.out.print(" " + board[row][col] + " ");
				if (col == 2)
					System.out.print("|");

			}
			System.out.println();
			System.out.println("   -----------");

		}

	}

}