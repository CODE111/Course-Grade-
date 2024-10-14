#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

double Midterm1Average(std::vector<int> midterm1List, int count) {
    int sum = 0;
    double averageMid1 = 0.0;
    for (int i = 0; i < midterm1List.size(); i++) {
        count++;
        sum += midterm1List.at(i);
    }
    averageMid1 = static_cast<double>(sum) / count;
    return averageMid1;
}

double Midterm2Average(std::vector<int> midTerm2List, int count) {
    int sum = 0;
    double averageMid2 = 0.0;
    for (int i = 0; i < midTerm2List.size(); i++) {
        count++;
        sum += midTerm2List.at(i);
    }
    averageMid2 = static_cast<double>(sum) / count;
    return averageMid2;
}

double FinalAverage(std::vector<int> finalList, int count) {
    double averageFinal = 0.0;
    int sum = 0;
    for (int i = 0; i < finalList.size(); i++) {
        count++;
        sum += finalList.at(i);
    }
    averageFinal = static_cast<double>(sum) / count;
    return averageFinal;
}


int main() {

    std::string firstName, lastName;
    int midterm1, midterm2, final, count = 0;

    std::vector<std::string> firstNameList;
    std::vector<std::string> lastNameList;
    std::vector<int> midterm1List;
    std::vector<int> midterm2List;
    std::vector<int> finalList;
    std::vector<char> letterGrade;

    std::ifstream inFSS1;
    std::ifstream inFSS2;
    std::ifstream inFSS3;
    double midTerm1Average = 0.0;
    double midTerm2Average = 0.0;
    double finalAverage = 0.0;
    std::string userInput = "StudentInfo.tsv";

    int totalGrade = 0;
    std::getline(std::cin, userInput);

    if (userInput == "StudentInfo.tsv") {
        inFSS1.open("StudentInfo.tsv");
        while (inFSS1 >> firstName >> lastName >> midterm1 >> midterm2 >> final) {
            firstNameList.push_back(firstName);
            lastNameList.push_back(lastName);
            midterm1List.push_back(midterm1);
            midterm2List.push_back(midterm2);
            finalList.push_back(final);
        }
        inFSS1.close();
    }
    else if (userInput == "StudentInfo1.tsv") {
        inFSS1.open("StudentInfo1.tsv");
        while (inFSS1 >> firstName >> lastName >> midterm1 >> midterm2 >> final) {
            firstNameList.push_back(firstName);
            lastNameList.push_back(lastName);
            midterm1List.push_back(midterm1);
            midterm2List.push_back(midterm2);
            finalList.push_back(final);
        }
        inFSS1.close();
    }
    else if (userInput == "StudentInfo2.tsv") {
        inFSS3.open("StudentInfo2.tsv");
        while (inFSS3 >> firstName >> lastName >> midterm1 >> midterm2 >> final) {
            firstNameList.push_back(firstName);
            lastNameList.push_back(lastName);
            midterm1List.push_back(midterm1);
            midterm2List.push_back(midterm2);
            finalList.push_back(final);
        }
        inFSS3.close();

    }


    std::ofstream outFSS;
    outFSS.open("report.txt");

    midTerm1Average = Midterm1Average(midterm1List, count);
    midTerm2Average = Midterm2Average(midterm2List, count);
    finalAverage = FinalAverage(finalList, count);
    for (int i = 0; i < midterm1List.size(); i++) {
        totalGrade = midterm1List[i] + midterm2List[i] + finalList[i];
        totalGrade /= 3;
        if (totalGrade >= 90) {
            letterGrade.push_back('A');
        }
        else if (totalGrade >= 80 && totalGrade < 90) {
            letterGrade.push_back('B');
        }
        else if (totalGrade >= 70 && totalGrade < 80) {
            letterGrade.push_back('C');
        }
        else if (totalGrade >= 60 && totalGrade < 70) {
            letterGrade.push_back('D');
        }
        else {
            letterGrade.push_back('F');
        }
    }

    for (int i = 0; i < midterm1List.size(); i++) {
        outFSS << firstNameList[i] << "\t" << lastNameList[i] << "\t" << midterm1List[i]
               << "\t" << midterm2List[i] << "\t" << finalList[i] << "\t" << letterGrade[i] << std::endl;
    }

    outFSS << std::endl;
    outFSS << std::fixed << std::setprecision(2) << "Averages: midterm1 "
           << midTerm1Average << ", midterm2 " << midTerm2Average << ", final " << finalAverage << std::endl;


    return 0;
}
