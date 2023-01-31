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


// Enum - enumerated list
// "Type" is MyEffects
enum MyEffects {Reverb, Distortion, Chorus, Echo};

//int Reverb = 0;
//int Distortion = 1;
//int Chorus = 2;


// Structure "struct" data type
// A group of variables that all go together
struct AudioInfo {
    int sampleRate = 44100;
    int bitDepth = 16;
    int numChannels = 2;
    string format = "wav";
    string filename;
};

// Example for audio data to store samples of a signal
//float sig[1024] = {0.f}; // Primative array
// vector<float> sig;
//
// AudioBuffer is a special for holding samples of a signal
class AudioBuffer
{
public:
    
    void setBufferSize( int size ){
        bufferSize = size;
    }
    
    int getBufferSize(){
        return bufferSize;
    }
    
    void fillChannelOfBuffer(vector<float> sig, int channel, int & sigIndex){
        int N = sig.size();
        
        for (int i = 0; i < bufferSize ; ++i){
            if (sigIndex < N){
                x[channel][i] = sig[sigIndex];
                sigIndex++;
            }
            else
                x[channel][i] = 0.f;
        }
        
    }
    
    float getSample( int c, int sampleNumber){
        return x[c][sampleNumber];
    }
    
    void setSample(float value, int c , int sampleNumber){
        x[c][sampleNumber] = value;
    }
    
private:
    
    int bufferSize = 1024;
    
    // Stereo buffer with 2 channels, max of 1024 samples
    float x[2][1024] = {{0.f}}; // Actual data is stored in primative array
    
};


// Example for an audio effect
class GainProcessor
{
public:
    // Things that can be accessed on an object
    void setAmplitudeIndB(float dBAmp)
    {
        // Consider adding some checks to make sure
        // dBAmp is valid
        
        A = pow(10.f , dBAmp/20.f);
    }
    
    void processBuffer(AudioBuffer & x)
    {
        // Total number of samples
        int N = x.getBufferSize();
        
        for (int n = 0 ; n < N ; ++n){
            float sample = x.getSample(0, n);
            x.setSample(sample * A, 0, n);
        }
    }
    
private:
    // Internal stuff to use
    float A = 1.f; // Linear amplitude
    
};



void setSamplingRate(int & x){
    x = 44100;
    //return x;
}

void dBAmplitudeChange(vector<float> & x, const float dBAmp);


void myPointerFunction(float * w){
    float q = *w;
    float n = q + 5.f;
}


void processSignal(float * x, const int numSamples){
    for (int n = 0; n < numSamples ; ++n){
        float sample = *x; // get the sample value at the index of "x"
        
        float y = sample + n;
        
        *x = y; // set "y" to the value that "x" points to
        
        // Pointers can be incremented
        x++; // move to the next memory location in our signal
        
        
    }
}

void stereoWidener(vector<vector<float>> & x , const float width);

int main() {
    
    string filename = "AcGtr.wav";
    int Fs = 48000;
    int bitDepth;
    int numChannels;
    // float signal[5]; cannot use primative array due to memory allocation
    // Must use fancy "array"
    vector<float> signal;
    
    audioread(filename, signal, Fs, bitDepth, numChannels);
    
    AudioBuffer buffer;
    buffer.setBufferSize(256);
    
    GainProcessor gain;
    
    gain.setAmplitudeIndB(-12.f);
    
    int N = signal.size();
    int i = 0;
    while (i < N){
        // 0 for mono signal
        buffer.fillChannelOfBuffer(signal, 0, i);
        gain.processBuffer(buffer);
    }
    
    
    
    
    
    
    
    //setSamplingRate(Fs);
    
    // We supply "filename"
    // Function fills in sig,Fs,bit,channels (empty to begin with)
//    audioread(filename, signal, Fs, bitDepth, numChannels);
    
    // Total number of samples
//    int N = signal.size();
//
//    for (int n = 0 ; n < N ; ++n){
//
//        signal[n] *= 0.25f;
//        //signal.at(n) *= 0.25f; // Both ways for indexing
//    }
  
//    dBAmplitudeChange(signal, -24.f);
//
//    string outName = "NewSignal.wav";
//
//    audiowrite(outName,signal,Fs,bitDepth,numChannels);
    
    
    
//     Stereo signals
//     In C++, one way to create a "matrix"
//     is with a vector of vectors
//
//    float s[2][4] = {0.f}; // "static" memory allocation
//     Vectors use "dynamic" memory allocation
//    vector<vector<float>> stereoSignal;
//    string stereoFilename = "stereoDrums.wav";
//
//    audioread(stereoFilename,stereoSignal,Fs,bitDepth,numChannels);
//
//    float width = 1.5f;
//    stereoWidener(stereoSignal, width);
//
//    string stereoOutName = "NewStereo.wav";
//    audiowrite(stereoOutName,stereoSignal,Fs,bitDepth,numChannels);

    float x = 3.f;
    float * y;
    y = &x; // get the address of "x" and assign it to a "pointer" that holds addresses
    
    cout << x << endl;
    cout << y << endl;
    cout << *y << endl; // de-reference, "get out the value from the address that y points to"

    float z = 4.f + (*y);
    cout << z << endl;
    
    myPointerFunction(y);
    myPointerFunction(&x); // both are acceptable inputs
    
    
    float sig[6] = {0.f};
    float * index;
    index = sig; // variable name of a primative array is a pointer
    
    int numSamples = 6;
    
    processSignal(index, numSamples);
    
    // Create a new variable called "effectA"
    // Assign it a value from our enumerated list
    MyEffects effectA = MyEffects::Reverb;
    
    if (effectA == MyEffects::Chorus){
        
    }
    else if (effectA == MyEffects::Distortion){
        
    }
    else if (effectA == MyEffects::Reverb){
        
    }

    
    // Use our AudioInfo
    AudioInfo info;
    AudioInfo info2;
    info.filename = "MyFile.wav";
    info.bitDepth = 24;
    info.numChannels = 1;
    
    
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
