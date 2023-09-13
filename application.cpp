// Bar Chart Animation
//
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.
//
// Once your three class/abstraction files are completed and tested, run with
// this application to see your final creation.
//
// TO DO: Nothing for the standard application, just compile and run! However,
// before submitting you need to add your creative component.
//
// Adam Koehler
// U. of Illinois, Chicago
// Fall 2022
//
// Original iteration of program developed by:
// Shanon Reckinger
// U. of Illinois, Chicago 


//  Project 3 Starter Code 
//
//  Course name: CS 251 
//  Atharva Dharia
//  NetID: adhari5
//  UIN: 656074627
//  UIC email: adhari5@uic.edu



#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;

//milestone 5
//this function add records in the inserted text file
//this function will open the file in append mode to write data inside it
//it will ask for user about frame, name, country, value and category
//after adding the information by user it will be added to the given file
//the records will be added in the format as it were added before in the file at the end for new data
//first end line that is blank line, then the number of records and then the records with the separation of comma 
//and at the end again blank line
void addRecord(string filename)
{
    ofstream outFile;
    outFile.open (filename,ios::app);
    int numberOfRecords;
    string frame;
    string name;
    string country;
    string value;
    string category;
    
    cout<<"Enter number of records\n";
    cin>>numberOfRecords;
    outFile <<endl<< numberOfRecords<<"\n";
    for(int i=0;i<numberOfRecords;i++)
    {
        cout<<"Enter Frame Name\n";
        cin>>frame;
        cout<<"Enter Name\n";
        cin>>name;
        cout<<"Enter Country\n";
        cin>>country;
        cout<<"Enter Value\n";
        cin>>value;
        cout<<"Enter Category\n";
        cin>>category;
        
    outFile<<frame<<","<<name<<","<<country<<","<<value<<","<<category<<endl;
    }
    
    outFile.close();
    
    cout<<"Record added\n";
    string x;
    cout<<"Enter any key to continue\n";
    cin>>x;
}
int main() {
    
	string filename = "abc.txt";
    int choice;
    //take input from the user about to add record or just show the animation
    do{
    	cout<<"Enter 1 for adding a record to the file\nEnter 2 for displaying animation of records\n";
    	cin>>choice;
    	if(choice==1)
    	{
    	    addRecord(filename);//call addRecord function described above for milestone 5 creative part for adding record
    	}
    	else if(choice==2)
    	{
        	ifstream inFile(filename);
        	string title;
        	getline(inFile, title);
        	string xlabel;
        	getline(inFile, xlabel);
        	string source;
        	getline(inFile, source);
        
        	BarChartAnimate bca(title, xlabel, source);
        	
        	while (!inFile.eof()) {
        		bca.addFrame(inFile);
        	}
        	
        	bca.animate(cout, 12, -1);
    	}
	}while(choice!=2);//unless the user selects to display animation

    return 0;
}

