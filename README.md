# bluetooth-car
Code for a car powered by an arduino using Bluetooth

# controls
The car is controlled by an app (myrobot.apk) wich was made with thunkable. The app sends bluetooth signals to the arduino which executes them

# car
the car has two motors, an arduino and a bluetooth module (HC-05)

# Protocol
the App forawards a 4-5 byte String. 
for example 
            
            R100
            ^^^^
            
The first char defines which motor is used.
The rest defines a positive or negativ integer between -255-255.
