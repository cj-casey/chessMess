#include <iostream>
#include "CLI11.hpp"
#include <string>
#include <string.h>
#include <fstream>
#include <unordered_map>

using namespace std;

std::unordered_map<char, std::string> chess_map = {
    {'R', "\u2656"},
    {'N', "\u2658"},
    {'B', "\u2657"},
    {'Q', "\u2655"},
    {'K', "\u2654"},
    {'P', "\u2659"},
    {'r', "\u265C"},
    {'n', "\u265E"},
    {'b', "\u265D"},
    {'q', "\u265B"},
    {'k', "\u265A"},
    {'p', "\u265F"},
    {'0', "\u2592"},  // Mapping '0' to not a space
    {'|', "|"}   // Mapping '|' to itself
};



char** boardRead()
{
	char **board = new char*[8];
	string line;
	ifstream readBoard("board.txt");

	for(int i = 0; i < 8; i++)
	{
		board[i] = new char[13];
	}

	for(int i = 0; i < 8; i++)
	{ 
		readBoard >> line;
		for(int j = 0; j < 13; j++)
		{
			board[i][j] = line[j]; 	
		}
	}
	readBoard.close();
	return board;
}

void boardWrite(char** s)
{
	ofstream writeBoard("board.txt");
	
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 13; j++)
		{

			writeBoard<<s[i][j];
		}
		writeBoard << std::endl;
	}
	writeBoard.close();

}

bool isSameTeam(char piece, char piece2)
{
	//if(1){std::cout<<"p1"<<piece<<(int)piece<<" p2"<<piece2<<(int)piece2<<std::endl;}
	if((piece > 64) && (piece < 91))
	{
		if ((piece2 > 64) && (piece2 < 91))
		{
			return true;
		}
		else
			return false;
	}
	else if ((piece > 96) && (piece < 123))
	{
		if((piece2 > 96) && (piece2 < 123))
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
void resetBoard()
{
	ofstream resetBoard("board.txt");
	


	resetBoard << "RNBQKBNR|0000"<<endl;
	resetBoard << "PPPPPPPP|0000"<<endl;
	resetBoard << "00000000|0000"<<endl;
	resetBoard << "00000000|0000"<<endl;
	resetBoard << "00000000|0000"<<endl;
	resetBoard << "00000000|0000"<<endl;
	resetBoard << "pppppppp|0000"<<endl;
	resetBoard << "rnbqkbnr|0000"<<endl;
	resetBoard.close();

}
void show(char **board){
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 13; j++)
		{

			std::cout<<chess_map[board[i][j]];
		}
		std::cout<<std::endl;


	}
}
	
int main(int argc, char** argv) {

	int debug = 0;
	char piece;
	vector<string> move_args;
	int move_init_x, move_init_y, move_final_x,move_final_y;
	int shadow_x = 0,shadow_y = 9;

    CLI::App app{"ChessMess"};

     bool showFlag = false;
    app.add_flag("--show", showFlag, "Show option");


   auto mv = app.add_option("--mv", move_args, "Move from <from> to <to>")->expected(2);
   
	
	bool reset = false;
	app.add_flag("--reset",reset,"Resets Board");



    bool overridez = false;
    app.add_flag("--override", overridez, "Override option");

    bool unlock = false;
    app.add_flag("--unlock", unlock, "Unlock option");

    CLI11_PARSE(app, argc, argv);

     if(reset)
    {
	resetBoard();
    }
char **board = boardRead();

//if(move_args.size() == 2){mv = 0;}
if(mv->count() == 2)
{

	if(debug){std::cout<<"mv true"<<std::endl;}
	move_init_x  = move_args[0][0] - '0';
	move_init_y  = move_args[0][1] - '0';
	move_final_x = move_args[1][0] - '0';
	move_final_y = move_args[1][1] - '0';
	
	//std::cout<<move_init_x<<move_init_y<<move_final_x<<move_final_y<<std::endl;
	
	// Check bounds
	if(!((((int) move_init_x) < 8) && (((int) move_init_y) < 8) && (((int) move_final_x) < 8) && (((int) move_final_y) < 8))) {
		return 1;
	}
	if(debug){std::cout<<"in bounds"<<std::endl;}
	// grab piece
	piece = (char) board[(int)move_init_x][(int)move_init_y];

	if(!overridez){
		if(isSameTeam(piece,((char) board[(int)move_final_x][(int)move_final_y]))){
			// Not allowed to plop boiz onto your teammates
			return 1;
		}
		if(move_init_y > 7 || move_final_y > 7){
			// Can't move into the shadow realm
			// TODO: resurrecting pieces should be okay sometimes
			return 1;
		}
	}
	if(debug){show(board);}
	//shadow realm handling
	if(board[move_final_x][move_final_y] != '0')
	{
		if(debug){std::cout<<"moving to non empty space"<<std::endl;}
		int shadow = 0;
		// So the shadow realm starts in column i a.k.a. column 9
		if(debug){std::cout<<"shadow slot "<<shadow<<" is "<<board[shadow%8][9+shadow/8]<<std::endl;}
		while(board[shadow%8][9+shadow/8] != '0'){
			if(debug){std::cout<<"shadow slot "<<shadow<<" is "<<board[shadow%8][9+shadow/8]<<std::endl;}
			shadow++;
		}
	
		if(debug){std::cout<<"shadow slot "<<shadow<<" is open"<<std::endl;}
		// At this point, shadow should be >=0 and <32 and point to the first '0'
		// cell in the shadow realm
		board[shadow%8][9+shadow/8] = board[move_final_x][move_final_y];
		//
		//
		//board[shadow_x][shadow_y] = board[move_final_x][move_final_y];
		//shadow_x++;
		//if(shadow_x > 7)
		//{
		//shadow_x = 0;
		//shadow_y++;
		//}	
	}

	board[(int)move_final_x][(int)move_final_y] = piece;
	board[(int)move_init_x][(int)move_init_y] = '0';
	//show(board);
}
boardWrite(board);
if(showFlag)
{
	    show(board);
}

return 0;
}
