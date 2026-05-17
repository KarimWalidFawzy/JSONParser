# JSONParser

A simple Qt-based desktop application for loading and parsing JSON files containing users and posts.

## Overview

`JSONParser` is a Qt/C++ project that reads a JSON file, parses `users` and `posts` arrays, and displays the extracted data in a text area.

## Features

- Loads a JSON file via a file picker
- Parses user information (`id`, `name`)
- Parses post information (`post_id`, `user_id`, `post_content`, `topics`)
- Displays parsed data in a read-only text view

## JSON Format

The parser expects JSON with the following top-level objects:

- `users`: array of user objects
- `posts`: array of post objects

Example structure:

```json
{
  "users": [
    {
      "id": "0",
      "name": "Karim",
      "posts_ids": [""],
      "followers_ids": [""]
    }
  ],
  "posts": [
    {
      "post_id": "",
      "user_id": "",
      "post_content": "",
      "topics": ["", ""]
    }
  ]
}
```

> The parser currently reads `name` and `id` from users, and `post_id`, `user_id`, `post_content`, plus optional `topics` from posts.

## Build Instructions

This project uses CMake and Qt Widgets. It supports both Qt 6 and Qt 5.

### Prerequisites

- Qt development environment installed (Qt 5 or Qt 6)
- CMake 3.16 or newer
- A C++17-capable compiler

### Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Run

- Launch the generated `JSONParser` executable
- Click the button to open a `.json` file
- Parsed data will appear in the text display area

## Project Structure

- `main.cpp` - application entry point
- `mainwindow.*` - Qt main window UI and logic
- `parser.*` - JSON parsing implementation
- `user.*`, `post.*` - model classes for parsed data
- `example.json` - sample JSON structure

## Notes

- The app is built as a Qt Widgets application
- The parser uses Qt JSON classes (`QJsonDocument`, `QJsonObject`, `QJsonArray`)
- If JSON input is malformed or missing expected arrays, the display will show empty parsed results
