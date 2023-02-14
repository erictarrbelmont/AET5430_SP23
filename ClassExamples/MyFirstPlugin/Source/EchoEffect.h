/*
  ==============================================================================

    EchoEffect.h
    Created: 9 Feb 2023 1:12:45pm
    Author:  Eric Tarr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>



class DelayEffect {
 
public:
    
    float processSample(float x, const int c);
    
private:
    
    // One sample of delay
    float delayBuffer[10000][2] = {0.f}; // left and right channels
    int i[2] = {0}; // index for buffer
};


class EchoEffect {

public:
    
    float processSample(float x, const int c);
    
    void processBlock(juce::AudioBuffer<float> &buffer);
    
    void processInPlace(float * buffer, const int numSamples, const int c);
    
    void setWet(float newWet) {wet = newWet;}
    
private:
    DelayEffect delay;
    
    float wet = 0.5f;
    
};




