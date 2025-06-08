//g++ main.cpp -o main `pkg-config --cflags --libs opencv4`

#include <opencv2/opencv.hpp>
const int win_size = 1024; //800;


void draw_nodes();

cv::Mat canvas(win_size, win_size, CV_8UC3, cv::Scalar(255, 255, 255));
struct Node {
    cv::Point2f pos;
    bool isActive;
    Node(float x, float y) : pos(x, y), isActive(true) {}
};

std::vector<Node> nodes;

void draw_sim() {
    draw_nodes();
    cv::imshow("Bridge Simulator", canvas);
}

void draw_nodes() {
    for (const auto& node : nodes) {
        if (node.isActive)
            cv::circle(canvas, node.pos, 5, cv::Scalar(0, 255, 0), -1);
    }
}

int main() {
    cv::namedWindow("Bridge Simulator");

    //std::vector<Node> nodes;
    
    // Directly construct inside the vector: new Node(20, 30);
    nodes.emplace_back(20, 30);

    // Create a temporary: Node tmp(10, 10);
    // Then vector.push_back(tmp); --> copy or move
    nodes.push_back(Node(10, 10));
    
    // Main loop
    while (true) {
        draw_sim();
        int key = cv::waitKey(16);
        if (key == 27 || key == 'q') break;
    }

    cv::destroyAllWindows();
    return 0;
}

