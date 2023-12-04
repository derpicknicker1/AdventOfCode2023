/*
--- Day 1: Trebuchet?! ---
Something is wrong with global snow production, and you've been selected to take a look. The Elves have even given you a map; on it, they've used stars to mark the top fifty locations that are likely to be having problems.

You've been doing this long enough to know that to restore snow operations, you need to check all fifty stars by December 25th.

Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!

You try to ask why they can't just use a weather machine ("not powerful enough") and where they're even sending you ("the sky") and why your map looks mostly blank ("you sure ask a lot of questions") and hang on did you just say the sky ("of course, where do you think snow comes from") when you realize that the Elves are already loading you into a trebuchet ("please hold still, we need to strap you in").

As they're making the final adjustments, they discover that their calibration document (your puzzle input) has been amended by a very young Elf who was apparently just excited to show off her art skills. Consequently, the Elves are having trouble reading the values on the document.

The newly-improved calibration document consists of lines of text; each line originally contained a specific calibration value that the Elves now need to recover. On each line, the calibration value can be found by combining the first digit and the last digit (in that order) to form a single two-digit number.

For example:

1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet
In this example, the calibration values of these four lines are 12, 38, 15, and 77. Adding these together produces 142.

Consider your entire calibration document. What is the sum of all of the calibration values?

Your puzzle answer was 54951.

--- Part Two ---
Your calculation isn't quite right. It looks like some of the digits are actually spelled out with letters: one, two, three, four, five, six, seven, eight, and nine also count as valid "digits".

Equipped with this new information, you now need to find the real first and last digit on each line. For example:

two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen
In this example, the calibration values are 29, 83, 13, 24, 42, 14, and 76. Adding these together produces 281.

What is the sum of all of the calibration values?

Your puzzle answer was 55218.
*/
#include "advent.h"

static int sum;

/*##########################
# Get input data from file #
##########################*/
static bool getInput(char *f, bool a) {
	char line[100];
	sum = 0;

	FILE *file = fopen(f, "r");
	if (file == NULL) {
		printf("ERR: CAN NOT OPEN '%s'\n\n", f);
		return false;
	}

	while (fgets (line, 100, file)) {
		bool first = true;
		uint8_t digit = 0;
		int len = strlen(line) - 1;
		for (int i = 0; i <= len; i++ ) {
			if(isDigit(line[i])) {
				digit = line[i]-48;
			}
			if(!a) {
				if(i+2 <= len && line[i] == 'o' && line[i+1] == 'n' && line[i+2] == 'e')
					digit = 1;
				else if(i+2 <= len && line[i] == 't' && line[i+1] == 'w' && line[i+2] == 'o')
					digit = 2;
				else if(i+4 <= len && line[i] == 't' && line[i+1] == 'h' && line[i+2] == 'r' && line[i+3] == 'e' && line[i+4] == 'e')
					digit = 3;
				else if(i+3 <= len && line[i] == 'f' && line[i+1] == 'o' && line[i+2] == 'u' && line[i+3] == 'r')
					digit = 4;
				else if(i+3 <= len && line[i] == 'f' && line[i+1] == 'i' && line[i+2] == 'v' && line[i+3] == 'e')
					digit = 5;
				else if(i+2 <= len && line[i] == 's' && line[i+1] == 'i' && line[i+2] == 'x')
					digit = 6;
				else if(i+4 <= len && line[i] == 's' && line[i+1] == 'e' && line[i+2] == 'v' && line[i+3] == 'e' && line[i+4] == 'n')
					digit = 7;
				else if(i+4 <= len && line[i] == 'e' && line[i+1] == 'i' && line[i+2] == 'g' && line[i+3] == 'h' && line[i+4] == 't')
					digit = 8;
				else if(i+3 <= len && line[i] == 'n' && line[i+1] == 'i' && line[i+2] == 'n' && line[i+3] == 'e')
					digit = 9;
			}
			if(digit > 0 && first){
				sum += digit*10;
				first = false;
			}
		}
		sum += digit;
	}

	fclose(file);
	return true;
}

/*##########################
# Function to solve part A #
##########################*/
void get1a(char * f) {
	if (!getInput(f, true)) return;
	
	printf("1a: %d\n", sum);
}

/*##########################
# Function to solve part B #
##########################*/
void get1b(char *f) {
	if (!getInput(f, false)) return;

	printf("1b: %d\n\n", sum);
}
