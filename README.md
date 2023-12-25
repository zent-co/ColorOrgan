# Color Organ Project
This is a color organ. It filters audio signals provided by an 1/8" audio jack into seven different channels for each channel (left and right) using seven band pass filters per channel. The filters detect the peak value in that frequency band and provide that to an Arduino Uno via A to D channels. That value is "filtered" by an expoential filter that transforms the signal into a visually pleasing, exponetially changing signal. The raw audio waveform is not pleasant to look at because [the human eye perceives logarithmic differences in light intesnsity](https://psychology.stackexchange.com/questions/5408/sensitivity-of-human-eye-to-luminance). 

## Project Motivation and Description
STORY OF HOW YOU BUILT ONE I NCOLLEGE WITH ANALOG PARTS AND ALWAYS WANTED TO BUILD A BIGGER/BETTER ONE

## Technical Overview
The following sections describe the technical details and challenges in designing and building the Color Organ.

0. Overview
    1. What is a Color Organ?
    2. Description of yours (Left and right channel, how many filters per channel) and its theory of operation

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


