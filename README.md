# 🚛 Truck Platooning System

A semi-autonomous truck platooning prototype built using Arduino Uno for the B.Tech ECE project at JNTUH University College of Engineering Sultanpur (2025–26).

## 📌 Project Overview

This system enables multiple vehicles to move in a coordinated convoy under the control of a single lead vehicle. The follower truck autonomously tracks the leader using sensors and Bluetooth communication.

## ⚙️ Components Used

| Component |                                                |Purpose |
| Arduino Uno (ATmega328P) |                                 |Main microcontroller |
| L298N Motor Driver |                                       |Motor speed & direction control |
| HC-SR04 Ultrasonic Sensor |                                |Inter-vehicle distance measurement |
| IR Sensors (Left & Right) |                                |Directional tracking |
| HC-05 Bluetooth Module |                                   |Wireless communication |
| DC Motors + Robot Chassis |                                |Locomotion |

## 🔧 How It Works

- The **leader truck** is controlled via a Bluetooth mobile app
- The **follower truck** autonomously maintains safe distance using ultrasonic sensing
- IR sensors assist with directional correction
- Emergency stop triggers if an obstacle is detected within 10 cm

## 👨‍💻 Team

- A S Yajat Kumar (24SS1A0401)
- Jupelli Shiva Manishwari (24SS1A0428)
- Konduri Poojitha (24SS1A0434)
- Neradukomma Manicharan (24SS1A0447)
- Kummari Ramesh (24SS1A0435)

**Guide:** Mr. T. Mohan Das  
**Department:** ECE, JNTUHUCES

## 📁 Repository Structure
