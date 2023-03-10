/*
  ==============================================================================

    GainEffect.cpp
    Created: 21 Feb 2023 1:39:40pm
    Author:  Eric Tarr

  ==============================================================================
*/

#include "GainEffect.h"

float GainEffect::processSample(float x, const int c){
    
    float newVar = Fs/1000.f;
    
    return gain * x;
}
