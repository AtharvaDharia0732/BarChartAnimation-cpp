// barchartanimate.h
// TO DO:  add header comment here.  Also add function header comments below.


//  Project 3 Starter Code 
//
//  Course name: CS 251 
//  Author: Atharva Dharia
//  NetID: adhari5
//  UIN: 656074627
//  UIC email: adhari5@uic.edu

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
  
using namespace std;



//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    string title;
    string xlabel;
    string source;
    string country;

 public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        
        this->title=title;
        this->xlabel=xlabel;
        this->source=source;
        capacity=4;
        this->size=0;
        country="";
        barcharts=new BarChart[capacity];
        
        // TO DO:  Write this constructor.
        
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        for(int i=0;i<size;i++){
            delete &barcharts[i];
        }
        // TO DO:  Write this destructor.
        
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {
    	
        // TO DO:  Write this constructor.
        
        string text;
        string s1,s2,s3,s4,s5;
        
        while(!file.eof())
        {
            getline(file,text);
            getline(file,text);
            int count=atoi(text.c_str());
            
            BarChart b(count);
            for(int i=0;i<count;i++)
            {
                getline(file,s1,',');
                getline(file,s2,',');
                getline(file,s3,',');
                getline(file,s4,',');
                getline(file,s5);
                // cout<<s1<<" "<<s2<<" "<<s3<<" "<<atoi(s4.c_str())<<" "<<s5<<endl;
                // cout<<capacity<<endl;
                    b.setFrame(s1);
                    b.addBar(s2,stoi(s4),s5);
                    
                    barcharts[size]=b;
                 
                
            }
                 
                size++;
                if(capacity==size)
                {
                    capacity=capacity*2;
                }
        }
        size--;
    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;
		int index=0;
		if(endIter=-1)
		{
		    endIter=size;
		}
		for(int i=0;i<size;i++)
		{
		    barcharts[i].dump(output); 
		    
// 		cout<<"endl\n";
		}
// 		cout<<"endl2\n";
		for(int i=0;i<size;i++)
		{
		    for(int j=0;j<size;j++)
		    {
		        string str=barcharts[i][j].getCategory();
		        if(colorMap.find(str)==colorMap.end())
		        {
		            if(index!=6)
		            {
		              //  cout<<"\ncolor: "<<COLORS[index]<<endl<<endl;
    		            colorMap[str] = COLORS[index];
    		            index++;
		            }
		            else
		            {
		              //  cout<<"\ncolor: "<<COLORS[index]<<endl<<endl;
		                index=0;
		                colorMap[str] = COLORS[index];
    		            index++;
		            }
		        }
		    }
		}
// 		for(auto it = colorMap.cbegin(); it != colorMap.cend(); ++it)
//         {
//             cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
//         }
        for(int i=0;i<endIter&&i<size;i++)
        {
            
            output<<title<<"\n"<<source<<endl;
            //  const string CLEARCONSOLE = "\033[2J";
              if(top>barcharts[i].getSize())
                {
                    barcharts[i].graph(output, colorMap, barcharts[i].getSize());
                }
                else
                {
                    barcharts[i].graph(output, colorMap, top);
                }
            output<<RESET;
            output<<xlabel<<endl<<barcharts[i].getFrame()<<endl; 
            if((i!=size-1)||(i!=endIter-1))
            { 
              
            usleep(3 * microsecond);
             output<<CLEARCONSOLE;
            //   output<<CLEARCONSOLE;
                // system("clear");
            }
            else
            {
                 usleep(3 * microsecond);
            
            }
        }
        // TO DO:  Write this function.
			
	}

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize(){
        
        return size;  // TO DO:  update this, it is only here so code compiles.
        
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i){
        // BarChart bc;
         if(i<size){
        return barcharts[i];  // TO DO:  update this, it is only here so code compiles.
        }
        else{
        cout<<"out_of_range\n";
        return barcharts[i];
            
        }
        // TO DO:  Write this function.
        
        // return bc; // TO DO:  update this, it is only here so code compiles.
    }
};
