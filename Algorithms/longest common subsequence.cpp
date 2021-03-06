/*
Implementation of Longest common subsequence
It traverse strings from start to end.
Written By : Smrity Chaudhary
Dated      : 09/10/2018
*/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void longest_subsequence(vector<char>,vector<char>);
int main(){
    /*
    Objective       : Take input in vector and call other functions
    Input Parameter : None
    Output Value    : Sorted Array
    Description     : Driver function
    */
    vector<char> seq1;
    vector<char> seq2;
    /*
    char character;
    char choice = 'y';
    while(choice == 'y' || choice == 'Y' ){
        cout << "Enter an character(sequence-1): ";
        cin >> character;
        seq1.push_back(character);
        cout << "Do you want to enter more?(y/n): ";
        cin >> choice;
    }
    choice = 'y';
    while(choice == 'y' || choice == 'Y' ){
        cout << "Enter an character(sequence-2): ";
        cin >> character;
        seq2.push_back(character);
        cout << "Do you want to enter more?(y/n): ";
        cin >> choice;
    }*/
    seq1.push_back('a');
    seq1.push_back('b');
    seq1.push_back('c');
    seq1.push_back('d');
    seq1.push_back('a');
    seq1.push_back('f');
    //seq1.push_back('b');

    seq2.push_back('a');
    seq2.push_back('c');
    seq2.push_back('b');
    seq2.push_back('c');
    seq2.push_back('f');
    //seq2.push_back('y');
    //seq2.push_back('b');
    longest_subsequence(seq1,seq2);

}
void longest_subsequence(vector<char> seq1,vector<char> seq2){
    /*
    Objective       : To find longest subsequence
    Input Parameter : Two user entered strings
    Output Value    : Longest subsequences
    Approach        : First find length of longest subsequence using Dynamic
                        programming. Then find all possible longest subsequence
                        of that length.
    */

    int size_seq1 = seq1.size();
    int size_seq2 = seq2.size();
    vector<char> subseq;
    //matrix to store matchings in between strings
    int length[size_seq1+1][size_seq2+1];
    //prepare a matrix for memoization
    for(int i=0;i<=size_seq1;i++){
        for(int j=0;j<=size_seq2;j++){
        if(i==0 || j==0){
            length[i][j] = 0;
        }
        if(i>0 && j>0 && seq1[i-1]==seq2[j-1]){
            length[i][j] = 1+length[i-1][j-1];
        }
        if(i>0 && j>0 && seq1[i-1]!=seq2[j-1]){
            length[i][j] = max(length[i-1][j],length[i][j-1]);
        }
        }
    }
    //print the matrix
    cout << "\nmatrix is: \n";
    for(int i=0;i<=size_seq1;i++){
        for(int j=0;j<=size_seq2;j++){
            cout << length[i][j];
        }
        cout << "\n";
    }
    cout << " longest common subsequence is: \n";
    int i,j;
    int index = size_seq1-1;
    vector<char> lcs;
    stack<int> sequence;
    sequence.push(size_seq1);
    sequence.push(size_seq2);
    //Here we will  find out all possible longest sub sequence
    //This loop will help to backtrack again where the conflict of same length occur
    while(!sequence.empty()){
        j = sequence.top();
        sequence.pop();
        i = sequence.top();
        sequence.pop();
    //This loop will back track from given point
        while(i>0&&j>0){
        if(seq1[i-1]==seq2[j-1]){
            //Storing where letters are matching(subsequence)
            lcs.push_back(seq1[i-1]);
            index--;
            i--;
            j--;
        }
        else if(length[i-1][j]==length[i][j-1]){
            //Push positions into stack where conflict occur
            sequence.push(i-1);
            sequence.push(j);
            sequence.push(lcs.size()); // to track correct subsequence
            j--;
        }
        else if(length[i-1][j]>length[i][j-1]){
            i--;
        }
        else{
            j--;

        }
    }
    for(int i=lcs.size()-1;i>=0;i--){
        cout << lcs[i] << ",";
    }
    cout << "\n";
    int counter = sequence.top();
    sequence.pop();
    int curr_size = lcs.size();
    //pop out the letters until where the conflict occurred
    for(int i=1;i<=curr_size-counter;i++){
        lcs.pop_back();
    }
    }

}
