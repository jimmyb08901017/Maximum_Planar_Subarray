// **************************************************************************
//  File       [maximum_planar_subset.h]
//  Author     [HSIANG-CHUN YANG]
//  Synopsis   [The header file for maximum planar subset.]
//  Modify     [2020/11/19 HSIANG-CHUN YANG]
// **************************************************************************
#ifndef MAXIMUM_PLANAR_SUBSET_H_INCLUDED
#define MAXIMUM_PLANAR_SUBSET_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;

class MaxPlaSub {
    public:
        int MPS(int , int ,vector<int> const&);
        void find_chord(vector<int>&);
        //int chord_Size();
        //void fout_chord();
        MaxPlaSub(int);
        ~MaxPlaSub();
        vector<vector<int>> chord;//chord
        
    private:
        vector<vector<int>> A;//checkCase 1 for in 2 for exact
        vector<vector<int>> M;//MIS
        int count = 0;
        int N = 0; //points, not line
        void Chord(int, int, vector<int>&, vector<vector<int>>&,vector<vector<int>>&);

};


#endif // MAXIMUM_PLANAR_SUBSET_H_INCLUDED
