An autonomous vehicle, utilizing an ESP8266 microcontroller, has been constructed by integrating it into a robot car chassis. The ESP8266 provides the necessary computing power and connectivity for the vehicle's operation. Additionally, a smartphone camera has been mounted on the car, allowing it to capture live video footage.

The live video stream from the smartphone camera is transmitted across the local network, enabling real-time monitoring and analysis. On a connected computer, specialized software leveraging OpenCV-Python and TensorFlow processes the incoming video feed. OpenCV is utilized for image processing tasks such as object detection, recognition, and tracking, while TensorFlow handles more complex tasks such as machine learning-based object classification.

Within this software framework, the primary objective is to determine the optimal direction or heading for the autonomous vehicle. This determination is based on various factors extracted from the processed video feed, including object detection, lane detection, obstacle avoidance, and other relevant environmental cues.

Once the heading or desired trajectory has been calculated, this information is transmitted back to the ESP8266 microcontroller onboard the vehicle. This communication is typically facilitated through HTTP requests, allowing for seamless integration with the vehicle's control system.

Upon receiving the heading information, the ESP8266 adjusts the vehicle's steering mechanism or motor controls accordingly, guiding it along the designated path. This closed-loop control system ensures that the vehicle can adapt to changing environmental conditions in real-time, enabling smooth and efficient autonomous navigation.

The entire process operates in a continuous loop, with the vehicle constantly capturing, transmitting, processing, and acting upon new visual information to navigate its environment autonomously. This integration of hardware and software components enables the creation of a sophisticated and adaptable autonomous vehicle system.



installation 
step 1: install this code on esp Esp\car\car.ino [add the local wifi ssid and password ]
step 2: install IP webcam app on Android smartphone connect to the same network and run the server 
step 3: run this python file with all the dependencies src\newControl\main.py [add the video camera ip and robo car ip]

![image](https://github.com/pavanb0/AnnCar/assets/96296445/3368ead0-8c6c-42ea-88ee-a8d9380ee403)
