
//  Project 3 Starter Code 
//
//  Course name: CS 251 
//  Author: Atharva Dharia
//  NetID: adhari5
//  UIN: 656074627
//  UIC email: adhari5@uic.edu


#include <iostream>
#include "barchartanimate.h"
#include <fstream>
#include<string>
#include <sstream>

using namespace std;

bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}
bool testBarOperatorsGreaterThanLessThan() {
	Bar b1("a", 1, "cat");
	Bar b2("b", 2, "cat");

	
    if (b1>b2) {
    	cout << "testBarOperatorsGreaterThanLessThan: b1>b2 true, test passed" << endl;
    	return true;
    } else if (!(b1>b2)) {
    	cout << "testBarOperatorsGreaterThanLessThan: b1>b2 false, test passed" << endl;
    	return true;
    } else if (b1<b2) {
    	cout << "testBarOperatorsGreaterThanLessThan: b1<b2 true, test passed" << endl;
    	return true;
    } else if (!(b1<b2)) {
    	cout << "testBarOperatorsGreaterThanLessThan: b1<b2 false, test passed" << endl;
    	return true;
    } 
    else
    {
        cout<<"testBarOperatorsGreaterThanLessThan: tests for < and > failed";
        return false;
    }
}
bool testBarOperatorsGreaterThanEqualToLessThanEqualTo() {
	Bar b1("a", 1, "cat");
	Bar b2("b", 2, "cat");

	
    if (b1>=b2) {
    	cout << "testBarOperatorsGreaterThanEqualToLessThanEqualTo: b1>b2 true, test passed" << endl;
    	return true;
    } else if (!(b1>=b2)) {
    	cout << "testBarOperatorsGreaterThanEqualToLessThanEqualTo: b1>b2 false, test passed" << endl;
    	return true;
    } else if (b1<=b2) {
    	cout << "testBarOperatorsGreaterThanEqualToLessThanEqualTo: b1<b2 true, test passed" << endl;
    	return true;
    } else if (!(b1<=b2)) {
    	cout << "testBarOperatorsGreaterThanEqualToLessThanEqualTo: b1<b2 false, test passed" << endl;
    	return true;
    } 
    else
    {
        cout<<"testBarOperatorsGreaterThanEqualToLessThanEqualTo: tests for < and > failed";
        return false;
    }
}


bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

int main() {
	testBarDefaultConstructor();
	cout<<endl;
	testBarParamConstructor();
	cout<<endl;
	testBarOperatorsGreaterThanLessThan();
	cout<<endl;
	testBarOperatorsGreaterThanEqualToLessThanEqualTo();
	cout<<endl;
	
	
	cout<<endl<<endl;
	
	  BarChart bc;
    BarChart bcc(10);
    BarChart bccc(10);
    // BarChart bcCopy(bccc);
    BarChart bc1;
    BarChart bc2(10);
    bc1 = bc2;
    BarChart bcccc(10);
    bcccc.clear();
    
    BarChart bccccc(3);
    bccccc.setFrame("1950");
    
    cout<<bccccc.getFrame()<<endl;
    
    cout<<bccccc.addBar("Chicago", 1020, "US A");
    cout<<bccccc.addBar("NYC", 1300, "US");
    cout<<bccccc.addBar("Paris", 1200, "France");
    
    cout<<endl<<bccccc.getSize()<<endl;

    int n=bccccc.getSize();
    for (int i = 0; i <n ; i++) {
      cout << bccccc[i].getName() << " ";
      cout << bccccc[i].getValue() << " ";
      cout << bccccc[i].getCategory();
      cout << endl;
    }
    cout<<endl<<endl;
        // Option 1:
    bccccc.dump(cout); 
    
    cout<<endl<<endl;
    // Option 2:
    stringstream ss("");
    bccccc.dump(ss);
    cout << ss.str();
    
    
    cout<<endl<<endl;
    
    string red("\033[1;36m");
    string blue("\033[1;33m");
    map<string, string> colorMap;
    colorMap["US A"] = red;
    colorMap["France"] = blue;
    bccccc.graph(cout, colorMap, 3);

    
	ifstream inFile("abc.txt");
    BarChartAnimate bca("title", "xlabel", "source");
    bca.addFrame(inFile);
	bca.animate(cout, 14, 14);
	
// 	int n=bca.getSize();
// 	for (int i = 0; i < n; i++) {
//       cout << bca[i].getFrame();
//       cout << endl;
//     }
	inFile.close();


    return 0;
}