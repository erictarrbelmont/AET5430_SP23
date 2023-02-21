/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyFirstPluginAudioProcessorEditor::MyFirstPluginAudioProcessorEditor (MyFirstPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 400);
    
    gainKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    gainKnob.setBounds(100,50,125,125);
    gainKnob.setValue(0.0); // initial value
    gainKnob.setRange(-48.0,12.0,0.1); // (min, max, interval)
    gainKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    gainKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    addAndMakeVisible(gainKnob);
    
    driveKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    driveKnob.setBounds(300,50,125,125);
    driveKnob.setValue(5.0); // Initial value
    driveKnob.setRange(1.0,10.0,0.01); // (min, max, interval)
    driveKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    driveKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    addAndMakeVisible(driveKnob);
}

MyFirstPluginAudioProcessorEditor::~MyFirstPluginAudioProcessorEditor()
{
}

//==============================================================================
void MyFirstPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::cornflowerblue);
    g.setFont (35.0f);
    g.drawFittedText ("My First Plugin", getLocalBounds(), juce::Justification::centred, 1);
}

void MyFirstPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}


void MyFirstPluginAudioProcessorEditor::sliderValueChanged(juce::Slider * slider)
{
    // This is how we check which slider was moved  
    if (slider == &gainKnob){
        auto value = slider->getValue();
        audioProcessor.gainValue_dB = value;
    }
    if (slider == &driveKnob){
        audioProcessor.drive = slider->getValue();
    }
    //DBG(value);
}
