#include "stats.h"

stats::stats(PNG& im) {
    /* Your code here!! */
    int width = im.width();
    int height = im.height();

    sumRed.resize(width, vector<long>(height, 0));
    sumGreen.resize(width, vector<long>(height, 0));
    sumBlue.resize(width, vector<long>(height, 0));
    sumsqRed.resize(width, vector<long>(height, 0));
    sumsqGreen.resize(width, vector<long>(height, 0));
    sumsqBlue.resize(width, vector<long>(height, 0));

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            long RSum = 0;
            long GSum = 0;
            long BSum = 0;
            long RSumSq = 0;
            long GSumSq = 0;
            long BSumSq = 0;
            for (int i = 0; i <= x; i++) {
                for (int j = 0; j <= y; j++) { 

            RGBAPixel* pixel = im.getPixel(i, j);
            RSum += pixel->r;
            GSum += pixel->g;
            BSum += pixel->b;
            RSumSq += pow(pixel->r, 2);
            GSumSq += pow(pixel->g, 2);
            BSumSq += pow(pixel->b, 2);

            sumRed[x][y] = RSum;
            sumGreen[x][y] = GSum;
            sumBlue[x][y] = BSum;
            sumsqRed[x][y] = RSumSq;
            sumsqGreen[x][y] = GSumSq;
            sumsqBlue[x][y] = BSumSq;

    }
}

    }
}


    
    
}

long stats::getSum(char channel, pair<int, int> ul, int dim) {
    /* Your code here!! */
    int x = ul.first;
    int y = ul.second;
    int squareLength = pow(2, dim);
    if (channel == 'r') {
    if (x == 0 && y == 0) {
        return sumRed[x + squareLength - 1][y + squareLength - 1];
    }

    else if (x!= 0 && y == 0) {
        return sumRed[x + squareLength - 1][y + squareLength - 1] - 
        sumRed[x - 1][y + squareLength - 1];

    }

    else if (x == 0 && y != 0) {
        return sumRed[x + squareLength - 1][y + squareLength - 1] - 
        sumRed[x + squareLength - 1][y - 1];
    }

    else {
        return sumRed[x + squareLength - 1][y + squareLength - 1] - 
        sumRed[x - 1][y + squareLength - 1] - 
        sumRed[x + squareLength - 1][y - 1] +
        sumRed[x - 1][y - 1];
    }
    }

    if (channel == 'g') {
    if (x == 0 && y == 0) {
        return sumGreen[x + squareLength - 1][y + squareLength - 1];
    }

    else if (x!= 0 && y == 0) {
        return sumGreen[x + squareLength - 1][y + squareLength - 1] - 
        sumGreen[x - 1][y + squareLength - 1];

    }

    else if (x == 0 && y != 0) {
        return sumGreen[x + squareLength - 1][y + squareLength - 1] - 
        sumGreen[x + squareLength - 1][y - 1];
    }

    else {
        return sumGreen[x + squareLength - 1][y + squareLength - 1] - 
        sumGreen[x - 1][y + squareLength - 1] - 
        sumGreen[x + squareLength - 1][y - 1] +
        sumGreen[x - 1][y - 1];
    }
    }

    if (channel == 'b') {
    if (x == 0 && y == 0) {
        return sumBlue[x + squareLength - 1][y + squareLength - 1];
    }

    else if (x!= 0 && y == 0) {
        return sumBlue[x + squareLength - 1][y + squareLength - 1] - 
        sumBlue[x - 1][y + squareLength - 1];

    }

    else if (x == 0 && y != 0) {
        return sumBlue[x + squareLength - 1][y + squareLength - 1] - 
        sumBlue[x + squareLength - 1][y - 1];
    }

    else {
        return sumBlue[x + squareLength - 1][y + squareLength - 1] - 
        sumBlue[x - 1][y + squareLength - 1] - 
        sumBlue[x + squareLength - 1][y - 1] +
        sumBlue[x - 1][y - 1];
    }
    }

    return 0;

}

long stats::getSumSq(char channel, pair<int, int> ul, int dim) {
    /* Your code here!! */
    int x = ul.first;
    int y = ul.second;
    int squareLength = pow(2, dim);
    if (channel == 'r') {
    if (x == 0 && y == 0) {
        return sumsqRed[x + squareLength - 1][y + squareLength - 1];
    }

    else if (x!= 0 && y == 0) {
        return sumsqRed[x + squareLength - 1][y + squareLength - 1] - 
        sumsqRed[x - 1][y + squareLength - 1];

    }

    else if (x == 0 && y != 0) {
        return sumsqRed[x + squareLength - 1][y + squareLength - 1] - 
        sumsqRed[x + squareLength - 1][y - 1];
    }

    else {
        return sumsqRed[x + squareLength - 1][y + squareLength - 1] - 
        sumsqRed[x - 1][y + squareLength - 1] - 
        sumsqRed[x + squareLength - 1][y - 1] +
        sumsqRed[x - 1][y - 1];
    }
    }

    if (channel == 'g') {
    if (x == 0 && y == 0) {
        return sumsqGreen[x + squareLength - 1][y + squareLength - 1];
    }

    else if (x!= 0 && y == 0) {
        return sumsqGreen[x + squareLength - 1][y + squareLength - 1] - 
        sumsqGreen[x - 1][y + squareLength - 1];

    }

    else if (x == 0 && y != 0) {
        return sumsqGreen[x + squareLength - 1][y + squareLength - 1] - 
        sumsqGreen[x + squareLength - 1][y - 1];
    }

    else {
        return sumsqGreen[x + squareLength - 1][y + squareLength - 1] - 
        sumsqGreen[x - 1][y + squareLength - 1] - 
        sumsqGreen[x + squareLength - 1][y - 1] +
        sumsqGreen[x - 1][y - 1];
    }
    }

    if (channel == 'b') {
    if (x == 0 && y == 0) {
        return sumsqBlue[x + squareLength - 1][y + squareLength - 1];
    }

    else if (x!= 0 && y == 0) {
        return sumsqBlue[x + squareLength - 1][y + squareLength - 1] - 
        sumsqBlue[x - 1][y + squareLength - 1];

    }

    else if (x == 0 && y != 0) {
        return sumsqBlue[x + squareLength - 1][y + squareLength - 1] - 
        sumsqBlue[x + squareLength - 1][y - 1];
    }

    else {
        return sumsqBlue[x + squareLength - 1][y + squareLength - 1] - 
        sumsqBlue[x - 1][y + squareLength - 1] - 
        sumsqBlue[x + squareLength - 1][y - 1] +
        sumsqBlue[x - 1][y - 1];
    }
    }

    return 0;

}

long stats::rectArea(int dim) {
    /* Your code here!! */
    return pow(2, dim) * pow(2, dim);
}

// given a rectangle, compute its sum of squared deviations from mean, over all color channels.
// see written specification for a description of this function.
double stats::getVar(pair<int, int> ul, int dim) {
    /* Your code here!! */
    long area = rectArea(dim);

    long sumR = getSum('r', ul, dim);
    long sumG = getSum('g', ul, dim);
    long sumB = getSum('b', ul, dim);

    long sumSqR = getSumSq('r', ul, dim);
    long sumSqG = getSumSq('g', ul, dim);
    long sumSqB = getSumSq('b', ul, dim);

    double varR = sumSqR - pow(sumR, 2)/area;
    double varG = sumSqG - pow(sumG, 2)/area;
    double varB = sumSqB - pow(sumB, 2)/area;
   
   return varR + varG + varB;
}

RGBAPixel stats::getAvg(pair<int, int> ul, int dim) {
    /* Your code here!! */

    long area = rectArea(dim);

    long sumR = getSum('r', ul, dim);
    long sumG = getSum('g', ul, dim);
    long sumB = getSum('b', ul, dim);

    int avgR = sumR / area;
    int avgG = sumG / area;
    int avgB = sumB / area;

    return RGBAPixel(avgR, avgG, avgB);
}

