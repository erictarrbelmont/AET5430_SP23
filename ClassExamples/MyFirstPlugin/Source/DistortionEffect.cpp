/*
  ==============================================================================

    DistortionEffect.cpp
    Created: 2 Feb 2023 1:39:11pm
    Author:  Eric Tarr

  ==============================================================================
*/

#include "DistortionEffect.h"



float DistortionEffect::processSample(float x, float drive)
{
    x = (2.f/M_PI) * atan(x * drive); // Distortion
    return x;
}

void DistortionEffect::processBlock(juce::AudioBuffer<float> &buffer, float drive)
{
    const int numChannels = buffer.getNumChannels();
    const int numSamples = buffer.getNumSamples();
    
    for (int c = 0; c < numChannels ; ++c){
        
        for (int n = 0; n < numSamples ; ++n){
            
            float x = buffer.getWritePointer(c) [n];
            x = (2.f/M_PI) * atan(x * drive); // Distortion
            buffer.getWritePointer(c) [n] = x;
        }
        
    }
}

void DistortionEffect::processInPlace(float * buffer, float drive, const int numSamples){
    
    for (int n = 0 ; n < numSamples; ++n){
        float x = 2.f * (*buffer); // de-reference current value
        
        x = (2.f/M_PI) * atan(x * drive); // Distortion
        
        *buffer = x; // over-write current value
        
        ++buffer; // move pointer to the next sample
    }
    
}


