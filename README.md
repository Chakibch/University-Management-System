# University Dormitory & Restaurant Management System (UDRMS)

A Qt desktop application built with **Object-Oriented Programming (C++)** to manage university dormitory accommodation and restaurant services.

ENSIA 2025-2026 — Object-Oriented Programming Project

---

## Overview

UDRMS models a real university dormitory system: students are accommodated across **5 dormitories**, each containing **230 rooms** (1150 rooms in total). Each dormitory has exactly one restaurant offering a weekly menu. The system is built around a central `University` class that stores all students, rooms, and restaurant data, and persists it to a **JSON file** for data continuity across sessions.

## Features

- **Student Management** — add, remove, and view students (ID, name, academic year, accommodation status)
- **Room Management** — view all rooms in a filterable table (All / Available / Occupied), with automatic over-occupancy prevention
- **Dormitory Management** — per-dormitory occupancy breakdown across all 5 dorms
- **Restaurant Management** — browse the weekly menu (breakfast, lunch, dinner) per dormitory and day
- **Dashboard** — live statistics (students, rooms, dorms, meals) shown through animated progress bars
- **Data Persistence** — student and room assignment data is saved to `data.json` and reloaded on startup

## Project Structure

```
├── Data classes
│   ├── studentinfo.h / .cpp        Student data (ID, name, year, dorm, room)
│   ├── roominfo.h / .cpp           Room data (number, dorm, assigned student)
│   ├── restaurantinfo.h / .cpp     Weekly menu per dorm (breakfast/lunch/dinner)
│   └── university.h / .cpp         Central data store (students, rooms, restaurants)
│                                    Handles persistence (saveData / loadData)
│
├── UI widgets (Qt Designer + .cpp logic)
│   ├── mainwindow.h / .cpp / .ui   Sidebar navigation + stacked widget
│   ├── dashboard.h / .cpp / .ui    Statistics overview
│   ├── students.h / .cpp / .ui     Student table + add/remove
│   ├── rooms.h / .cpp / .ui        Room table with All/Available/Occupied filters
│   ├── dormitory.h / .cpp / .ui    Per-dormitory occupancy view
│   ├── restaurant.h / .cpp / .ui   Weekly menu browser
│   ├── addstudentdialog.h / .cpp / .ui
│   └── sidebar.h / .cpp / .ui
│
├── main.cpp
└── data.json                       Persisted application data
```

## OOP Concepts Applied

- **Encapsulation** — all data classes (`StudentInfo`, `RoomInfo`, `RestaurantInfo`) expose data only through getters/setters
- **Composition** — a `RoomInfo` *has a* `StudentInfo`; a dormitory *has a* `RestaurantInfo`
- **Singleton pattern** — `University` provides one shared instance accessible from every widget
- **Separation of concerns** — data classes are fully independent from UI/Qt widget classes

## Data Persistence

On launch, `University::loadData()` reads `data.json` and restores all students and their room assignments. On close, `MainWindow::closeEvent()` calls `University::saveData()` to write the current state back to disk.

## Build Requirements

- Qt 6 (Widgets module)
- C++17 or later
- Qt Creator (recommended) or `qmake` / `CMake`

## Screenshots 
<img width="1069" height="639" alt="image" src="https://github.com/user-attachments/assets/121ccef4-f0d1-4926-9f98-dccd62f654e8" />
<img width="2101" height="1285" alt="image" src="https://github.com/user-attachments/assets/175fc5ed-810a-4544-85e6-4af9be62ece6" />

## Authors
Chakib Mourad Eddine Chabane 
- OOP Project — 2025/2026
