//
//  main.cpp
//  AudioExample
//
//  Created by Hack Audio on 10/5/19.
//  Copyright © 2019 Eric Tarr. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "AudioFile/AudioFile.hpp"
using namespace std;


int main() {
    
    string filename = "AcGtr.wav";
    int Fs;
    int bitDepth;
    int numChannels;
    // float signal[5]; cannot use primative array due to memory allocation
    // Must use fancy "array"
    vector<float> signal;
    
    // We supply "filename"
    // Function fills in sig,Fs,bit,channels (empty to begin with)
    audioread(filename, signal, Fs, bitDepth, numChannels);
    
    return 0;
}


