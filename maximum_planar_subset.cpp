//maximum planar subset
#include <iostream>
#include <fstream>
#include "maximum_planar_subset.h"
using namespace std;

MaxPlaSub::MaxPlaSub(int a){
    N = a;
    //cout<<"ok3.5"<<endl;
    vector<int> m;
    vector<int> aa;
    m.assign(N, 0);
    aa.assign(N, 0);
    M.assign(N, m);
    A.assign(N, aa);
    cout<<"M "<<M.size()<<'x'<<M[0].size()<<endl;
}

//top down


int MaxPlaSub::MPS(int a, int b , vector<int> const &data){
    cout<< b;
    
    if (M[a][b] > 0){
        return M[a][b];
    }
    else {
        if (data.at(b) > b||data.at(b) < a){
                M[a][b] = MPS(a, b-1, data);
        }
        else if (data.at(b) == a){
            M[a][b] = MPS(a+1, b-1, data) + 1;
            A[a][b] = 2;
        }
        else {
            if(MPS(a, b-1, data) < MPS(a, data.at(b)-1, data) + MPS(data.at(b)+1, b, data) + 1){
                M[a][b] = MPS(a, data.at(b)-1, data) + MPS(data.at(b)+1, b, data) + 1;
                A[a][b] = 1;
            }
            else{
                M[a][b] = MPS(a, b-1, data);
            }
        }
        return M[a][b];
    }

}

void MaxPlaSub::Chord(int i, int j, vector<int>&data, vector<vector<int>>&S, vector<vector<int>>&chor)
{
	while( j - i > 1)
	{
		if (S[i][j] == 1)
		{
			int k = data.at(j);
			//printf("%d %d\n", j, k);
			chor[count][0] = k;
			chor[count][1] = j;
			count++;
			Chord(k, j-1, data, S, chor);
			j = k - 1;
		}
		else if(S[i][j] == 2)
		{
			int k = data.at(j);
			//printf("%d %d\n", j, k);
			chor[count][0] = k;
			chor[count][1] = j;
			count++;
			Chord(i+1, j-1, data, S, chor);
			j = i - 1;
		}
		else
		{
			j--;
		}
	}
}



void MaxPlaSub::find_chord(vector<int>& data){
    int MIS = M[0][N-1];
    vector<int> c;
    c.assign(MIS, 0);
    chord.assign(2, c);
    
    //chord.resize(MIS);
    //for(int i=0;i < MIS;i++){
    //    chord[i].assign(2,0);
    //}
    //cout<<"ok5"<<endl;
    Chord(0, N-1 , data, A, chord);
}

MaxPlaSub::~MaxPlaSub(){

}


// bottom up
/**    A[]
 *   M[][]
 *   for (int i = 0 ; i < 2N ; i++){
 *       M[i][i] = 0;
 *   }
 *   for (int l = 1 ; l < 2N ; l++){
 *       for (int i = 0 ; i < 2N-l ; i++){
 *           int j = i + l;
 *           if (A[]<j&&A[]>i){
 *               M[][] = M[][]+1;
 *           }
 *           else if (A[] == i){
 *               M[][] = M[][] + 1;
 *           }
 *           else {
 *               M[][] = max(M[][],M[][]+M[][]+1);
 *           }
 *       }
 *   }
**/
