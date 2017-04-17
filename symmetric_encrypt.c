// @author Bryan Urquia
//
// This project implements the functionality of a One-Time Pad encryption
// techniquie to encrypt and decrypt a text file. 
//
// Usage: ./symetric_encrypt [seed] [read file] [write file]
//
//
#include <stdio.h>
#include <stdlib.h>

char scrunch(char p);

int main(int argc, char *argv[]){
	int seed = atoi(argv[1]); //Seed is recommended to be 6 secret digits
	srandom(seed);


	FILE *ifp, *ofp; //File pointers
	
	ifp = fopen(argv[2], "r"); //Read file
	ofp = fopen(argv[3], "w"); //Write file
	
	char ch;
	while(fscanf(ifp, "%c", &ch)!=EOF){ //While end of file is not reached
		char scrunched = scrunch(ch);
		
		fprintf(ofp, "%c", scrunched); //printing new scrunched value to the outfile
	}
	//Closing files
	fclose(ifp);
	fclose(ofp);

	return 1;
}


//Takes a normal char and makes it a cypher txt char
//or viseversa
char scrunch(char p){
	int r = random()%97;
	// change all displayable character to range [0..96]
	int p1;

	if(p=='\t')  //checking for whitespaces to assign new values
		p1=0;
	else if(p=='\n')
		p1=1;
	else
		p1=p-30; //if not an space type, add subtract 30
	
	int c1;
	char c;
	c1 = p1 ^ r; //Computation to generate new char value
	//bitwise xor 
	//turn all output values into displayable characters
	if(c1==0)
		c = '\t'; ///checks if value is of type white space
	else if(c1==1)
		c = '\n';
	else
		c = c1 + 30; //adds 30 to the ASCII value if not space type

	return c;
}

