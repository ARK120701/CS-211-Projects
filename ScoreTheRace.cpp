/** 
 * Project - Score the race
 * */

#include <iostream>
using namespace std;

int main() {
    
   while (true) {
       
      string outcome;
      
      cout << "Enter the race outcome: "; // asking the user to enter the race outcome
      cin >> outcome; // storing the outcome

      if (outcome == "done")       // If the user entered "done", exit the program
         break;
         
      int numTeams = 0;       // The number of teams
      int maxTeamSize = 0;    // The number of runners on the largest team
      int scores['Z'+1] = {}; // scores[i] keeps track of the total score of team i
      int counts['Z'+1] = {}; // counts[i] keeps track of the number of runners on team i
      
      for (int i = 0; i < outcome.length(); ++i) { // For each runner in the race,
         scores[outcome[i]] += i + 1;              // Increase the team's score by the runner's rank.
       
         if (counts[outcome[i]] == 0)              // If the score changed from 0 to non-0, increment numTeams.
            ++numTeams;                           // update the total number of teams
         ++counts[outcome[i]];                  // Update the number of runners on the team
         maxTeamSize = max(maxTeamSize, counts[outcome[i]]);
      }
      
      if (maxTeamSize != outcome.length() / numTeams) { // If the largest team is larger than the average team,
         cout << "The teams don't have the same number of runners.\n";
         continue;
      }
      
      cout << "There are " << numTeams << " teams.\n";
      cout << "Each team has " << maxTeamSize << " runners.\n";
      string winningTeams = ""; // All teams that are tied with the winning score
      double winningScore = outcome.length() * outcome.length(); // The winning total score (initialize to some large value)
    
      for (char i = 'A'; i <= 'Z'; ++i) {   // For each letter from A-Z,
       
         if (scores[i] != 0) {              // If that team participated,
            cout << i << ": " << (double)scores[i] / maxTeamSize << endl;
         
            if (scores[i] < winningScore) { // Compare that team's score to the winning score.
               winningTeams = i;
               winningScore = scores[i];    // If there's a new winner, it becomes the sole winner.
            }
         
            else if (scores[i] == winningScore)
               winningTeams += i;           // If it's a tie, append it to the list of winners.
         }

      }
      
    // Print the name of the winning team, runners, each name of the teams, and its average score
      cout << "The winning " << (winningTeams.length() == 1 ? "team is team '" : "s are teams ")
         << winningTeams << "' with a score of " << winningScore / maxTeamSize << endl;
   }
   
   return 0;
   
} // end of the code
