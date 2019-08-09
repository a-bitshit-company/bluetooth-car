# bluetooth-car
Code for a car which uses an arduino with a bluetooth module to get controls from a mobile app

# controls
The car is controlled by an app (myrobot.apk) wich was made with thunkable. The app sends bluetooth signals to the arduino which executes them

# car
the car has two motors, an arduino and a bluetooth module(HC-05) built in

# Protocol
the App forwards a 4-5 byte String. 
for example 
            
            R100
            ^^^^
            
The first char defines which motor is used.
The rest defines signed integer between -255-255.
