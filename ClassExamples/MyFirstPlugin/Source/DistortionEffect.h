/*
  ==============================================================================

    DistortionEffect.h
    Created: 2 Feb 2023 1:39:11pm
    Author:  Eric Tarr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class DistortionEffect
{
  
public:
    
    float processSample(float x);
    
    void processBlock(juce::AudioBuffer<float> & buffer);
    
    void processInPlace(float * buffer, const int numSamples);
    
    void setDrive (float newDrive);
    
private:
    
    float drive = 1.f;
    
};
