#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;
using namespace std::chrono;

int main() {
    VideoCapture cap(0); // open the default camera

    if (!cap.isOpened()) {
        cerr << "Error: Could not open camera." << endl;
        return -1;
    }

    // Set default resolution
    int width = 640;
    int height = 480;
    cap.set(CAP_PROP_FRAME_WIDTH, width);
    cap.set(CAP_PROP_FRAME_HEIGHT, height);

    bool invert = true;
    bool flipImage = true;
    double scaleFactor = 0.75;

    Mat frame;
    auto lastTime = high_resolution_clock::now();
    int frameCount = 0;
    double fps = 0.0;

    while (true) {
        cap >> frame;
        if (frame.empty()) {
            cerr << "Error: Empty frame." << endl;
            break;
        }

        // Apply scaling
        Mat scaled;
        resize(frame, scaled, Size(), scaleFactor, scaleFactor);

        // flip
        Mat flipped = scaled.clone();
        if (flipImage) {
            flip(scaled, flipped, -1);
        }

        // invert
        Mat processed = flipped.clone();
        if (invert) {
            bitwise_not(flipped, processed);
        }

        // FPS counter
        frameCount++;
        auto now = high_resolution_clock::now();
        duration<double> elapsed = now - lastTime;
        if (elapsed.count() >= 1.0) {
            fps = frameCount / elapsed.count();
            frameCount = 0;
            lastTime = now;
        }

        // Draw text overlay
        string legend = "Keys: [I] Invert | [F] Flip | [+/-] Scale | [ESC] Quit";
        putText(processed, legend, Point(10, processed.rows - 30), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255), 1);
        string fpsLabel = "FPS: " + to_string(int(fps));
        putText(processed, fpsLabel, Point(10, 25), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 1);

        imshow("Processed Video", processed);

        // Handle keyboard input
        int key = waitKey(1);
        if (key == 27) break; // ESC
        else if (key == 'i' || key == 'I') invert = !invert;
        else if (key == 'f' || key == 'F') flipImage = !flipImage;
        else if (key == '+' || key == '=') {
            scaleFactor = min(2.0, scaleFactor + 0.05);
            cout << "Scale increased to: " << scaleFactor << endl;
        }
        else if (key == '-' || key == '_') {
            scaleFactor = max(0.1, scaleFactor - 0.05);
            cout << "Scale decreased to: " << scaleFactor << endl;
        }
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
