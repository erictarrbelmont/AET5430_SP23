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


void setSamplingRate(int & x){
    x = 44100;
    //return x;
}

void dBAmplitudeChange(vector<float> & x, const float dBAmp);

void stereoWidener(vector<vector<float>> & x , const float width);

int main() {
    
    string filename = "AcGtr.wav";
    int Fs = 48000;
    int bitDepth;
    int numChannels;
    // float signal[5]; cannot use primative array due to memory allocation
    // Must use fancy "array"
    vector<float> signal;
    
    setSamplingRate(Fs);
    
    // We supply "filename"
    // Function fills in sig,Fs,bit,channels (empty to begin with)
    audioread(filename, signal, Fs, bitDepth, numChannels);
    
    // Total number of samples
//    int N = signal.size();
//
//    for (int n = 0 ; n < N ; ++n){
//
//        signal[n] *= 0.25f;
//        //signal.at(n) *= 0.25f; // Both ways for indexing
//    }
  
    dBAmplitudeChange(signal, -24.f);
    
    string outName = "NewSignal.wav";
    
    audiowrite(outName,signal,Fs,bitDepth,numChannels);
    
    
    
    // Stereo signals
    // In C++, one way to create a "matrix"
    // is with a vector of vectors
    
    //float s[2][4] = {0.f}; // "static" memory allocation
    // Vectors use "dynamic" memory allocation
    vector<vector<float>> stereoSignal;
    string stereoFilename = "stereoDrums.wav";
    
    audioread(stereoFilename,stereoSignal,Fs,bitDepth,numChannels);
    
    float width = 1.5f;
    stereoWidener(stereoSignal, width);
    
    string stereoOutName = "NewStereo.wav";
    audiowrite(stereoOutName,stereoSignal,Fs,bitDepth,numChannels);

    return 0;
}


void dBAmplitudeChange(vector<float> & x, const float dBAmp){
    
    // Convert to linear amplitude
    //float amp = 10.f ^ (dBAmp/20.f);
    float amp = pow(10.f , dBAmp/20.f);
    
    
    // Total number of samples
    int N = x.size();
    
    for (int n = 0 ; n < N ; ++n){
        x[n] *= amp;
    }
}


void stereoWidener(vector<vector<float>> & x , const float width)
{
    // New mono signals for "mid" and "sides"
    vector<float> sides;
    vector<float> mids;
    
    int N = x[0].size(); // number of samples in channel "0"
    
    sides.resize(N); // change the size to match total number of samples
    mids.resize(N);
    
    for (int n = 0 ; n < N ; ++n){
        // S = L-R
        sides[n] = 0.5f * (x[0][n] - x[1][n]);
        // M = L+R
        mids[n] = 0.5f * (x[0][n] + x[1][n]);
        
        // Change the width
        sides[n] *= width;
        mids[n] *= (2.f - width);
        
        // L = M + S
        x[0][n] = mids[n] + sides[n];
        // R = S - M
        x[1][n] = sides[n] - mids[n];
        
    }
    
    
    
}
