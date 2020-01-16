
class Board {
  public:
  int black;
  int red;
  Board() {
    black = 9;
    red = 1;
  }
  int strike() {      // Strike - When a player pockets a coin he/she wins a point
    if (black == 0)
      return 0;

    black = black - 1;
    return 1;
  }
  int multistrike() {   //Multi-strike - When a player pockets more than one coin he/she wins 2 points. All, but 2 coins, that were pocketed, get back on to the carrom-board
    if (black == 0)
      return 0;

    black=black-2;
    return 2;
  }
  int redstrike() {  //Red strike - When a player pockets red coin he/she wins 3 points. If other coins arepocketed along with red coin in the same turn, other coins get back on to the carrom-board
    if (red == 0)
      return 0;

    red = red - 1;
    return 3;

  }
  int striker() {  //Striker strike - When a player pockets the striker he/she loses a point
    return -1;
  }
  int defunct() {  //Defunct coin - When a coin is thrown out of the carrom-board, due to a strike, the player loses 2 points, and the coin goes out of play
    if (black == 0)
      return 0;

    black = black - 1;
    return -2;
  }
  int emptyStrike() { //Empty Strike
    return 0;
  }
  bool coincheck() { 
    if (black == 0 && red == 0)
      return true;
    else
      return false;
  }
};
