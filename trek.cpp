/* ========================================================================= */
/*	PROGRAM Starship Enterprise

    AUTHOR: Ryan Kunjbehari
    FSU MAIL NAME: EF0825229
    RECITATION SECTION NUMBER: 02
    RECITATION INSTRUCTOR NAME: Yanan Yu
    COP 3014 - Summer 2009
    PROJECT NUMBER: 3
    DUE DATE: Monday 6/22/2009
    PLATFORM: Windows OS using Microsoft Visual C++ Express 2008 compiler

SUMMARY

This program runs an escape simulation for the Starship Enterprise from the
planet Delta Tau.  It takes the input of current ship status from the user 
and calculates all possible attack situations for the starship.  The 
program then gives the user the option to re-run the simulation or exit by 
way of a looping structure.

INPUT

The input is entirely interactive and will require the user to enter integers 
for altitude, fuel_supply, and beam_strength.  All input is typed in at the
keyboard by the user (person running the program). 

OUTPUT

All output goes to the text (console) window.  The program prints an output 
title and echoprints the user's input in a readable fashion.  Finally, the 
calculated results are printed out. 

ASSUMPTIONS

We can assume that all input data is valid and correctly entered by the 
user.  Therefore, this program may not run correctly if bad data (characters
rather than numbers) are entered.  Only the choice of yes or no is tested
for errors.

*/

/* ========================================================================= */

#include <iostream>
         	
using namespace std;

/* ========================================================================= */

int main()
{
	// needed for choice selection in loop
	char choice;

	// variables
	int altitude;					// Enterprise's altitude in Km.					
	int fuel_supply;				// Enterprises's fuel supply in Kg.                     
	int beam_strength;				// Enterprises's tractor beam's 
									// strength in Km/min/min.
	double fuel_required;			// Fuel required to escape safely.
	int minute = 0;					// initial time, set minute to zero.

	// print overall program output heading
	cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n";
	cout << "Escape From The Planet Delta Tau Simulation\n\n";
	cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n";


	choice = 'y'; // must be outside the loop as a precursor.

	// keep running simulation as long as the user wants to do so
	while ((choice == 'y') || (choice == 'Y'))
    {

		// get the intitial readings and status from the user.
		cout << "Please enter the current altitude of the Enterprise:\n"; 
		cin >> altitude;
		
		cout << "Please enter the current fuel supply of the Enterprise:\n"; 
		cin >> fuel_supply;
				
		cout << "Please enter the strength of the Deltoid's tractor beam:\n"; 
		cin >> beam_strength;


		// print notification to notify starting of simulation.
		cout << endl << "Start of Simulation...\n\n";

		cout << "*=*=*=*=*=*=*=* Starship Enterprise" 
			 << " Computer Readout *=*=*=*=*=*=*=*\n\n"; 


	    // formula to calculate fuel required in order to escape.
	    fuel_required = (1 - static_cast<double>(altitude)/200000) 
		* beam_strength;

		// first condition
		if ((fuel_supply > fuel_required) && (altitude > 0))
		{
			cout << "We have enough fuel to escape!\n"
			     << "WE ARE CLEARED TO ESCAPE IMMEDIATELY!\n";
		}

		else 
		{
			cout << "We don't have enough fuel to escape!\n\n";
			cout << "Captain Archer, turn off the engines!\n";
			cout << "Trip, start shoveling at once!\n";
		

			minute = 0;   // initialize time for all suceeding simulations.

			// second condition
    		while ((fuel_supply < fuel_required) && (altitude > 0))
			{
				
				minute ++;

				altitude = (altitude - (beam_strength * minute * minute));
				fuel_required = (1 - static_cast<double>(altitude)/200000)
				* beam_strength;
				fuel_supply = (fuel_supply + 10);
			
				cout << endl << minute << " minutes have elapsed.\n";
				cout << "We are now orbiting the Deltoids at an altitude of " 
					 << altitude << " Km.\n";
				cout << "We have a steady fuel supply of " 
					 << fuel_supply << " Kg.\n";
				cout << "We have been hit by the Deltoids with a tractor beam "
					 << "of strength " << beam_strength << endl; 
				cout << "Km/min/min.\n";
				cout << "We require " << fuel_required << " Kg of fuel" 
					 << " to escape the Deltoids at this altitude.\n";
			}


			// third condition
			if (fuel_supply >= fuel_required) 
			
				cout << "We have enough fuel to escape!\n\n"
			         << "WE ARE CLEARED TO ESCAPE IMMEDIATELY!\n";
			 
			else 
				cout << "We don't have enough fuel to escape!\n\n"
				     << "ALL HAS COME TO AN END, CRASHING IS"
					 << " INEVITABLE AT THIS POINT!\n";

		}

		// rest of looping structure
    	do 
		{
    		cout << endl << "Would you like the run the simulation again?\n"; 
			cout << "Enter (y)es or (n)o: ";
    		cin >> choice;
			
		}while ((choice != 'y') && (choice != 'Y') 
			            && (choice != 'n') && (choice != 'N'));
	
	}	


	// print closing message 
	cout << endl << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n";
	cout << "Thanks for running the Delta Tau Escape Simulation\n\n";
	cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n"; 

return 0;

}

/* ========================================================================= */
/*                           END OF PROGRAM                                  */
/* ========================================================================= */
