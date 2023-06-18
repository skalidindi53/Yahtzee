
/****************************
 * HEADER
 *
 * Starter code provided by: Dr. Sara Riazi
 * ***************************/


#include <string>
#include <iostream>
#include <stdlib.h> 
#include <stdio.h>
#include <iomanip>

using namespace std;



//#################################################################################################



class Dice{
	private:
		int value;
	
	public:

		//Randomly assigns a value between from 1 to 6 to the dice.
		void roll(){
             value = rand() % 6 + 1;
        }

        int reveal(){
            return value;
        }

		//The autograder will set the values directly instead of calling roll() to avoid randomness!
		void setValue(int value){
            this->value = value;
        }


};


//#################################################################################################

const int HAND_SIZE = 5;

class Hand {
	public:
        Dice dice[HAND_SIZE];

		//Display the value of the five dice
		void show(){
            for(int i = 0; i < HAND_SIZE; i++){
                //cout << dice[i].reveal() << " ";
            }
            //cout << endl;
        }

		void play(){
            for(int i = 0; i < HAND_SIZE; i++){
                dice[i].roll();
            }
        }

        Dice* getDice(int diceNum){
            return &dice[diceNum];
        }
		
		//selection is the string of dice numbers that the player wants to keep.
		//For example, "125" means that player wants to keep the first, second, and fifth dice, and roll the rest.
		void setSelection(string selection){
            for(int i = 0; i < HAND_SIZE; i++){
                bool found = false;
                for(int j = 0; j < selection.length(); j++){
                    if(i == selection[j] - '1'){
                        found = true;
                        break;
                    }
                }
                if(!found){
                    dice[i].roll();
                }
            }
        }



    Hand(){
        for(int i = 0; i < HAND_SIZE; i++){
            dice[i].roll();
        }
    }

private:

};



//######################################################################


//List of rows in the board
const int ONES = 0;
const int TWOS = 1;
const int THREES = 2;
const int FOURS = 3;
const int FIVES = 4;
const int SIXES = 5;
const int THREE_OF_KIND = 6;
const int FOUR_OF_KIND = 7;
const int FULL_HOUSE = 8;
const int SMALL_STRAIGHT = 9;
const int LARGE_STRAIGHT = 10;
const int CHANCE = 11;
const int YAHTZEE = 12;

const int BOARD_SIZE=13; 

class Game {

	public:
		//calcScore returns a score of a hand (5 dice) for given row in the board. 
		//Note the rows are indexed from zero. 
		//For example if the hand is 2 1 1 5 1 then calcScore(hand, ONES) returns 3 and  calcScore(hand, TWOS) returns 2.
		int calcScore(Hand* hand, int row){
            int score = 0;
            int sum = 0;
            int count =0;
            int tempCount = 0;
            bool isDuplicate = false;
            int duplicateCount = 0;
            int temp;
            int arr [5] = {hand->getDice(0)->reveal(), hand->getDice(1)->reveal(), hand->getDice(2)->reveal(), hand->getDice(3)->reveal(), hand->getDice(4)->reveal()};
            switch(row){
                case ONES:
                    for(int i = 0; i < HAND_SIZE; i++){
                        if(hand->getDice(i)->reveal() == 1){
                            count++;
                        }
                    }
                    score = count;
                    break;
                case TWOS:
                    for(int i = 0; i < HAND_SIZE; i++){
                        if(hand->getDice(i)->reveal() == 2){
                            count++;
                        }
                    }
                    score = count * 2;
                    break;
                case THREES:
                    for(int i = 0; i < HAND_SIZE; i++){
                        if(hand->getDice(i)->reveal() == 3){
                            count++;
                        }
                    }
                    score = count * 3;
                    break;
                case FOURS:
                    for(int i = 0; i < HAND_SIZE; i++){
                        if(hand->getDice(i)->reveal() == 4){
                            count++;
                        }
                    }
                    score = count * 4;
                    break;
                case FIVES:
                    for(int i = 0; i < HAND_SIZE; i++){
                        if(hand->getDice(i)->reveal() == 5){
                            count++;
                        }
                    }
                    score = count * 5;
                    break;
                case SIXES:
                    for(int i = 0; i < HAND_SIZE; i++){
                        if(hand->getDice(i)->reveal() == 6){
                            count++;
                        }
                    }
                    score = count * 6;
                    break;
                case THREE_OF_KIND:
                    if(hand->getDice(0)->reveal() == hand->getDice(1)->reveal() && hand->getDice(1)->reveal() == hand->getDice(2)->reveal()){
                        score = hand->getDice(0)->reveal() + hand->getDice(1)->reveal() + hand->getDice(2)->reveal() + hand->getDice(3)->reveal() + hand->getDice(4)->reveal();
                    }
                    else if(hand->getDice(1)->reveal() == hand->getDice(2)->reveal() && hand->getDice(2)->reveal() == hand->getDice(3)->reveal()){
                        score = hand->getDice(0)->reveal() + hand->getDice(1)->reveal() + hand->getDice(2)->reveal() + hand->getDice(3)->reveal() + hand->getDice(4)->reveal();
                    }
                    else if(hand->getDice(2)->reveal() == hand->getDice(3)->reveal() && hand->getDice(3)->reveal() == hand->getDice(4)->reveal()){
                        score = hand->getDice(0)->reveal() + hand->getDice(1)->reveal() + hand->getDice(2)->reveal() + hand->getDice(3)->reveal() + hand->getDice(4)->reveal();
                    }
                    else if(hand->getDice(0)->reveal() == hand->getDice(2)->reveal() && hand->getDice(2)->reveal() == hand->getDice(3)->reveal()){
                        score = hand->getDice(0)->reveal() + hand->getDice(1)->reveal() + hand->getDice(2)->reveal() + hand->getDice(3)->reveal() + hand->getDice(4)->reveal();
                    }
                    else if(hand->getDice(0)->reveal() == hand->getDice(1)->reveal() && hand->getDice(1)->reveal() == hand->getDice(3)->reveal()){
                        score = hand->getDice(0)->reveal() + hand->getDice(1)->reveal() + hand->getDice(2)->reveal() + hand->getDice(3)->reveal() + hand->getDice(4)->reveal();
                    }
                    else if(hand->getDice(1)->reveal() == hand->getDice(3)->reveal() && hand->getDice(3)->reveal() == hand->getDice(4)->reveal()){
                        score = hand->getDice(0)->reveal() + hand->getDice(1)->reveal() + hand->getDice(2)->reveal() + hand->getDice(3)->reveal() + hand->getDice(4)->reveal();
                    }
                    else if(hand->getDice(1)->reveal() == hand->getDice(2)->reveal() && hand->getDice(2)->reveal() == hand->getDice(4)->reveal()){
                        score = hand->getDice(0)->reveal() + hand->getDice(1)->reveal() + hand->getDice(2)->reveal() + hand->getDice(3)->reveal() + hand->getDice(4)->reveal();
                    }
                    else{
                        score = 0;
                    }
                    break;
                case FOUR_OF_KIND:
                    if(hand->getDice(0)->reveal() == hand->getDice(1)->reveal() && hand->getDice(1)->reveal() == hand->getDice(2)->reveal() && hand->getDice(2)->reveal() == hand->getDice(3)->reveal()){
                        score = hand->getDice(0)->reveal() + hand->getDice(1)->reveal() + hand->getDice(2)->reveal() + hand->getDice(3)->reveal() + hand->getDice(4)->reveal();
                    }
                    else if(hand->getDice(1)->reveal() == hand->getDice(2)->reveal() && hand->getDice(2)->reveal() == hand->getDice(3)->reveal() && hand->getDice(3)->reveal() == hand->getDice(4)->reveal()){
                        score = hand->getDice(0)->reveal() + hand->getDice(1)->reveal() + hand->getDice(2)->reveal() + hand->getDice(3)->reveal() + hand->getDice(4)->reveal();
                    }
                    else if(hand->getDice(0)->reveal() == hand->getDice(2)->reveal() && hand->getDice(2)->reveal() == hand->getDice(3)->reveal() && hand->getDice(3)->reveal() == hand->getDice(4)->reveal()){
                        score = hand->getDice(0)->reveal() + hand->getDice(1)->reveal() + hand->getDice(2)->reveal() + hand->getDice(3)->reveal() + hand->getDice(4)->reveal();
                    }
                    else if(hand->getDice(0)->reveal() == hand->getDice(1)->reveal() && hand->getDice(1)->reveal() == hand->getDice(3)->reveal() && hand->getDice(3)->reveal() == hand->getDice(4)->reveal()){
                        score = hand->getDice(0)->reveal() + hand->getDice(1)->reveal() + hand->getDice(2)->reveal() + hand->getDice(3)->reveal() + hand->getDice(4)->reveal();
                    }
                    else if(hand->getDice(0)->reveal() == hand->getDice(1)->reveal() && hand->getDice(1)->reveal() == hand->getDice(2)->reveal() && hand->getDice(2)->reveal() == hand->getDice(4)->reveal()){
                        score = hand->getDice(0)->reveal() + hand->getDice(1)->reveal() + hand->getDice(2)->reveal() + hand->getDice(3)->reveal() + hand->getDice(4)->reveal();
                    }
                    else{
                        score = 0;
                    }
                    break;
                case FULL_HOUSE:
                    if(hand->getDice(0)->reveal() == hand->getDice(1)->reveal() && hand->getDice(1)->reveal() == hand->getDice(2)->reveal()){
                        if(hand->getDice(3)->reveal() == hand->getDice(4)->reveal()){
                            score = 25;
                        }
                        else{
                            score = 0;
                        }
                    }
                    else if(hand->getDice(2)->reveal() == hand->getDice(3)->reveal() && hand->getDice(3)->reveal() == hand->getDice(4)->reveal()){
                        if(hand->getDice(0)->reveal() == hand->getDice(1)->reveal()){
                            score = 25;
                        }
                        else{
                            score = 0;
                        }
                    }
                    else{
                        score = 0;
                    }
                    break;
                case SMALL_STRAIGHT:
                    //Bubble sort
                    for (int i = 0; i < HAND_SIZE; i++)
                    {
                        for (int j = 0; j + 1 < HAND_SIZE - i; j++)
                        {
                            // Swaping the elements if first one
                            // is greater than second one.
                            if (arr[j] > arr[j + 1])
                            {
                                temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                            }
                        }
                    }
                    if(arr[0] == 1 && arr[1] == 2 && arr[2] == 3 && arr[3] == 4){
                        score = 30;
                    }
                    else if(arr[1] == 1 && arr[2] == 2 && arr[3] == 3 && arr[4] == 4){
                        score = 30;
                    }
                    else if(arr[0] == 2 && arr[1] == 3 && arr[2] == 4 && arr[3] == 5){
                        score = 30;
                    }
                    else if(arr[1] == 2 && arr[2] == 3 && arr[3] == 4 && arr[4] == 5){
                        score = 30;
                    }
                    else if(arr[0] == 3 && arr[1] == 4 && arr[2] == 5 && arr[3] == 6){
                        score = 30;
                    }
                    else if(arr[1] == 3 && arr[2] == 4 && arr[3] == 5 && arr[4] == 6){
                        score = 30;
                    }
                    else{
                        score = 0;
                    }
                    break;
                case LARGE_STRAIGHT:
                    for(int i = 0; i < HAND_SIZE; i++){
                        for(int j = 0; j < HAND_SIZE; j++){
                            if(hand->getDice(i)->reveal() == hand->getDice(j)->reveal()){
                                duplicateCount++;
                            }
                        }
                        if(duplicateCount > 1){
                            isDuplicate = true;
                        }
                        sum += hand->getDice(i)->reveal();
                        duplicateCount = 0;
                    }
                    if(!isDuplicate && (sum==15||sum==20)){
                        score = 40;
                    }
                    else{
                        score = 0;
                    }
                    break;
                case CHANCE:
                    for(int i = 0; i < HAND_SIZE; i++){
                        score += hand->getDice(i)->reveal();
                    }
                    break;
                case YAHTZEE:
                    isDuplicate = true;
                    for(int i = 0; i<HAND_SIZE; i++){
                        for(int j = 0; j<HAND_SIZE; j++){
                            if(hand->getDice(i)->reveal() != hand->getDice(j)->reveal()){
                                isDuplicate = false;
                                break;
                            }
                        }
                    }
                    if(isDuplicate){
                        score = 50;
                    }
                    else{
                        score = 0;
                    }
                    break;
            }

            return score;

        }

        int score[BOARD_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

		//Display the board
		void show(){
            cout << "1. Ones: " << score[0] << endl;
            cout << "2. Twos: " << score[1] << endl;
            cout << "3. Threes: " << score[2] << endl;
            cout << "4. Fours: " << score[3] << endl;
            cout << "5. Fives: " << score[4] << endl;
            cout << "6. Sixes: " << score[5] << endl;
            cout << "   Sum: " << getUpperScore() << endl;
            cout << "   Bonus: " << getBonusScore() << endl;
            cout << "7. Three of a Kind: " << score[6] << endl;
            cout << "8. Four of a Kind: " << score[7] << endl;
            cout << "9. Full House: " << score[8] << endl;
            cout << "10. Small Straight: " << score[9] << endl;
            cout << "11. Large Straight: " << score[10] << endl;
            cout << "12. Chance: " << score[11] << endl;
            cout << "13. Yahtzee: " << score[12] << endl;
            cout << "Total: " << getTotalScore() << endl;
            cout << "Hand: ";
        }
		

		//Returns the score of the upper part of the board
		int getUpperScore(){
            return score[0]+score[1]+score[2]+score[3]+score[4]+score[5];

        }
		
		//Returns the score of the lower part of the board
		int getLowerScore(){
            return score[6]+score[7]+score[8]+score[9]+score[10]+score[11]+score[12];
        }
	

		//Returns the bonus points
		int getBonusScore(){
            if(getUpperScore() >= 63){
                return 35;
            }
            else{
                return 0;
            }
        }

		//Returns the total score
		int getTotalScore(){
            return getUpperScore() + getLowerScore() + getBonusScore();
        }


		//Play a hand based on the selected row
		void play(Hand* hand, int row){
            score[row-1] = calcScore(hand, row-1);
        }

		
		//Check to see if a row has been played or not (returns true if a row has been played)
		bool isPlayed(int row){
            if(score[row] != 0){
                return true;
            }
            else{
                return false;
            }
        }
		
		//Check to see if all rows haven been played or not (returns true if all rows have been played)
		bool isFinished(){
            for(int i = 0; i < BOARD_SIZE; i++){
                if(!isPlayed(i)){
                    return false;
                }
            }
            return true;
        }


	private:
};




//#######################################################################################

//The run function is the main loop of your program
void run() {
   string inputString;
   int row;
   Hand hand = Hand();
   Hand *handPtr = &hand;
   Game game = Game();
   game.show();
   hand.play();
   hand.show();
   //cout<< "Keep Dice (s to stop rolling): ";
   cin>>inputString;

   while(!game.isFinished()) {
       for (int i = 0; i < 2; i++) {
           if (inputString == "s") {
               break;
           }
           hand.setSelection(inputString);
           //cout << "Hand: ";
           hand.show();
           //cout << "Keep Dice (s to stop rolling): ";
           cin >> inputString;
       }
       //cout << "Select a combination to play: ";
       cin >> row;
       game.play(handPtr, row);
       game.show();

   }
   }




//For these types of programs there exists many combinations that you might have missed. 
//The best way to check them all is to write test cases for your program. 
//Here I give you an example of checking large straight. You can design your own test cases for different parts.

void test_case() {
    Game game;
    Hand* hand = new Hand();
    hand->getDice(0)->setValue(1);
    hand->getDice(1)->setValue(2);
    hand->getDice(2)->setValue(3);
    hand->getDice(3)->setValue(4);
    hand->getDice(4)->setValue(5);

    bool check1 = true;
    if (game.calcScore(hand, LARGE_STRAIGHT) != 40) {
        check1 = false;
    }
    if (check1) {
        cout << "check 1 passed\n";
    }

    hand->getDice(0)->setValue(2);
    hand->getDice(1)->setValue(6);
    hand->getDice(2)->setValue(4);
    hand->getDice(3)->setValue(3);
    hand->getDice(4)->setValue(5);

    bool check2 = true;
    if (game.calcScore(hand, LARGE_STRAIGHT) != 40) {
        check2 = false;
    }

    if (check2) {
        cout << "check 2 passed\n";
    }

    hand->getDice(0)->setValue(3);
    hand->getDice(1)->setValue(2);
    hand->getDice(2)->setValue(5);
    hand->getDice(3)->setValue(6);
    hand->getDice(4)->setValue(3);

    bool check3 = true;
    if (game.calcScore(hand, LARGE_STRAIGHT) != 0) {
        check3 = false;
    }

    if (check3) {
        cout << "check 3 passed\n";
    }

    hand->getDice(0)->setValue(1);
    hand->getDice(1)->setValue(2);
    hand->getDice(2)->setValue(3);
    hand->getDice(3)->setValue(4);
    hand->getDice(4)->setValue(6);

    bool check4 = true;
    if (game.calcScore(hand, LARGE_STRAIGHT) != 0) {
        check4 = false;
    }

    if (check4) {
        cout << "check 4 passed\n";
    }


}


int main() {

    srand(time(0));
    run();
    //Display the board
    Game game = Game();
    game.show();
    return 0;
}