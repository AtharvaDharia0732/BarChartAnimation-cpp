// barchart.h
// TO DO:  add header comment here.  Also add function header comments below.


//  Project 3 Starter Code 
//
//  Course name: CS 251 
//  Author: Atharva Dharia
//  NetID: adhari5
//  UIN: 656074627
//  UIC email: adhari5@uic.edu

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include "myrandom.h" // used in graders, do not remove
#include "bar.h"

using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
const string RESET("\033[0m");


//
// NOTE: COMMENT AND UNCOMMENT AS NEEDED BASED ON YOUR TERMINAL
//
// Color codes for light mode terminals
// const string RED("\033[1;36m");
// const string PURPLE("\033[1;32m");
// const string BLUE("\033[1;33m");
// const string CYAN("\033[1;31m");
// const string GREEN("\033[1;35m");
// const string GOLD("\033[1;34m");
// const string BLACK("\033[1;37m");
// const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for darker mode terminals
const string CYAN("\033[1;36m");
const string GREEN("\033[1;32m");
const string GOLD("\033[1;33m");
const string RED("\033[1;31m");
const string PURPLE("\033[1;35m");
const string BLUE("\033[1;34m");
const string WHITE("\033[1;37m");
// const string RESET("\033[0m");
const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};



//
// BarChart
//
class BarChart {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // Bars.  As a result, you must also keep track of the number of elements
    // stored (size) and the capacity of the array (capacity).  This is not a
    // dynamic array, so it does not expand.
    //
    Bar* bars;  // pointer to a C-style array
    int capacity;
    int size;
    string frame;
    
 public:
    
    // default constructor:
    BarChart() {
        
        // TO DO:  Write this constructor.
        bars=NULL;
        capacity=0;
        size=0;
        frame="";
    }
    
    // parameterized constructor:
    // Parameter passed in determines memory allocated for bars.
    BarChart(int n) {
        
        // TO DO:  Write this constructor.
        bars=new Bar[n];
        
        capacity=n;
        size=0;
        frame="";
    }

    //
    // copy constructor:
    //
    // Called automatically by C++ to create an BarChart that contains
    // a copy of an existing BarChart.  Example: this occurs when passing
    // BarChart as a parameter by value.
    //
    BarChart( BarChart& other) {
        
        other.bars = this->bars;
        other.capacity=this->capacity;
        other.size=this->size;
        other.frame=this->frame;
        // TO DO:  Write this constructor.
        
    }
    //
    // copy operator=
    //
    // Called when you assign one BarChart into another, i.e. this = other;
    //
    
    
    BarChart& operator=(BarChart& other) {
       
        bars=other.bars;//=this->bars;
        capacity=other.capacity;//=this->capacity;
        size=other.size;//=this->size;
        frame=other.frame;//=this->frame;
        // TO DO:  Write this operator.
        
        return *this;   // TO DO:  update this, it is only here so code compiles.
    }


    // clear
    // frees memory and resets all private member variables to default values.
    void clear() {
        
        bars=NULL;
        capacity=0;
        size=0;
        frame="";
        // TO DO:  Write this operator.
        
    }
    
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the
    // BarChart.
    //
    virtual ~BarChart() {

        // TO DO:  Write this destructor.
        
        bars=NULL;
        capacity=0;
        size=0;
        frame="";
        // free(bars);
        // for(int i=0;i<size;i++){
        //     delete &bars[i];
            
        // }
    }
    
    // setFrame
    void setFrame(string frame) {
        
        // TO DO:  Write this destructor.
    	this->frame=frame;
    }
    
    // getFrame()
    // Returns the frame of the BarChart oboject.
    string getFrame() {
        
        // TO DO:  Write this function.
        
        return frame; // TO DO:  update this, it is only here so code compiles.
    }

    // addBar
    // adds a Bar to the BarChart.
    // returns true if successful
    // returns false if there is not room
    bool addBar(string name, int value, string category) {
        
        // TO DO:  Write this function.
        if(size!=capacity){
        bars[size]=Bar(name,value,category);
        size++;
        return true; 
        }
        return false;// TO DO:  update this, it is only here so code compiles.
    }
    
    // getSize()
    // Returns the size (number of bars) of the BarChart object.
    int getSize() {
        
        // TO DO:  Write this function.
        
        return size;  // TO DO:  update this, it is only here so code compiles.
    }
    
    // operator[]
    // Returns Bar element in BarChart.
    // This gives public access to Bars stored in the Barchart.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChart: i out of bounds"
    Bar& operator[](int i) {
        
        
        // TO DO:  Write this function.
        if(i<size){
        return bars[i];  // TO DO:  update this, it is only here so code compiles.
        }
        else{
        cout<<"out_of_range\n";
        return bars[i];
            
        }
    }
    
    // dump
    // Used for printing the BarChart object.
    // Recommended for debugging purposes.  output is any stream (cout,
    // file stream, or string stream).
    // Format:
    // "frame: 1
    // aname 5 category1
    // bname 4 category2
    // cname 3 category3" <-newline here
    void dump(ostream &output) {

        // TO DO:  Write this function.
        //  Bar* tempBars;
        //  tempBars=bars; 
         Bar temp;
        
        for (int i = 0; i < size; i++) 
        {
          for (int j = i + 1; j < size; j++) 
          {
            if (bars[i].getValue() < bars[j].getValue()) 
            {
              temp = bars[i];
              bars[i] = bars[j];
              bars[j] = temp;
            }
          }
        }
        // output<<"frame: "<<frame<<endl;
        // for(int i=0;i<size;i++)
        //   {
        //       output<<bars[i].getName()<<" "<<bars[i].getValue()<<" "<<bars[i].getCategory()<<endl;
        //   }
        //   system("clear");
    }
    
    // graph
    // Used for printing out the bar.
    // output is any stream (cout, file stream, string stream)
    // colorMap maps category -> color
    // top is number of bars you'd like plotted on each frame (top 10? top 12?)
    void graph(ostream &output, map<string, string> &colorMap, int top) {
    	int lenMax = 60;  // this is number of BOXs that should be printed
                          // for the top bar (max value)
    //   usleep(30 * 50000);
       
        // TO DO: read this example and this erase it.
        // e.g. Here I am plotting 60 red BOXs to output
        // string color = "\033[1;36m";  // you should get this from colorMap
            
        string barstr;
        int max=bars[0].getValue();
        for(int x=0;x<top;x++)
        {
            barstr = "";
            
            double blocks=(bars[x].getValue())*60/max ;
            lenMax=floor(blocks);
            for (int i = 0; i < lenMax; i++) {
                
                barstr += BOX;
            }
             auto it = colorMap.find(bars[x].getCategory());  
            //  output<<endl;
            if(it==colorMap.end())
                output <<  WHITE << barstr <<" "<<bars[x].getName()<<" "<<bars[x].getValue() << endl;
            else         
                output <<  it->second << barstr <<" "<<bars[x].getName()<<" "<<bars[x].getValue() << endl;
        }
        // TO DO:  Write this function.
       
    }
    
};

