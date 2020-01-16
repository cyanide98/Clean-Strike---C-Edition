#include <iostream>
#include <string>
#include <conio.h>
#include "modules/Play.cpp"
#include "modules/Board.cpp"
using namespace std;


int main() {
  string score;
  int option;
  int result;
  cout << "Loading..." << endl;
  // Sleep(2000);
  system("CLS");
  cout << "Welcome To CleanStrike - Developed By Rishi Ramesh" << endl;
 // Sleep(1000);
  int player = 1;
  Board cleanstrikeboard;
  Play gameplayers;
  while (gameplayers.gamewin() != true) {
 system("CLS");
    player = (player + 1) % 2;
    if (((gameplayers.checkplaysc() == true) && (gameplayers.scoreddifference() >= 3)) || (
        cleanstrikeboard.coincheck())) {
      score = gameplayers.gameresult();
      cout << score << " won the game." << " Final Score: " << finalplay1sc << '-' << finalplay2sc;
      break;
    }

    cout << endl << "Player " << player + 1 << ": Choose an outcome from the list below" << endl;
    cout << "1. Strike" << endl;
    cout << "2. Multi Strike" << endl;
    cout << "3. Red Strike" << endl;
    cout << "4. Striker Strike" << endl;
    cout << "5. Defunct Coin" << endl;
    cout << "6. None" << endl;
    cout << "Current Score" << endl << "Player 1 Score: " << gameplayers.play1sc <<endl<< "Player 2 Score: " << gameplayers.play2sc;
    cout << endl << "Type Your Option";
    cin >> option;
    if(option!=1&&option!=2&&option!=3&&option!=4&&option!=5&&option!=6)
    {
    	cout<<endl<<"Wrong Option Try Again";
    	player = (player + 1) % 2;
    	continue;
	}
	if(cleanstrikeboard.red<1&&option==3)
	{
		cout<<endl<<"There are not enough red coins on the board";
		cout<<endl<<"Red coin left on board are: "<<cleanstrikeboard.red;
		getch();
		player = (player + 1) % 2;
    	continue;
	}
	if(cleanstrikeboard.black<2&&option==2 || cleanstrikeboard.black<1&&option==1  || cleanstrikeboard.black<=0&&option==5)
	{
		cout<<endl<<"There are not enough black coins on the board";
		cout<<endl<<"Black coin left on board are: "<<cleanstrikeboard.black;
		getch();
		player = (player + 1) % 2;
    	continue;
	}
    if (option == 1) {
      gameplayers.clearcount(player+1);
      result = cleanstrikeboard.strike();
      gameplayers.updateplaysc(player + 1, result);
      outcome = "Strike";
      gameplayers.history(player + 1);
    }
    if (option == 2) {
      gameplayers.clearcount(player+1);
      result = cleanstrikeboard.multistrike();
      gameplayers.updateplaysc(player + 1, result);
      outcome = "MultiStrike";
    
      gameplayers.history(player + 1);
    }
    if (option == 3) {
      gameplayers.clearcount(player+1);
      result = cleanstrikeboard.redstrike();
      gameplayers.updateplaysc(player + 1, result);
      outcome = "RedStrike";
      gameplayers.history(player + 1);

    }
    if (option == 4) {
      gameplayers.clearcount(player+1);
      result = cleanstrikeboard.striker();
      gameplayers.updateplaysc(player + 1, result);
      outcome = "StrikerStrike";
      gameplayers.history(player + 1);
      gameplayers.playerfoulcount(player + 1);

    }
    if (option == 5) {
      result = cleanstrikeboard.defunct();
      gameplayers.updateplaysc(player + 1, result);
      outcome = "Defunct";
      gameplayers.history(player + 1);
     gameplayers.playerfoulcount(player + 1);

    }
    if (option == 6) {
      result = cleanstrikeboard.emptyStrike();
      gameplayers.updateplaysc(player + 1, result);
      outcome = "Empty";
     gameplayers.playeremptymoves(player + 1);
      gameplayers.updateplayerhistory(player + 1);
 
    }
  }
  getch();
  return 0;
}
