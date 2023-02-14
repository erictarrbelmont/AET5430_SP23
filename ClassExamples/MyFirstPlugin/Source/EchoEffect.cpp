/*
  ==============================================================================

    EchoEffect.cpp
    Created: 9 Feb 2023 1:12:45pm
    Author:  Eric Tarr

  ==============================================================================
*/

#include "EchoEffect.h"


float DelayEffect::processSample(float x, const int c){
    
    // one sample of delay
    int currentIndex = i[c];
    float y = delayBuffer[currentIndex][c];
    
    delayBuffer[currentIndex][c] = x;
    
    // Increment Index
    i[c]++;
    if (i[c] > 9999){
        i[c] = 0; // circular indexing
    }
    
    return y;
    
}



float EchoEffect::processSample(float x, const int c){
    
    float v = delay.processSample(x, c);
    
    float y = (1.f - wet) * x + wet * v;
    
    return y;
}


void EchoEffect::processBlock(juce::AudioBuffer<float> &buffer)
{
    const int numChannels = buffer.getNumChannels();
    const int numSamples = buffer.getNumSamples();
    
    for (int c = 0; c < numChannels ; ++c){
        
        for (int n = 0; n < numSamples ; ++n){
            
            float x = buffer.getWritePointer(c) [n];
            
            x = processSample(x,c);
            
            buffer.getWritePointer(c) [n] = x;
        }
        
    }
}

void EchoEffect::processInPlace(float * buffer, const int numSamples, const int c){
    
    for (int n = 0 ; n < numSamples; ++n){
        float x = (*buffer); // de-reference current value
        
        x = processSample(x,c);
        
        *buffer = x; // over-write current value
        
        ++buffer; // move pointer to the next sample
    }
    
}
