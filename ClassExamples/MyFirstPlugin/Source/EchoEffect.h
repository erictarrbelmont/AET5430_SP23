/*
  ==============================================================================

    EchoEffect.h
    Created: 9 Feb 2023 1:12:45pm
    Author:  Eric Tarr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>


class RevDelayEffect {
 
public:
    
    float processSample(float x, const int c);
    
    void setDelayMS(float delayMS);
    
    void prepareToPlay(double sampleRate, int bufferSize){
        Fs = (float) sampleRate;
    }
    
private:
    
    // One sample of delay
    static const int SIZE = 24000;
    float delayBuffer[SIZE][2] = {0.f}; // left and right channels
    int i[2] = {0};
    int increment = 1;
    
    
    int delaySamples = 10000;
    float Fs = 48000.f;
};


class DelayEffect {
 
public:
    
    float processSample(float x, const int c);
    
    void setDelayMS(float delayMS);
    
    void prepareToPlay(double sampleRate, int bufferSize){
        Fs = (float) sampleRate;
        r[0] = w[0] - delaySamples;
        r[1] = w[1] - delaySamples;
    }
    
private:
    
    // One sample of delay
    static const int SIZE = 24000;
    float delayBuffer[SIZE][2] = {0.f}; // left and right channels
    int w[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
    int r[2] = {0}; // read index for buffer (output)
    
    int delaySamples = 10000;
    float Fs = 48000.f;
};


class EchoEffect {

public:
    
    float processSample(float x, const int c);
    
    void processBlock(juce::AudioBuffer<float> &buffer);
    
    void processInPlace(float * buffer, const int numSamples, const int c);
    
    void setWet(float newWet) {wet = newWet;}
    
    void prepareToPlay(double sampleRate, int bufferSize){
        delay.prepareToPlay(sampleRate, bufferSize);
    }
    
    void setDelayMS(float delayMS){
        delay.setDelayMS(delayMS);  
    }
    
private:
    RevDelayEffect delay;
    
    float wet = 0.5f;
    
};




