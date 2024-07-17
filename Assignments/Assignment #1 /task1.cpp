#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

#define K 3
//^^a preprocessor directive that defines the value of K as 3, 
//which is the number of clusters that we want to create
#define MAX_ITERATIONS 100
//^^a preprocessor directive that defines the value of MAX_ITERATIONS as 100,
//meaning that the algorithm will perform at most 100 iterations before terminating.

using namespace std;

//structure made in order to assess each point in the data
struct Point {
    double x, y;
    int cluster;
};

//function to find the euclidean distances
double euclidean_distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

//function to assign clusters in order to check the distances between the array and cluster
void assignClusters(Point array[], Point clusters[]) {
    for (int i = 0; i < K; i++) {
        clusters[i].x = 0;
        clusters[i].y = 0;
        clusters[i].cluster = i;
    }

    for (int i = 0; i < 400; i++) {
        double minDist = euclidean_distance(array[i], clusters[0]);
        int closestCluster = 0;

        for (int j = 1; j < K; j++) {
            double dist = euclidean_distance(array[i], clusters[j]);

            if (dist < minDist) {
                minDist = dist;
                closestCluster = j;
            }
        }

        array[i].cluster = closestCluster;
        clusters[closestCluster].x += array[i].x;
        clusters[closestCluster].y += array[i].y;
    }
}

//updating the clusters value once all the data points are added to each cluster
void updateClusters(Point array[],Point clusters[]) {
    for (int i = 0; i < K; i++) {
        int numPoints = 0;

        for (int j = 0; j < 400; j++) {
            if (clusters[i].cluster == array[j].cluster) {
                clusters[i].x += array[j].x;
                clusters[i].y += array[j].y;
                numPoints++;
            }
        }

        clusters[i].x /= numPoints;
        clusters[i].y /= numPoints;
    }
}

//originally the file of the data would take in a 4000 size array,
//but it was causing error, so i kept it at 400 for the array
int main() {
    Point array[400];
    Point clusters[K];

    //made in order to randomised numbers later
    srand(time(NULL));

    ifstream inputFile("C:/Users/DELL/Downloads/driver-data.csv");

    //in case the file doesnt open
    if (inputFile.fail()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string header;
    getline(inputFile, header);

    for (int i = 0; i < 400; i++) {
        char comma;
        inputFile >> array[i].x >> comma >> array[i].y;
    }

    inputFile.close();

    //randomising the clusters
    for (int i = 0; i < K; i++) {
        clusters[i].x = rand() % 100;
        clusters[i].y = rand() % 100;
        clusters[i].cluster = i;
    }

    for (int i = 0; i < MAX_ITERATIONS; i++) {
        assignClusters(array, clusters);
        updateClusters(array,clusters);
    }

    ofstream outputFile("output.csv");
    //in case the file doesnt open
    if (outputFile.fail()) {
        cout << "Error, File can't open." << endl;
        return 1;
    }
    //making the headers for "output.csv"
    outputFile << "mean_dist_day,mean_over_speed_perc,cluster" << endl;

    for (int i = 0; i < 400; i++) {
        outputFile << array[i].x << "," << array[i].y << "," << array[i].cluster << endl;
    }

    outputFile.close();
    return 0;
}
