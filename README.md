

# ColorOrgan
This is a color organ. It filters audio signals provided by 1/8" audio jack into seven different channels for each channel (left and right) using seven band pass filters per channel. The filters detect the peak value in that frequency band and provide that to an Arduino Uno via A to D channels. That value is "filtered" by an expoential filter that transforms the signal into a visually pleasing signal. The raw audio waveform is not pleasant to look at because [the human eye perceives logarithmic differences in light intesnsity](https://psychology.stackexchange.com/questions/5408/sensitivity-of-human-eye-to-luminance). 

## Project Motivation and Description
STORY OF HOW YOU BUILT ONE I NCOLLEGE WITH ANALOG PARTS AND ALWAYS WANTED TO BUILD A BIGGER/BETTER ONE

## Technical Overview
The following sections describe the technical details of the Tub Light system.

### Hardware
- [Sparkfun ESP32 Thing Plus](https://www.sparkfun.com/products/15663?gclid=CjwKCAiAp5qsBhAPEiwAP0qeJnRRSU4OE6ZlrzAAaxC8sL1j2-f2hIqKbaGOr5SEi_CV_tvKprVjEhoCCmUQAvD_BwE) to communicate via WiFi and control the RGB light. 
- [Adafruit NeoPixel Jewel RGB LED assembly](https://www.adafruit.com/product/2859?gad_source=1&gclid=CjwKCAiAp5qsBhAPEiwAP0qeJkzRK5o67oNMlqqDC8S1sDyIZCz12_C3Y6A9JUmND2r-IASDWLSKcRoCs48QAvD_BwE) for RGB light.
- Custom 3D printed adapter to secure NeoPixel Jewel to tub light port hole. 
- Level Shifter for ESP32 (3V system) to [Adafruit NeoPixel Jewel RGB LED assembly](https://www.adafruit.com/product/2859?gad_source=1&gclid=CjwKCAiAp5qsBhAPEiwAP0qeJkzRK5o67oNMlqqDC8S1sDyIZCz12_C3Y6A9JUmND2r-IASDWLSKcRoCs48QAvD_BwE) (5V system) using TI's [SN74AHCT125 Octal Buffer](https://www.ti.com/product/SN74AHCT125?utm_source=google&utm_medium=cpc&utm_campaign=asc-null-null-GPN_EN-cpc-pf-google-wwe&utm_content=SN74AHCT125&ds_k=SN74AHCT125&DCM=yes&gad_source=1&gclid=CjwKCAiAyp-sBhBSEiwAWWzTnt-SE3ptIo6v0rLhpGXk40SaxN7Lgv-MlV34kCT6CDqxO0mAszq7FxoCUzwQAvD_BwE&gclsrc=aw.ds)
- USB B plug for power from a 5V USB power supply.
- Pneumatic push switch tied to ESP32 digital input ISR line to toggle power on and off.
- Water tight box with cable gland for RGB light wiring.

#### Hardware PIctures:

| Tub Light Controller Installed | Tub Light Controller Opened |
| :--------------: | :------------: |
| <img src="resources/hardware/tubLightInstalled.jpg"> | <img src="resources/hardware/openView.jpg"> |

| Light Adapter Front View | Light Adapter Side View |
| :--------------: | :------------: |
| <img src="resources/hardware/lightAdapterFront.jpg"> | <img src="resources/hardware/lightAdapterSide.jpg"> |

### Firmware
- Connects to household WiFi, for local network use only.
- 4 hour inactivity auto light shut off.
- Physical button turns light on and off via interrupt service routine.
- The light can also be turned on and off via WiFi commands.
- Uses a WebServer to establish initial connection with App and reports light state to App.
- Uses a UDP port to receive on/off and color change messages.
- UDP messages are sent via JSON formatted text. The firmware must deserialize the JSON message to set the proper light color.
- Firmware Updatable via FOTA from Arduino IDE.
  
### Android App
- Based on MVC architecture
- Turn light on or off with power button at top.
- Select from any color on the color wheel.
- If color is selected from the color wheel, then it can be dimmed with the slider bar.
- Our favorite colors are set as favorites with the button the color the light will be.
- Retrieves the status of the light at startup from the WebServer running on the ESP32, sets power on/off appropriately.
- Sends commands via UDP to the ESP32 to set the light color, brightness, or to turn the light on/off.
  
#### Screenshots:
| Initial Screen | Light Dimmed |
| :--------------: | :------------: |
| <img src="resources/appScreenshots/screenWithTurnPowerOn.png" width="66%" height="66%"> | <img src="resources/appScreenshots/screenWithTurnSliderDimmed.png" width="66%" height="66%">|

## Future Feature Development List
- Slow Color Change
- Candle/Fire Flicker
- User based favorite color list
- Move UDP code in App into ControllerCompositionRoot for depedency injection.



0. Overview
    1. What is a Color Organ?
    2. Description of yours (Left and right channel, how many filters per channel) and its theory of operation
2. Hardware
    1. Descriptions/block diagrams
    2. Pictures
    3. YouTube Videos
3. Software
    1. Post Link to Actual Code. 
    2. Describe what code is doing. 
5. Integration
    1. Challenges
    2. Final product in video format
