/*
  ==============================================================================

    AudioEffect.h
    Created: 21 Feb 2023 1:32:15pm
    Author:  Eric Tarr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
// This is a generic base class for doing audio processing
// Other effects can inherit from it to use its functionality and variables
class AudioEffect
{
public:
    
    // Make this function to be able to be overridden "virtual"
    virtual float processSample(float x, const int c);
    
    void processBlock(juce::AudioBuffer<float> & buffer);
    
    void processInPlace(float * buffer, const int numSamples, const int channel);
    
    void prepareToPlay(float sampleRate, int samplesPerBlock);
    
private:
    
    float Fs;
    int bufferSize;
};
