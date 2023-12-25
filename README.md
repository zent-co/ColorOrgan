# Color Organ Project
A color organ is a device that filters an audio signal into various frequency bands and the intesity of the audio signal in that frequency band is used to drive the brightness of a light. The intensity of the sound and brightness of the light a directly related to each other. 

## Project Motivation and Description
The first color organ I built was in Circuits/Electronics II in college. That color organ used three analog filters implemented with OpAmps and a single, small LED for each filter. When I started designing this color ogran, I considered implementing it with OpAmps, but ultimately decided against it due to the potential complications, and decided on a digital design instead. 

## Technical Overview
This color organ filters audio signals provided by an 1/8" audio jack into seven different channels for each channel (left and right) using seven band pass filters per channel. The filters detect the peak value in that frequency band and provide that to an Arduino Uno via A to D channels. That value is "filtered" by an expoential filter that transforms the signal into a visually pleasing, exponetially changing signal. The raw audio waveform is not pleasant to look at because [the human eye perceives logarithmic differences in light intesnsity](https://psychology.stackexchange.com/questions/5408/sensitivity-of-human-eye-to-luminance). 

Here is a block diagram of my color organ:

![Color Organ Block Diagram](resources/blockDiagram.png)

### Hardware
    1. Descriptions/block diagrams
    2. Pictures
    3. YouTube Videos

- [Sparkfun ESP32 Thing Plus](https://www.sparkfun.com/products/15663?gclid=CjwKCAiAp5qsBhAPEiwAP0qeJnRRSU4OE6ZlrzAAaxC8sL1j2-f2hIqKbaGOr5SEi_CV_tvKprVjEhoCCmUQAvD_BwE) to communicate via WiFi and control the RGB light. 
- [Adafruit NeoPixel Jewel RGB LED assembly](https://www.adafruit.com/product/2859?gad_source=1&gclid=CjwKCAiAp5qsBhAPEiwAP0qeJkzRK5o67oNMlqqDC8S1sDyIZCz12_C3Y6A9JUmND2r-IASDWLSKcRoCs48QAvD_BwE) for RGB light.
.

#### Hardware Pictures:


### Firmware
    1. Post Link to Actual Code. 
    2. Describe what code is doing. 

5. Integration
    1. Challenges in getting light math correct
    2. Final product in video format

- List 1
- List 2
  

## Future Feature Development List


