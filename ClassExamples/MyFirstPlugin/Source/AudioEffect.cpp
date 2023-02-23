/*
  ==============================================================================

    AudioEffect.cpp
    Created: 21 Feb 2023 1:32:15pm
    Author:  Eric Tarr

  ==============================================================================
*/

#include "AudioEffect.h"

//float AudioEffect::processSample(float x, const int c){
//    
//    return x;
//}


void AudioEffect::processBlock(juce::AudioBuffer<float> &buffer)
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

void AudioEffect::processInPlace(float * buffer, const int numSamples, const int c){
    
    for (int n = 0 ; n < numSamples; ++n){
        float x = (*buffer); // de-reference current value
        
        x = processSample(x,c);
        
        *buffer = x; // over-write current value
        
        ++buffer; // move pointer to the next sample
    }
    
}


void AudioEffect::prepareToPlay(float sampleRate, int samplesPerBlock){
    
    Fs = sampleRate;
    bufferSize = samplesPerBlock;
}
