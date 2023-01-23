/*Machine Learning Program for flower classification. 
Given train.data and test.data, the program will classify 
a flower given user-provided sepal length and width and petal 
length and width. This program takes 4 command line arguments: 
./a train.data test.data <option> 
User provided options: 
    1) "display" will display the test and train data 
    2) "stats" will calculate and display the mean and standard 
        deviation for all 4 characteristics of each flower from 
        the data set provided in argv[1]
    3) "accuracy" will display the test accuracy. If using the 
        provided train.data and test.data files, the accuracy 
        will be 1.00. (100% accurate) -this optin serves mainly as 
        a sanity check for the programmer)
    4) "classify" will prompt the user for flower characteristics
        that can be entered on the cmd line in the form 
        <num1> <num2> <num3> <num4> and will classify the type of 
        flower it best matches based on the nearest neighbor function*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int readData(char filename[], double sepal_lengths[], double sepal_widths[], double petal_lengths[], double petal_widths[], int labels[], int length){  
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Unable to open file %s", filename);
        return 1;
    }
    char str[20];
    for (int i = 0; i < length; i++) {
        fscanf(fp, "%lf %lf %lf %lf %s", &sepal_lengths[i], &sepal_widths[i], &petal_lengths[i], &petal_widths[i], str);
        if (strcmp(str, "Iris-setosa") == 0) {
            labels[i] = 0;
        }
        else if (strcmp(str, "Iris-versicolor") == 0) {
            labels[i] = 1;
        }
        else if (strcmp(str, "Iris-virginica") == 0) {
            labels[i] = 2;
        }
    }
    return 0;
}

void display(double sepal_lengths[], double sepal_widths[], double petal_lengths[], double petal_widths[], int labels[], int length) {
    for (int i = 0; i < length; i++) {
        printf("(%lf, %lf, %lf, %lf) => %d\n", sepal_lengths[i], sepal_widths[i], petal_lengths[i], petal_widths[i], labels[i]);
    }
}

double mean(double values[], int labels[], int filter, int length) {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (labels[i] == filter) {
            sum+= values[i];
            count++;
        }
    }
    return sum / count;
}

double stddev(double values[], int labels[], int filter, int length) {
    double sum = 0;
    int count = 0;
    double avg = mean(values, labels, filter, length);
    for (int i = 0; i < length; i++) {
        if (labels[i] == filter) {
            sum+= pow(values[i] - avg, 2);
            count++;
        }
    }
    return sqrt(sum / count);
}

void stats(double sepal_lengths[], double sepal_widths[], double petal_lengths[], double petal_widths[], int labels[], int length) {
    printf("  | Sepal length  | Sepal width   | Petal length  | Petal width\n");
    for (int i = 0; i < 3; i++) {
        printf("%d | %.2lf +/- %.2lf | %.2lf +/- %.2lf | %.2lf +/- %.2lf | %.2lf +/- %.2lf\n", i,
        mean(sepal_lengths, labels, i, length), stddev(sepal_lengths, labels, i, length) * 2, 
        mean(sepal_widths,  labels, i, length), stddev(sepal_widths,  labels, i, length) * 2,
        mean(petal_lengths, labels, i, length), stddev(petal_lengths, labels, i, length) * 2, 
        mean(petal_widths,  labels, i, length), stddev(petal_widths,  labels, i, length) * 2);
    }
}

double distance(double a1, double a2, double a3, double a4, double b1, double b2, double b3, double b4) {
    double dist = sqrt(pow((a1-b1), 2) + pow((a2-b2),2) + pow((a3-b3), 2) + pow((a4-b4), 2));
    return dist;
}

int nearestNeighbor(
    double sepal_lengths[], double sepal_widths[], double petal_lengths[], double petal_widths[], int labels[], int length,
    double sepal_length, double sepal_width, double petal_length, double petal_width) {
    int minIndex = 0;
    double min = distance(
        sepal_lengths[0], sepal_widths[0], petal_lengths[0], petal_widths[0],
        sepal_length,     sepal_width, petal_length, petal_width);
    for (int i = 1; i < length; i++) {
        double dist = distance(
            sepal_lengths[i], sepal_widths[i], petal_lengths[i], petal_widths[i],
            sepal_length, sepal_width, petal_length, petal_width);
        if (dist < min) {
            minIndex = i;
            min = dist;
        }
    }
    return labels[minIndex];
}

double accuracy(
    double sepal_lengths[], double sepal_widths[], double petal_lengths[], double petal_widths[],
    int labels[], int length, double sepal_lengths_test[], double sepal_widths_test[], double petal_lengths_test[],
    double petal_widths_test[], int labels_test[], int length_test) {
    int prediction;
    int correct = 0;
    for (int i = 0; i < length_test; i++) {
        prediction = nearestNeighbor(sepal_lengths, sepal_widths, petal_lengths, petal_widths, labels, length,
        sepal_lengths_test[i], sepal_widths_test[i], petal_lengths_test[i], petal_widths_test[i]);
        //printf("prediction: %i\tactual:%i\n", prediction, labels_test[i]);
        if (prediction== labels_test[i]) {
            correct++;
        }
    }   
//printf("correct: %d\n", correct);
    return (double)correct / length_test; 
}

int main(int argc, char* argv[]) {

    if (argc != 4) {
        printf("Usage: project4 TRAIN_FILE TEST_FILE OPTION");
        return 1;
    }

    double n1[120], n2[120], n3[120], n4[120];
    int labels1[120];
    double n5[30], n6[30], n7[30], n8[30];
    int labels2[30];
    double sepal_length, sepal_width, petal_length, petal_width;

    if (readData(argv[1], n1, n2, n3, n4, labels1, 120) == 1) {
       return 1;
   }
    if (readData(argv[2], n5, n6, n7, n8, labels2, 30) == 1) {
        return 1;
    }
    if (strcmp(argv[3], "display") == 0) {
        printf("Training data: \n");
        display(n1, n2, n3, n4, labels1, 120);
        printf("Testing data: \n");
        display(n5, n6, n7, n8, labels2, 30);   
    }
    else if (strcmp(argv[3], "stats") == 0) {
        stats(n1, n2, n3, n4, labels1, 120);
    }
    else if (strcmp(argv[3], "accuracy") == 0) {
        printf("Test accuracy: %.2lf", accuracy(n1, n2, n3, n4, labels1, 120, n5, n6, n7, n8, labels2, 30));
    }
    else if (strcmp(argv[3], "classify") == 0) {
        printf("Flower characteristics: ");
        scanf("%lf %lf %lf %lf", &sepal_length, &sepal_width, &petal_length, &petal_width);
        int closest = nearestNeighbor(n1, n2, n3, n4, labels1, 120, sepal_length, sepal_width, petal_length, petal_width);
        printf("\nPrediction: ");
        if (closest == 0) {
            printf("0 (Iris-setosa)\n");
        }
        else if (closest == 1) {
            printf("1 (Iris-versicolor)\n");
        }
        else if (closest == 2) {
            printf("2 (Iris-virginica)\n");
        }
    }
    else {
        printf("Unknown option");
        return 1;
    }
    return 0;
}