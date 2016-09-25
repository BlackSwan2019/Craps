/***************************************************************
CSCI 240         Program 5     Fall 2016

Programmer: Ben Lane

Section: 0002

Date Due: 10/7/16

Purpose: Simulate a game of Craps with wagering.
***************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;


// Set global variables.
	char playAgain;
	int	 dieOne, 
		 dieTwo, 
		 sum, 
		 point;
	double startingAmount = 100.00,
		   balanceAmount = startingAmount, 
		   wager;
	const int 	MIN_VALUE = 1,
		 		MAX_VALUE = 6,		 
				CRAPS_VAL1 = 2,
				CRAPS_VAL2 = 3,
				CRAPS_VAL3 = 12;
				
// Functions				
	double getWager(double balanceAmount);
	void wagerChatter(double balanceAmount, double wager);
	int rollDice();
	void continueChatter(double balanceAmount);



/***************************************************************
Function:  int main() 

Use: This function decides if the user wins or loses and also ask if 
	 the user wants to play again or not.

Arguments: None

Returns: interger 0

Note:
***************************************************************/
int main()
{ 
			 		 

	do{
	
	getWager(balanceAmount);
	wagerChatter(balanceAmount, wager);

	sum = rollDice();


		// Outcomes
		if (sum == 7 || sum == 11)
		{
			cout << "You won! "  << endl;
			balanceAmount += wager; 
			
		}
		else if (sum == CRAPS_VAL1 || sum == CRAPS_VAL2 || sum == CRAPS_VAL3)
		{
			cout << "You lose! Good day, sir! " << endl;
			balanceAmount -= wager; 
	
		}
		else if (sum ==  4 || sum == 5 || sum == 6 || sum == 8 || sum == 9 || sum == 10)
		{	
			cout << "The point is: " << sum << endl << endl;
			point = sum;
	
			do 
			{
				dieOne = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
				dieTwo = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
				sum = dieOne + dieTwo;
		
				cout << "The player rolled: " << dieOne << " + " << dieTwo << " = " << sum << endl;	
		
				if(sum == point)
				{
					cout << endl << "You rolled your point! You won! " << endl;
					balanceAmount += wager; 
				
				}
				else if(sum == 7)
				{
					cout << endl << "You seven'd out and lost! " << endl;
					balanceAmount -= wager; 
				}
			}while (sum != point && sum != 7);
	
		}
		
		// Play again?
		
		cout << endl << "Play again? (y)es or (n)o: ";
		cin >> playAgain;
		
		cout << endl;
		
			
		// Make sure the player enters a valid answer, either y or n, to play again.
		while(playAgain != 'n' && playAgain != 'N' && playAgain != 'y' && playAgain != 'Y')
			{
				cout << "Please enter a valid answer: (y)es or (n)o: ";
				cin >> playAgain;
		
			}
		
		
		if (playAgain == 'y' || playAgain == 'Y')
			{
				continueChatter(balanceAmount);
				
			}
			
	}while((playAgain == 'y' || playAgain == 'Y') && balanceAmount > 5);
	
		// Cordial or chastising outro depending on balance amount. 
		if (balanceAmount >=5)
		{
			cout << endl << "--------------------------------" << endl;
			cout << "The final balance is $" << balanceAmount << ". Goodbye, come back soon. ";
		
		}
		else
		{
			continueChatter(balanceAmount);	
			
		}
	
	return 0;
}


/***************************************************************
Function:  double getWager()

Use: This function gets the user's wager and shows his current balance.

Arguments: balanceAmount

Returns: wager

Note: 
***************************************************************/
double getWager(double balanceAmount)
{
	cout << "You have $" << fixed << setprecision(2) << balanceAmount << " available." << endl;
	cout << "How much would you like to wager (Minimum wager: $5.00)? ";
	cin >> wager;
	
	while (wager < 5)
		{
			cout << "Please enter a wager of $5.00 or greater ";
			cin >> wager;
		}
	while (wager > balanceAmount)
	{
		cout << "You can't do that, you have $" << balanceAmount << " to bet. Try again. ";
		cin >> wager;
		
	}
	balanceAmount -= wager;
	
	return wager;
	
}


/***************************************************************
Function:  void wagerChatter() 

Use: This function talks back to user depending on wager amount.

Arguments: None

Returns: the sum of the dice

Note: the function will display the two die and their sum as well
***************************************************************/
void wagerChatter(double balanceAmount, double wager)
{
	if (balanceAmount * .75 < wager)
	{
		cout << endl << "Are you nuts? You need to hedge your bets. " << endl;
		
	}
	else if (balanceAmount * .07 > wager)
	{
		cout << endl << "Come on, live a little. " << endl;
		
	}
	
}

/***************************************************************
Function:  int rollDice() 

Use: This function rolls the dice for the game of craps

Arguments: None

Returns: the sum of the dice

Note: the function will display the two die and their sum as well
***************************************************************/
int rollDice()
{
	// Perform random operations.
		srand(time(0));
		dieOne = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		dieTwo = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	
	// Find the sum of the dice roll.
	sum = dieOne + dieTwo;
		
	cout << endl << "The player rolled: " << dieOne << " + " << dieTwo << " = " << sum << endl << endl;
		
	return sum;
	
}


/***************************************************************
Function:  void continueChatter(double balanceAmount)

Use: This function talks to user upon continuing. Chatter dependent 
	 on balance amount.

Arguments: double balanceAmount

Returns: nothing

Note: 
***************************************************************/
void continueChatter(double balanceAmount)
{
	if (balanceAmount > (startingAmount * 5))
	{
		cout << endl << "--------------------------------" << endl;
		cout << "You are up by a good amount. Maybe you should cash in. ";
		
	}
	else if (balanceAmount == 0)
	{
		cout << endl << "--------------------------------" << endl;
		cout << "You went bust. You can't play anymore. G'bye. ";
		
	}
	else if (balanceAmount >= 0 && balanceAmount <5)
	{
		cout << endl << "--------------------------------" << endl;
		cout << "The final balance is $" << balanceAmount << ". Better luck next time. Good bye. ";
		
	}

}





