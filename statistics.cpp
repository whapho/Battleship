//#include "Battleship.h"
//
//using namespace std;
//
//string getFormattedTime() {
//    time_t rawtime;
//    tm* timeinfo;
//    char buffer [80];
//    time(&rawtime);
//    timeinfo = localtime(&rawtime);
//    strftime(buffer,80,"%Y-%m-%d_%H.%M.%S",timeinfo);
//    return buffer;
//}
//
//void writePlayerBoards() {
//    string dateAndTime = getFormattedTime();
//    ofstream gameLog("game_log_" + dateAndTime + ".txt+");
//    int num;
//    gameLog << "   A B C D E F G H I J" << endl;
//    for (int i = 0; i < 10; i++) {
//        gameLog << DISPLAY[i];
//        for (int j = 0; j < 10; j++) {
//            num = *(playerOneBoard + i * COLS + j);
//            switch (num) {
//                case 0:
//                    gameLog << "* ";
//                    break;
//                case 1:
//                    gameLog << "* ";
//                    break;
//                case 2:
//                    gameLog << "* ";
//                    break;
//                case 3:
//                    gameLog << "* ";
//                    break;
//                case 4:
//                    gameLog << "* ";
//                    break;
//                case 5:
//                    gameLog << "* ";
//                    break;
//                case 6:
//                    gameLog << "M ";
//                    break;
//                case 7:
//                    gameLog << "H ";
//                    break;
//                default:
//                    break;
//            }
//        }
//        gameLog << endl;
//    }
//}
//
//void createGameLog() {
//    string dateAndTime = getFormattedTime();
//    ofstream gameLog("game_log_" + dateAndTime + ".txt+");
//}
//
