// **************************************************************************
//  File       [main.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The main program of 2019 fall Algorithm PA1]
//  Modify     [2020/11/21 HSIANG-CHUN YANG]
// **************************************************************************

#include <cstring>
#include <iostream>
#include <fstream>
#include "../lib/tm_usage.h"
#include "maximum_planar_subset.h"

using namespace std;

void help_message() {
    cout << "usage: bin/mps <input_file> <output_file>" << endl;
}

int main(int argc, char* argv[])
{
    if(argc != 3) {
       help_message();
       return 0;
    }
    CommonNs::TmUsage tmusg;
    CommonNs::TmStat stat;

    //////////// read the input file /////////////
    //cout<<"ok1"<<endl;
    char buffer[200];
    fstream fin(argv[1]);
    fstream fout;
    fout.open(argv[2],ios::out);
    //cout<<"ok2"<<endl;
    int size = 0;
    fin >> size;
    
    int num1,num2;
    vector<int>data;
    data.assign(size ,0);
    
    //fin
    fin >> num1 >> num2;
    data[num1] = num2;
    data[num2] = num1;
    while (fin >> num1 >> num2){
        if(num1==0)break;
        else{
          data[num1] = num2;
          data[num2] = num1;
        }
    }

    cout<<"N = "<< size <<endl;
    cout<<"data:"<<endl;
    for(int i=0; i < size; i++){
      cout<<i <<' ' <<data[i]<<endl;
    }
    //////////// the mps part ////////////////
    //tmusg.periodStart();
    
    MaxPlaSub mps(size);
    int MIS = 0;
    cout << size << endl;
    int s = size-1;
    cout << s << endl;
    MIS = mps.MPS(0, s, data);
    mps.find_chord(data);

    //tmusg.getPeriodUsage(stat);
    //cout <<"The total CPU time: " << (stat.uTime + stat.sTime) / 1000.0 << "ms" << endl;
    cout <<"memory: " << stat.vmPeak << "KB" << endl; // print peak memory

    //////////// write the output file ///////////
    fout <<  MIS  <<endl;
    for (int i = 0; i < MIS; i++){
        fout << mps.chord[i][0] << ' ' << mps.chord[i][1] << endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}
