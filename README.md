# Video Processing

Real-time camera input processing using C++ and OpenCV — includes color inversion, flipping, and scalable resolution, with live FPS counter.

---

## Features

- Capture video from default webcam
- Apply real-time transformations:
  - Flip image (horizontal & vertical): toggle with `F`
  - Invert colors: toggle with `I`
  - Change scale: use `1` (100%), `2` (50%), `3` (25%)
- Display FPS counter in top-left
- Exit with `ESC`

---

## Requirements

- [OpenCV 4.5.x or later](https://opencv.org/releases/)
- C++17 compatible compiler (tested with MSVC `cl.exe`)
- Windows (for this setup)

---

## Building with Makefile (Windows)

1. **Install OpenCV** and set the path to your OpenCV root.
   - Example path: `C:\opencv`
2. **Open Developer Command Prompt for VS 2022**
3. **Navigate to project folder** (where `Makefile` is):
   ```bash
   cd path\to\project
