# AITestGame
# 🎯 Unreal Engine Shooter AI

This was the first game I developed using **Unreal Engine 4**, created as a solo project to learn core gameplay systems and AI behavior. It’s a simple first-person shooter featuring a functional enemy AI and basic player mechanics.

---

## 💡 About the Game

This project simulates a small-scale tactical shooter environment. The player explores a simple level while facing off against an AI enemy that can detect, chase, and attack. Both the player and enemy must manage ammo, line of sight, and movement — creating a reactive and teachable encounter system.

---

## 🧑‍💻 What I Built

This project was a deep dive into Unreal Engine's Blueprint system (or C++ if applicable), focusing on gameplay logic and AI behavior. I implemented:

### 🔫 Player Features:
- First-person shooting with projectile mechanics
- Reload system with ammo tracking
- Smooth movement and collision handling
- Ammo and health pickups

### 🧠 AI Features:
- Wanders within a defined patrol radius
- Detects player via line-of-sight
- Follows the player’s **last known location** if they lose sight
- **Shoots** when within range and reloading is handled dynamically
- **Hides** or retreats when low on health, ammo
- Stops chasing if the player escapes or breaks visual contact

All behaviors were built using UE4's AI tools (Behavior Trees, Blackboards, and NavMesh).

---

## 🎥 Demo Video

[![Watch the demo](https://img.youtube.com/vi/YOUR_VIDEO_ID_HERE/hqdefault.jpg)](https://youtu.be/YOUR_VIDEO_ID_HERE)

---

## 📸 Screenshots

<p align="center">
  <img src="images/ShooterScreenshot1.PNG" width="45%" />
  <img src="images/ShooterScreenshot2.PNG" width="45%" />
</p>
<p align="center">
  <img src="images/ShooterScreenshot3.PNG" width="45%" />
</p>

---

## 🛠️ Built With

- **Unreal Engine 4**
- Blueprints (or C++ if applicable)
- C++ scripts
- UE Navigation System + Behavior Trees

---

## 📌 Reflection

This was my first full project in Unreal Engine, where I gained hands-on experience with:
- AI logic and blackboard systems
- First-person controller setup
- Creating believable enemy behaviors
- Debugging in a 3D environment

It laid the foundation for my later work in team-based Unreal projects.

---

## 📝 License

This repository contains only documentation and media. No game code or proprietary assets are distributed.
