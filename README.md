## About SafeRail
**SafeRail** is a project made in Qt 6.7 which takes Radar data and visualize it on screen with different camera screens connected over RTSP(Real-Time Streaming)

![image](https://github.com/user-attachments/assets/b3d6f2e1-40da-4eaf-8d02-dbd730efb861)
![image](https://github.com/user-attachments/assets/689e6c21-9533-4872-8c71-0dada76f4b5d)



### Features:
* Ability to get data
  * via Tcp Socket for Radar
* Ability to stream 3 feeds at a time
* Two seperate modes for streaming and radar visual
* Configuration:
  * Radar connection state
  * Filters configuration (cluster, objects)
* Uses Gstreamer to stream the multiple streams
* Ability to save user configuration after application closes or restarts

### Supported OS
  * Windows

### P.S.
* You have to have Gstreamer installed on your system for it to work
