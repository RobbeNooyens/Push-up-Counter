# Push-up Counter
[Arduino Uno Project] Device that counts your 'valid' push-ups 

## Install

Download the file and open it in your Arduino IDE. Compile and push to the board to run the program.

## Hardware

Picture of the hardware architecture coming soon.
<br><br>
Hardware components:
- LCD 20x4
- Ultrasonic distance sensor
- Arduino Uno board
- Electronics board
- Led

## Libraries

[NewPing v1.9.1](https://libraries.io/platformio/NewPing)
<br>
[NewLiquidCrystal v1.3.5](https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads/)

## Usage

Put your hands in a push-up-position and lay the ultrasonic sensor betweem them right underneath your chest. Do a push-up. When you've bent your arms enough and your chest is low enough, the LED will light up. Once the LED lights up, lift your body up to it's starting position. This is one 'valid push-up'. The LCD will count how many valid push-ups you've done. Click the button on the Arduino board to reset the counter to 0.
