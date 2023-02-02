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
    
    float processSample(float x, float drive);
    
    void processBlock(juce::AudioBuffer<float> & buffer, float drive);
    
    void processInPlace(float * buffer, float drive, const int numSamples);
    
private:
    
    
};
