/*
  ==============================================================================

    DistortionEffect.cpp
    Created: 2 Feb 2023 1:39:11pm
    Author:  Eric Tarr

  ==============================================================================
*/

#include "DistortionEffect.h"



float DistortionEffect::processSample(float x)
{
    x = (2.f/M_PI) * atan(x * drive); // Distortion
    return x;
}

void DistortionEffect::processBlock(juce::AudioBuffer<float> &buffer)
{
    const int numChannels = buffer.getNumChannels();
    const int numSamples = buffer.getNumSamples();
    
    for (int c = 0; c < numChannels ; ++c){
        
        for (int n = 0; n < numSamples ; ++n){
            
            float x = buffer.getWritePointer(c) [n];
            //x = (2.f/M_PI) * atan(x * drive); // Distortion
            
            x = processSample(x);
            
            buffer.getWritePointer(c) [n] = x;
        }
        
    }
}

void DistortionEffect::processInPlace(float * buffer, const int numSamples){
    
    for (int n = 0 ; n < numSamples; ++n){
        float x = (*buffer); // de-reference current value
        
        //x = (2.f/M_PI) * atan(x * drive); // Distortion
        x = processSample(x);
        
        *buffer = x; // over-write current value
        
        ++buffer; // move pointer to the next sample
    }
    
}




void DistortionEffect::setDrive(float newDrive){
    
//    if (newDrive >= 1.f)
//    {
//        if (newDrive <= 10.f)
//        {
//            drive = newDrive;
//        }
//    }
    
    // JUCE Way
    //newDrive = juce::jmax(newDrive, 1.f);
    //newDrive = juce::jmin(newDrive, 10.f);
    
    drive = juce::jlimit(1.f, 10.f, newDrive);
    
    
}
