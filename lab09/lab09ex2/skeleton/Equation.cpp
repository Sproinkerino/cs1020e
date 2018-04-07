//=====================================================================
// FILE: Equation.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include <iostream>
#include <string>
using namespace std;

const int alphabetSize = 'G' - 'A' + 1;


class Equation {
private:

    // Indicate whether each digit has been assigned to any letter.
    bool digitUsed[ 10 ];

    // Indicate whether each letter is used in any of the 3 input strings.
    bool letterUsed[ alphabetSize ];

    // The value assigned to each letter.
    int letterValue[ alphabetSize ];

    // The 3 input strings of letters, where strX + strY = strZ.
    string strX, strY, strZ;


    int getValue( const string &str ) {
        int len = str.length();
        int value = 0;
        for ( int i = 0; i < len; i++ )
            value = value * 10 + letterValue[ str[i] - 'A' ];
        return value;
    }


    int countSolutions( char ch ) {

        // Add your code here.

    }

public:

    Equation( string &X, string &Y, string &Z )
        : strX(X), strY(Y), strZ(Z) { }


    int countSolutions() {
        unsigned i;
        for (i = 0; i < 10; i++) digitUsed[i] = false;
        for (i = 0; i < alphabetSize; i++) letterValue[i] = 0;
        for (i = 0; i < alphabetSize; i++)  letterUsed[i] = false;
        for (i = 0; i < strX.length(); i++) letterUsed[strX[i] - 'A'] = true;
        for (i = 0; i < strY.length(); i++) letterUsed[strY[i] - 'A'] = true;
        for (i = 0; i < strZ.length(); i++) letterUsed[strZ[i] - 'A'] = true;

        return countSolutions('A');
    }

}; // class Equation



int main() {
    string X, Y, Z;
    cin >> X >> Y >> Z;  // read inputs
    Equation eqn( X, Y, Z );
    cout << eqn.countSolutions() << endl;
    return 0;
}
