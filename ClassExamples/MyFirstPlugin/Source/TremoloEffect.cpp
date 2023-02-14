/*
  ==============================================================================

    TremoloEffect.cpp
    Created: 7 Feb 2023 1:07:30pm
    Author:  Eric Tarr

  ==============================================================================
*/

#include "TremoloEffect.h"


float TremoloEffect::processSample(float x, const int c){
    
    // LFO (modulator)
    float m = lfoAmp * sin(currentAngle[c]) + lfoOffset;
    
    float y = x * m;
    
    // Update currentAngle for the next sample
    updateCurrentAngle(c);
    
    return y;
}


void TremoloEffect::processBlock(juce::AudioBuffer<float> &buffer)
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

void TremoloEffect::processInPlace(float * buffer, const int numSamples, const int c){
    
    for (int n = 0 ; n < numSamples; ++n){
        float x = (*buffer); // de-reference current value
        
        x = processSample(x,c);
        
        *buffer = x; // over-write current value
        
        ++buffer; // move pointer to the next sample
    }
    
}


void TremoloEffect::setRate(float freqHz){
    
    angleChange = freqHz * piX2 / Fs;
    //M_2_PI = 2.f * M_PI
    //M_PI_2 = M_PI / 2.f
}

void TremoloEffect::setDepth(float depth){
    // note: depth is from 0-1
    lfoAmp = depth / 2.f;
    lfoOffset = 1.f - lfoAmp;
    
}


void TremoloEffect::prepareToPlay(float sampleRate, float samplesPerBlock){
    Fs = sampleRate;
}


void TremoloEffect::updateCurrentAngle(const int c){
    currentAngle[c] += angleChange;
    if (currentAngle[c] > piX2){
        currentAngle[c] -= piX2;
    }
}

























