
#include <iostream>
using namespace std;

void nextWoman(int q[], int &c);
void nextMan(int q[], int &c);
void backtrack(int q[], int &c);
void print(int q[], int c);
bool okay(int q[], int c);

bool okay(int q[], int c){
	//test to ensure number we are trying to place in q[c] is unique
	//and does not exist in q[0] through q[c-1]
	//this is essentially the same as the row test in 8 Queens 1D
	for (int i = 0; i < c; i++){
        if (q[i] == q[c]) return false;
	}
       

        
	
    int mp[3][3] = {{0,2,1},   //man 0 likes woman 0 the most and woman 1 the least.
                    {0,2,1},
                    {1,2,0}};   

    int wp[3][3] = {{2,1,0},
                    {0,1,2},
                    {2,0,1}};
  

    
    for (int i = 0; i < c; i++){
        if (mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) return false; // if man [i] likes women[c] more than women[i] and women[c] likes man[i] more than man[c] return false  
        if (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) return false; // if man [c] likes women[i] more than women[c] and women[i] likes man[c] more than man[i] return false   
    }
    //if we pass all tests 
    return true; }



void nextMan(int q[], int &c) { //pass the value of c by reference so it can be altered within the function
	c++; 	//go to the next column (alter the value of c)
	if (c == 3) {
		print (q, c);//we have a solution
	}
	nextWoman(q, c);
}

void nextWoman(int q[], int &c) {
	q[c]++; //increment the current value in q[c] here
	if (q[c] == 3){ /*some value greater than our set of numbers being entered in our q array*/ 
		q[c] = -1;//reset the value in q[c]
		backtrack(q, c);//backtrack
	}
	if (okay(q, c)) { //if the value we are trying to place in square c is valid
		nextMan(q, c); //we can go to the next square
		
	}
	else {
		nextWoman(q, c); //we need to try a new value in square c (i.e. go to the next row)
	}
}

void backtrack(int q[], int &c) { //pass the value of c by reference so it can be changed within the function
   c--; //go to the previous column (alter the value of c)
	if (c == -1) {
		exit(1); // cant return zero because it is a void
	}
	nextWoman(q, c);
}

void print(int q[], int c){
    static int sol = 0;
    cout << "Solution # " << ++sol << ":\n";
    cout << "Man Women" << "\n";
    for(int i =0; i < 3; i++){
       
       cout << i << "   " << q[i] << endl;
        
    }
    
   backtrack(q, c); //print the solution
    //backtrack
}

int main() {
	//initialize these values depending on the set of numbers you are using in the given problem
	//in 8 Queens, our set of numbers is 0 - 7 (the row in which the Queen is located in a given column)
	//In 8 in a Cross, it's 1 - 8 (the numbers we are storing in the squares)
    int q[3] = {-1};
    int col = -1;
	nextMan(q, col);
	
    return 0;
}
