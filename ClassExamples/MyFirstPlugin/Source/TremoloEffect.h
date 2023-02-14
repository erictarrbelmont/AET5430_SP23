/*
  ==============================================================================

    TremoloEffect.h
    Created: 7 Feb 2023 1:07:30pm
    Author:  Eric Tarr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class TremoloEffect{
    
public:
    
    float processSample(float x, const int c);
    
    void processBlock(juce::AudioBuffer<float> & buffer);
    
    void processInPlace(float * buffer, const int numSamples, const int channel);
    
    void setRate(float freqHz);
    
    void setDepth(float depth);
    
    void prepareToPlay(float sampleRate, float samplesPerBlock);
    
private:
    
    float currentAngle[2] = {0.f}; // in radians, one angle for left and right
    
    float angleChange = 0.f;
    
    float lfoAmp = 0.5f;
    float lfoOffset = 0.5f;
    
    float Fs = 44100.f;
    
    float piX2 = (float) (M_PI * 2.f);
    
    void updateCurrentAngle(const int c);
    
};
