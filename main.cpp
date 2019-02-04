#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <fstream>
#include<iterator>
#include "Passenger.h"
#include "Simulation.h"
#include "Event.h"

using namespace std;

template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}

float findAmount(const vector<string> words)
{
    float return_value = 0;
    for(int i=0; i< words.size(); i++){
        if (words[i][0] == '$') {
            const char *cstr = (words[i].substr(1)).c_str();
            return_value = strtof(cstr, NULL);
    //        cout << "return_value: " << return_value << endl;
            break;
        }
    }
    return return_value;
}


int main(int argc, char* argv[]) {

    /*
    // below reads the input file
    // in your next projects, you will implement that part as well
    if (argc != 3) {
        cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
        return 1;
    }

    cout << "input file: " << argv[1] << endl;
    cout << "output file: " << argv[2] << endl;
    */




    // here, perform the input operation. in other words,
    // read the file named <argv[1]>
    ifstream infile(argv[1]);
    string line;
    vector<string> input;
    // process first line
    getline(infile, line);
    cout << line << endl;
    vector<string> words;
    split1(line,words);
    int P = stoi(words[0]);
    int L = stoi(words[1]);
    int S = stoi(words[2]);
    cout << "number of input lines: " << P << endl;

    vector<Passenger*> passengers;

    for (int i=0; i<P; i++) {
        Passenger* p = new Passenger;
        getline(infile, line);
 //       cout << "line: " << line << endl;

        vector<string> words1;
        split1(line,words1);
        p->arriveTime = stoi(words1[0]);
        p->boardingTime = stoi(words1[1]);
        p->lugTime = stoi(words1[2]);
        p->secTime = stoi(words1[3]);
        if(words1[4] == "V"){
            p->vip = true;
        }
        else{
            p->vip = false;
        }
        if(words1[5] == "N"){
            p->lug = true;
        }
        else{
            p->lug = false;
        }
        passengers.push_back(p);

    }

    Simulation s;

    ofstream myfile;
    myfile.open (argv[2]);

    string case0 = s.makeSim(passengers, L, S, myfile);

    string case1 = s.makeSim1(passengers, L, S, myfile);

    string case2 = s.makeSim2(passengers, L, S, myfile);

    string case3 = s.makeSim3(passengers, L, S, myfile);

    string case4 = s.makeSim4(passengers, L, S, myfile);

    string case5 = s.makeSim5(passengers, L, S, myfile);

    string case6 = s.makeSim6(passengers, L, S, myfile);

    string case7 = s.makeSim7(passengers, L, S, myfile);



    cout << "input file has been read" << endl;


    /*
    // here, perform the output operation. in other words,
    // print your results into the file named <argv[2]>
    ofstream myfile;
    myfile.open (argv[2]);
    myfile << case0 << endl;
    myfile << case1 << endl;
    myfile << case2 << endl;
    myfile << case3 << endl;
    myfile << case4 << endl;
    myfile << case5 << endl;
    myfile << case6 << endl;
    myfile << case7 << endl;
    myfile.close();
    */


    return 0;

}