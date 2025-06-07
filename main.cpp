#include <opencv2/opencv.hpp>
const int win_size = 800;

void draw_sim() {
	cv::Mat canvas(win_size, win_size, CV_8UC3, cv::Scalar(255, 255, 255));
	cv::imshow("Bridge Simulator", canvas);
}

int main() {
    cv::namedWindow("Bridge Simulator");


    // Main loop
    while (true) {
        draw_sim();
        int key = cv::waitKey(16);
        if (key == 27 || key == 'q') break;
    }

    cv::destroyAllWindows();
    return 0;
}

