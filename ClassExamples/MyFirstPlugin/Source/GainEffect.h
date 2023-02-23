/*
  ==============================================================================

    GainEffect.h
    Created: 21 Feb 2023 1:39:40pm
    Author:  Eric Tarr

  ==============================================================================
*/

#pragma once

// Make sure to include the base class we want to use
#include "AudioEffect.h"

class GainEffect : public AudioEffect // syntax for inheritance
{
public:
    
    ~GainEffect () override {
        AudioEffect::~AudioEffect();
    } ;
    
    // Make a new function that "overrides" the one in AudioEffect
    float processSample(float x, const int c) override;
    
    // New function, not in AudioEffect
    void setGain(float newGain) {gain = newGain;}
    
private:
    
    float gain;
};
